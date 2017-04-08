#ifndef AMI_Client_H
#define AMI_Client_H


#include <QMainWindow>
#include <QTcpSocket>
#include <string>
#include <iostream>		//Remeber to remove this
#include "MainWindows.hpp"

class AMI_Client : public QMainWindow
{
private:
    Q_OBJECT
    Ui_MainWindow *mainWindow;
	QTcpSocket *client_socket;

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
