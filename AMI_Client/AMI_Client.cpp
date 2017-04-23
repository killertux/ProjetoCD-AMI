#include "AMI_Client.h"

AMI_Client::AMI_Client()
{
	//So, first let's take care of this boring interface stuff
	this->mainWindow = new Ui_MainWindow();
	this->mainWindow->setupUi(this);
	this->mainWindow->retranslateUi(this);
	this->mainWindow->textEditMessages->setDisabled(true);
	
	//Can't send text while we are not connected to a server
	this->mainWindow->lineEditNewMessage->setDisabled(true);
	this->mainWindow->lineEditNewMessage->setText("Not connected to a server!\n");
	
	//Desactivate disconnect button
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	
	//Creating the socket
	this->client_socket=new QTcpSocket(this);
	
	//Assign signals;
	this->connect(this->mainWindow->lineEditNewMessage,SIGNAL(returnPressed()),this,SLOT(sendMessage()));
	this->connect(this->mainWindow->pushButtonConnect,SIGNAL(clicked()),this,SLOT(connectToServer()));
	this->connect(this->mainWindow->pushButtonDisconnect,SIGNAL(clicked()),this,SLOT(disconnectFromServer()));
	this->connect(this->client_socket,SIGNAL(readyRead()),this,SLOT(messageReciv()));
	this->connect(this->client_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(showErrors(QAbstractSocket::SocketError)));
	
	//Alocating belmp;
	this->belmp= new BELMP(true);
	this->ami=NULL;
}

AMI_Client::~AMI_Client(){
	delete this->belmp;
	delete [] this->nicknames;
}

void AMI_Client::sendMessage(){
	std::string data = this->mainWindow->lineEditNewMessage->text().toUtf8().constData();
	std::istringstream iss(data);
	std::string cmd;
	iss>>cmd;
	
	this->mainWindow->lineEditNewMessage->setText("");
	if(cmd == "send"){
		std::string message= data.erase(0,cmd.size()+1);
		_belmp_packet *packet;
		packet = BELMP::new_message(this->ourId,(char)R_BROADCAST,(char *)message.c_str());
		this->client_socket->write((const char *)this->ami->toAMI((char*)packet,PACKET_SIZE),PACKET_SIZE*2);
		delete packet;
		message= "Sent: "+message;
		this->info(message.c_str());
	} else if(cmd == "private"){
		std::string person;
		std::string message;
		iss>>person;
		message = data.erase(0,cmd.size()+person.size()+2);
		for(int i=0;i<this->server_max_clients;i++)
			if(this->nicknames[i]==person){
				_belmp_packet *packet;
				packet = BELMP::new_message(this->ourId,(char)i,(char *)message.c_str());
				this->client_socket->write((const char *)this->ami->toAMI((char*)packet,PACKET_SIZE),PACKET_SIZE*2);
				delete packet;
				message= "Sent["+this->nicknames[i]+"]: "+message;
				this->info(message.c_str());
				return;
			}
		this->warning("User not found!");
		
	} else if(cmd == "online"){
		this->info("Online users:");
		for(int i=0;i<this->server_max_clients;i++)
			if(this->nicknames[i]!="")
				this->info(this->nicknames[i].c_str());
	
	} else if(cmd == "help"){
		this->info("Commands :");
		this->info("send [message]  -  Broadcast the message");
		this->info("private [user] [message]  -  Send a private message");
		this->info("online  -  Show connected users");
	} else 
			this->warning(QString(cmd.c_str())+ " not a command!");
}

void AMI_Client::connectToServer(){
	//We should desactivate any button for now.
	this->mainWindow->pushButtonConnect->setEnabled(false);
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	this->mainWindow->lineEditIP->setEnabled(false);
	this->mainWindow->lineEditPort->setEnabled(false);
	this->mainWindow->lineEditNickname->setEnabled(false);
	
	this->client_socket->connectToHost(this->mainWindow->lineEditIP->text(),this->mainWindow->lineEditPort->text().toInt());
	if(this->client_socket->waitForConnected(5000)){
		_belmp_packet *packet;
		std::string nickname = this->mainWindow->lineEditNickname->text().toLocal8Bit().data();
		std::replace(nickname.begin(),nickname.end(),' ','_');	//No space alowed in the nickname
		if(this->ami!=NULL)
			delete this->ami;
		this->ami= new AMI;
		this->mainWindow->pushButtonDisconnect->setEnabled(true);
		this->ourNickname = this->mainWindow->lineEditNickname->text().toUtf8().constData();
		packet = BELMP::new_request_connection((char*)nickname.c_str());
		this->client_socket->write((const char*)this->ami->toAMI((char*)packet,PACKET_SIZE),PACKET_SIZE*2);
		this->belmp->setStatus(STATUS_CONNECTION_REQUESTED);
		delete packet;
	}
}

void AMI_Client::disconnectFromServer(){
	this->client_socket->disconnectFromHost();
	this->mainWindow->pushButtonConnect->setEnabled(true);
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	this->mainWindow->lineEditIP->setEnabled(true);
	this->mainWindow->lineEditPort->setEnabled(true);
	this->mainWindow->lineEditNickname->setEnabled(true);
	this->mainWindow->lineEditNewMessage->setEnabled(false);
	this->info("We disconnected from the server");
	this->mainWindow->lineEditNewMessage->setText("Not connected to a server!\n");
	this->belmp->setStatus(STATUS_DISCONNECTED);
}

