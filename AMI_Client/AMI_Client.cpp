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
	
	//Assign signals;
	this->connect(this->mainWindow->lineEditNewMessage,SIGNAL(returnPressed()),this,SLOT(sendMessage()));
	this->connect(this->mainWindow->pushButtonConnect,SIGNAL(clicked()),this,SLOT(connectToServer()));
	this->connect(this->mainWindow->pushButtonDisconnect,SIGNAL(clicked()),this,SLOT(disconnectFromServer()));
	
}

AMI_Client::~AMI_Client()
{}

void AMI_Client::sendMessage(){
	std::string message = this->mainWindow->lineEditNewMessage->text().toUtf8().constData();
	std::cout << message << std::endl;
}

void AMI_Client::connectToServer(){
}

void AMI_Client::disconnectFromServer(){
}




#include "AMI_Client.moc"
