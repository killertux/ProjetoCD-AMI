#ifndef AMI_Client_H
#define AMI_Client_H


#include <QMainWindow>
#include <QTcpSocket>
#include <string>
#include <iostream>		//Remeber to remove this
#include "MainWindows.hpp"
#include "../AMI_Server/BELMP.hpp"
#include "../AMI_Server/AMI.hpp"
#include <sstream>
#include "itoa.hpp"


class AMI_Client : public QMainWindow
{
private:
    Q_OBJECT
    Ui_MainWindow *mainWindow;
	QTcpSocket *client_socket;
	BELMP *belmp;
	AMI *ami;
	
	bool debug;
	char ourId;
	std::string ourNickname;
	char server_max_clients;
	std::string *nicknames;
	void warning(QString text);
	void info(QString text);
	void message(QString text);
	void privateMessage(QString text);
public:
    AMI_Client();
    virtual ~AMI_Client();
public slots:
	void sendMessage();
	void connectToServer();
	void disconnectFromServer();
	void messageReciv();
	void showErrors(QAbstractSocket::SocketError socketError);
};

#endif // AMI_Client_H
