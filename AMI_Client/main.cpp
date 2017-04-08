#include <QApplication>
#include "AMI_Client.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    AMI_Client ami_client;
    ami_client.show();
    return app.exec();
}
