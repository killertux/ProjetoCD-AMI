#include "AMI_Client.h"

AMI_Client::AMI_Client()
{
	//So, first let's take care of this boring interface stuff
	this->mainWindow = new Ui_MainWindow();
	this->mainWindow->setupUi(this);
	this->mainWindow->retranslateUi(this);
	
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
}

AMI_Client::~AMI_Client(){
	delete this->belmp;
	delete [] this->nicknames;
}

void AMI_Client::sendMessage(){
	std::string message = this->mainWindow->lineEditNewMessage->text().toUtf8().constData();
	std::cout << message << std::endl;
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
		this->mainWindow->pushButtonDisconnect->setEnabled(true);
		this->ourNickname = this->mainWindow->lineEditNickname->text().toUtf8().constData();
		packet = BELMP::new_request_connection(this->mainWindow->lineEditNickname->text().toLocal8Bit().data());
		this->client_socket->write((const char*)packet,256);
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
	this->mainWindow->plainTextEditMessages->appendPlainText("We disconnected from the server");
}

void AMI_Client::messageReciv(){
	QByteArray byteArray = this->client_socket->readAll();
	char *buffer = byteArray.data();
	_belmp_packet *packet=(_belmp_packet *)buffer;
	if(!BELMP::check_packet(buffer))
		return;
	
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
			this->mainWindow->plainTextEditMessages->appendPlainText("We are connected with the ID: "+QString().number(unsigned(this->ourId)));
			this->mainWindow->lineEditNewMessage->setEnabled(true);
			this->belmp->setStatus(STATUS_CONNECTED);
		} else {
			if(packet->function == F_CONNECTION_REJECTED_M_CLIENTS)
				this->mainWindow->plainTextEditMessages->appendPlainText("Server is full!");
			else if(packet->function == F_CONNECTION_REJECTED_NICKNAME)
				this->mainWindow->plainTextEditMessages->appendPlainText("Nickname already in use!");
			else if(packet->function == F_CONNECTION_REJECTED_NICKNAME)
				this->mainWindow->plainTextEditMessages->appendPlainText("Connection refused with a unknown error!");
			this->disconnectFromServer();
		}
	} else if(belmp->getStatus() == STATUS_CONNECTED){
		if(packet->function == F_NEW_CLIENT){
			char id=packet->data[0];
			char buffer[249];
			std::memcpy(buffer,packet->data+1,249);
			this->nicknames[id]=buffer;
			this->mainWindow->plainTextEditMessages->appendPlainText("New user connected with the nickname: "+QString(this->nicknames[id].c_str()));
		}
	}
}

void AMI_Client::showErrors(QAbstractSocket::SocketError socketError){
	switch(socketError){
		case QAbstractSocket::RemoteHostClosedError:
			this->mainWindow->plainTextEditMessages->appendPlainText("Connection closed by the host!");
			break;
		case QAbstractSocket::ConnectionRefusedError:
			this->mainWindow->plainTextEditMessages->appendPlainText("Connection refused!");
			break;
		case QAbstractSocket::HostNotFoundError:
			this->mainWindow->plainTextEditMessages->appendPlainText("Host not found!");
			break;
		default:
			this->mainWindow->plainTextEditMessages->appendPlainText("Some unknown connecton error!");
	}
	this->mainWindow->pushButtonConnect->setEnabled(true);
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	this->mainWindow->lineEditIP->setEnabled(true);
	this->mainWindow->lineEditPort->setEnabled(true);
	this->mainWindow->lineEditNickname->setEnabled(true);
	this->mainWindow->lineEditNewMessage->setEnabled(false);
}



#include "AMI_Client.moc"
