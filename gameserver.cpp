#include "gameserver.h"

gameServer::gameServer(QObject *parent) :
    QTcpServer(parent)
{

    numberOfPlayers = 0;
}

void gameServer::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
    }
}

void gameServer::incomingConnection(qintptr socketDescriptor)
{
if( numberOfPlayers <4)
{
qDebug() << socketDescriptor << " Connecting...";

Players[numberOfPlayers]->connection = new servercomm(socketDescriptor);
QThread *thread = new QThread();
Players[numberOfPlayers]->connection->moveToThread(thread);
thread->start();

connect(thread, SIGNAL(finished()), Players[numberOfPlayers]->connection, SLOT(deleteLater()));
connect(this, SIGNAL(operate()), Players[numberOfPlayers]->connection, SLOT(manageconnection()));
emit operate();

numberOfPlayers = numberOfPlayers + 1;
connect(Players[numberOfPlayers]->connection, SIGNAL(sendmessage(QString)),this, SLOT(receiveMessage(QString)));
emit sendtoupdatePlayers(true,"Player connected");
emit sendGeneral("Yes", "136.76.bla.blah", "123");

} // numberOfPlayers <4
}

void gameServer::receiveMessage(QString message)
{
emit sendtoupdateStatus(message);
}

 void gameServer::receiveRegistration(QString name, QString IP, QString port)
 {
    //make connection to central game server, at IP and port

 }



