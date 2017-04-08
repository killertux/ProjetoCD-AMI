/********************************************************************************
** Form generated from reading UI file 'Design.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelMessageLog;
    QPlainTextEdit *plainTextEditMessages;
    QLabel *labelTitle;
    QLabel *labelTypeMessage;
    QLineEdit *lineEditNewMessage;
    QLabel *labelServerInfo;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QLabel *labelNickname;
    QLineEdit *lineEditNickname;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 650);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelMessageLog = new QLabel(centralwidget);
        labelMessageLog->setObjectName(QString::fromUtf8("labelMessageLog"));
        labelMessageLog->setGeometry(QRect(10, 50, 131, 16));
        plainTextEditMessages = new QPlainTextEdit(centralwidget);
        plainTextEditMessages->setObjectName(QString::fromUtf8("plainTextEditMessages"));
        plainTextEditMessages->setGeometry(QRect(10, 70, 431, 261));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setWeight(50);
        plainTextEditMessages->setFont(font1);
        plainTextEditMessages->setReadOnly(true);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(160, 10, 161, 21));
        QFont font2;
        font2.setPointSize(18);
        labelTitle->setFont(font2);
        labelTypeMessage = new QLabel(centralwidget);
        labelTypeMessage->setObjectName(QString::fromUtf8("labelTypeMessage"));
        labelTypeMessage->setGeometry(QRect(10, 330, 111, 16));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        labelTypeMessage->setFont(font3);
        lineEditNewMessage = new QLineEdit(centralwidget);
        lineEditNewMessage->setObjectName(QString::fromUtf8("lineEditNewMessage"));
        lineEditNewMessage->setGeometry(QRect(10, 350, 431, 20));
        lineEditNewMessage->setFont(font1);
        labelServerInfo = new QLabel(centralwidget);
        labelServerInfo->setObjectName(QString::fromUtf8("labelServerInfo"));
        labelServerInfo->setGeometry(QRect(160, 390, 111, 16));
        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setGeometry(QRect(70, 430, 21, 16));
        labelIP->setFont(font3);
        lineEditIP = new QLineEdit(centralwidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(90, 430, 101, 20));
        lineEditIP->setFont(font1);
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(260, 430, 51, 16));
        labelPort->setFont(font3);
        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(300, 430, 61, 20));
        lineEditPort->setFont(font1);
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(280, 540, 101, 23));
        pushButtonConnect->setFont(font3);
        pushButtonDisconnect = new QPushButton(centralwidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
        pushButtonDisconnect->setGeometry(QRect(60, 540, 101, 23));
        pushButtonDisconnect->setFont(font3);
        labelNickname = new QLabel(centralwidget);
        labelNickname->setObjectName(QString::fromUtf8("labelNickname"));
        labelNickname->setGeometry(QRect(100, 490, 91, 16));
        labelNickname->setFont(font3);
        lineEditNickname = new QLineEdit(centralwidget);
        lineEditNickname->setObjectName(QString::fromUtf8("lineEditNickname"));
        lineEditNickname->setGeometry(QRect(180, 490, 101, 20));
        lineEditNickname->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        labelMessageLog->setText(QApplication::translate("MainWindow", "Messages log:", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("MainWindow", "AMI_Client", 0, QApplication::UnicodeUTF8));
        labelTypeMessage->setText(QApplication::translate("MainWindow", "Type message:", 0, QApplication::UnicodeUTF8));
        labelServerInfo->setText(QApplication::translate("MainWindow", "Server Info:", 0, QApplication::UnicodeUTF8));
        labelIP->setText(QApplication::translate("MainWindow", "IP:", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        pushButtonDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        labelNickname->setText(QApplication::translate("MainWindow", "Nickname:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWS_H
