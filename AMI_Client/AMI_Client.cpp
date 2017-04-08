#include "AMI_Client.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

AMI_Client::AMI_Client()
{
    QLabel* label = new QLabel( this );
    label->setText( "Hello World!" );
    setCentralWidget( label );
    QAction* action = new QAction(this);
    action->setText( "Quit" );
    connect(action, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( action );
}

AMI_Client::~AMI_Client()
{}

#include "AMI_Client.moc"