void AMI_Client::messageReciv(){
	while(this->client_socket->bytesAvailable() >= PACKET_SIZE*2){
		QByteArray byteArray = this->client_socket->read(PACKET_SIZE*2);
		char *buffer = byteArray.data();
		_belmp_packet *packet=(_belmp_packet *)this->ami->fromAMI(buffer,PACKET_SIZE*2);
		if(!BELMP::check_packet(packet))
			continue;
		
		if(belmp->getStatus()==STATUS_CONNECTION_REQUESTED){
			if(packet->function == F_CONNECTION_ACCEPTED){
				//Yay, we are in boys!!
				this->ourId=packet->data[0];
				this->server_max_clients=packet->data[1];
				this->nicknames = new std::string[this->server_max_clients];
				//std::cout << this->ourId<<std::endl;
				//We should put "" in all nicknames for now.
				for(int i=0;i<this->server_max_clients;i++)
					if(i!=this->ourId)
						this->nicknames[i]="";
					else
						this->nicknames[i]=this->ourNickname;
				this->info("We are connected with the ID: "+QString().number(unsigned(this->ourId)));
				this->mainWindow->lineEditNewMessage->setEnabled(true);
				this->mainWindow->lineEditNewMessage->setText("");
				this->belmp->setStatus(STATUS_CONNECTED);
			} else {
				if(packet->function == F_CONNECTION_REJECTED_M_CLIENTS)
					this->warning("Server is full!");
				else if(packet->function == F_CONNECTION_REJECTED_NICKNAME)
					this->warning("Nickname already in use!");
				else if(packet->function == F_CONNECTION_REJECTED_NICKNAME)
					this->warning("Connection refused with a unknown error!");
				this->disconnectFromServer();
			}
		} else if(belmp->getStatus() == STATUS_CONNECTED){
			if(packet->function == F_NEW_CLIENT){
				//We have company
				char id=packet->data[0];
				char buffer[249];
				std::memcpy(buffer,packet->data+1,249);
				this->nicknames[id]=buffer;
				this->info("New user connected with the nickname: "+QString(this->nicknames[id].c_str()));
			} else if(packet->function == F_CLIENT_DISCONNECT){
				//That TRAITOR!!! Kill him!!! He is dead to us
				char id=packet->data[0];
				this->info("The user "+QString(this->nicknames[id].c_str())+ " disconnected!");
				this->nicknames[id]="";
			} else if(packet->function == F_ERROR_MESSAGE_RECIEVER){
				//My friend is dead :'(
				this->warning("We tried to contact a ghost!");
			} else if(packet->function == F_ERROR_MESSAGE_SENDER){
				//Ops. I was caught!!
				this->warning("Invalid sender ID");
			} else if(packet->function == F_NEW_MESSAGE){
				std::string message = packet->data+2;
				char from = packet->data[0];
				char to = packet->data[1];
				if(to == (char)R_BROADCAST){
					message = this->nicknames[from] + std::string(" [Broadcast]: ") + message;
					this->message(message.c_str());
				} else {
					message = this->nicknames[from] + std::string(": ") + message;
					this->privateMessage(message.c_str());
				}
			}
		}
	}
}

void AMI_Client::showErrors(QAbstractSocket::SocketError socketError){
	switch(socketError){
		case QAbstractSocket::RemoteHostClosedError:
			this->warning("Connection closed by the host!");
			break;
		case QAbstractSocket::ConnectionRefusedError:
			this->warning("Connection refused!");
			break;
		case QAbstractSocket::HostNotFoundError:
			this->warning("Host not found!");
			break;
		default:
			this->warning("Some unknown connecton error!");
	}
	this->mainWindow->pushButtonConnect->setEnabled(true);
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	this->mainWindow->lineEditIP->setEnabled(true);
	this->mainWindow->lineEditPort->setEnabled(true);
	this->mainWindow->lineEditNickname->setEnabled(true);
	this->mainWindow->lineEditNewMessage->setEnabled(false);
	this->mainWindow->lineEditNewMessage->setText("Not connected to a server!\n");
	this->belmp->setStatus(STATUS_DISCONNECTED);
}

void AMI_Client::info(QString text){
	this->mainWindow->textEditMessages->setTextColor(QColor(100,100,100));
	this->mainWindow->textEditMessages->append(text);
	this->mainWindow->textEditMessages->setTextColor(QColor(0,0,0));
}
void AMI_Client::warning(QString text){
	this->mainWindow->textEditMessages->setTextColor(QColor(177,0,0));
	this->mainWindow->textEditMessages->append(text);
	this->mainWindow->textEditMessages->setTextColor(QColor(0,0,0));
}

void AMI_Client::message(QString text){
	this->mainWindow->textEditMessages->append(text);
}

void AMI_Client::privateMessage(QString text){
	this->mainWindow->textEditMessages->setTextColor(QColor(0,0,120));
	this->mainWindow->textEditMessages->append(text);
	this->mainWindow->textEditMessages->setTextColor(QColor(0,0,0));
}

#include "AMI_Client.moc"
