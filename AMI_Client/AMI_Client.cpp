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
}

AMI_Client::~AMI_Client()
{}

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
		this->mainWindow->pushButtonDisconnect->setEnabled(true);
		
	}
}

void AMI_Client::disconnectFromServer(){
	this->client_socket->disconnectFromHost();
	this->mainWindow->pushButtonConnect->setEnabled(true);
	this->mainWindow->pushButtonDisconnect->setEnabled(false);
	this->mainWindow->lineEditIP->setEnabled(true);
	this->mainWindow->lineEditPort->setEnabled(true);
	this->mainWindow->lineEditNickname->setEnabled(true);
}

void AMI_Client::messageReciv(){
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
}



#include "AMI_Client.moc"
