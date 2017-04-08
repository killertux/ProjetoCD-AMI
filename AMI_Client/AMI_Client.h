#ifndef AMI_Client_H
#define AMI_Client_H


#include <QMainWindow>
#include <string>
#include <iostream>		//Remeber to remove this
#include "MainWindows.hpp"

class AMI_Client : public QMainWindow
{
    Q_OBJECT
    Ui_MainWindow *mainWindow;

public:
    AMI_Client();
    virtual ~AMI_Client();
public slots:
	void sendMessage();
	void connectToServer();
	void disconnectFromServer();
};

#endif // AMI_Client_H
