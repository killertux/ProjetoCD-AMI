/********************************************************************************
** Form generated from reading UI file 'Design.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QLabel *labelMessageLog;
    QTextEdit *textEditMessages;
    QLabel *labelTypeMessage;
    QLineEdit *lineEditNewMessage;
    QLabel *labelServerInfo;
    QGridLayout *gridLayout;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QLabel *labelIp;
    QLineEdit *lineEditIP;
    QSpacerItem *horizontalSpacer;
    QLabel *labelNickname;
    QLineEdit *lineEditNickname;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonDisconnect;
    QPushButton *pushButtonConnect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(556, 549);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        labelMessageLog = new QLabel(centralwidget);
        labelMessageLog->setObjectName(QString::fromUtf8("labelMessageLog"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelMessageLog->setFont(font1);

        verticalLayout->addWidget(labelMessageLog);

        textEditMessages = new QTextEdit(centralwidget);
        textEditMessages->setObjectName(QString::fromUtf8("textEditMessages"));
        QFont font2;
        font2.setPointSize(12);
        textEditMessages->setFont(font2);

        verticalLayout->addWidget(textEditMessages);

        labelTypeMessage = new QLabel(centralwidget);
        labelTypeMessage->setObjectName(QString::fromUtf8("labelTypeMessage"));
        QFont font3;
        font3.setPointSize(14);
        labelTypeMessage->setFont(font3);

        verticalLayout->addWidget(labelTypeMessage);

        lineEditNewMessage = new QLineEdit(centralwidget);
        lineEditNewMessage->setObjectName(QString::fromUtf8("lineEditNewMessage"));
        lineEditNewMessage->setFont(font2);

        verticalLayout->addWidget(lineEditNewMessage);

        labelServerInfo = new QLabel(centralwidget);
        labelServerInfo->setObjectName(QString::fromUtf8("labelServerInfo"));
        labelServerInfo->setFont(font1);
        labelServerInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelServerInfo);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy);
        labelPort->setFont(font3);

        gridLayout->addWidget(labelPort, 3, 3, 1, 1);

        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPort->sizePolicy().hasHeightForWidth());
        lineEditPort->setSizePolicy(sizePolicy1);
        lineEditPort->setFont(font2);

        gridLayout->addWidget(lineEditPort, 3, 4, 1, 1);

        labelIp = new QLabel(centralwidget);
        labelIp->setObjectName(QString::fromUtf8("labelIp"));
        sizePolicy.setHeightForWidth(labelIp->sizePolicy().hasHeightForWidth());
        labelIp->setSizePolicy(sizePolicy);
        labelIp->setFont(font3);

        gridLayout->addWidget(labelIp, 3, 0, 1, 1);

        lineEditIP = new QLineEdit(centralwidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        sizePolicy1.setHeightForWidth(lineEditIP->sizePolicy().hasHeightForWidth());
        lineEditIP->setSizePolicy(sizePolicy1);
        lineEditIP->setFont(font2);

        gridLayout->addWidget(lineEditIP, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        labelNickname = new QLabel(centralwidget);
        labelNickname->setObjectName(QString::fromUtf8("labelNickname"));
        labelNickname->setFont(font3);

        gridLayout->addWidget(labelNickname, 4, 0, 1, 1);

        lineEditNickname = new QLineEdit(centralwidget);
        lineEditNickname->setObjectName(QString::fromUtf8("lineEditNickname"));
        lineEditNickname->setFont(font2);

        gridLayout->addWidget(lineEditNickname, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonDisconnect = new QPushButton(centralwidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonDisconnect->sizePolicy().hasHeightForWidth());
        pushButtonDisconnect->setSizePolicy(sizePolicy2);
        pushButtonDisconnect->setFont(font3);

        horizontalLayout->addWidget(pushButtonDisconnect);

        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        sizePolicy2.setHeightForWidth(pushButtonConnect->sizePolicy().hasHeightForWidth());
        pushButtonConnect->setSizePolicy(sizePolicy2);
        pushButtonConnect->setFont(font3);

        horizontalLayout->addWidget(pushButtonConnect);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 556, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(textEditMessages, lineEditNewMessage);
        QWidget::setTabOrder(lineEditNewMessage, lineEditIP);
        QWidget::setTabOrder(lineEditIP, lineEditPort);
        QWidget::setTabOrder(lineEditPort, lineEditNickname);
        QWidget::setTabOrder(lineEditNickname, pushButtonConnect);
        QWidget::setTabOrder(pushButtonConnect, pushButtonDisconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AMI_Client", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("MainWindow", "AMI_Client", 0, QApplication::UnicodeUTF8));
        labelMessageLog->setText(QApplication::translate("MainWindow", "Messages log:", 0, QApplication::UnicodeUTF8));
        labelTypeMessage->setText(QApplication::translate("MainWindow", "Type message:", 0, QApplication::UnicodeUTF8));
        labelServerInfo->setText(QApplication::translate("MainWindow", "Server Info:", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        labelIp->setText(QApplication::translate("MainWindow", "Ip:", 0, QApplication::UnicodeUTF8));
        labelNickname->setText(QApplication::translate("MainWindow", "Nickname:", 0, QApplication::UnicodeUTF8));
        pushButtonDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWS_H
