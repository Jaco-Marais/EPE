#include "gameserver.h"
#include <QDebug>
gameServer::gameServer(QObject *parent) :
    QTcpServer(parent)
{
 Port =1234;
 numberOfPlayers = 0;
}

void gameServer::startServer()
{

    if(this->listen(QHostAddress::Any,Port))
    {
        QString serverIP;
        QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();

        for (int x = 0; x < ipAddressList.size(); x++) {
            if (ipAddressList.at(x) != QHostAddress::LocalHost && ipAddressList.at(x).toIPv4Address())
            {
             serverIP = ipAddressList.at(x).toString();
             break;
            }
        }

        if (serverIP.isEmpty())
            serverIP = QHostAddress(QHostAddress::LocalHost).toString();

        emit sendGeneral("No",serverIP, QString::number(Port));
        qDebug() << "Listening... on " << Port;
    }
    else
    {
        qDebug() << errorString()<< "Could not start server on port " << Port;
    }


}

void gameServer::incomingConnection(qintptr socketDescriptor)
{
if( numberOfPlayers <4)
{
qDebug() << socketDescriptor << " Connecting...";

Players[numberOfPlayers].connection.setID(socketDescriptor);
// = new QThread();
Players[numberOfPlayers].connection.moveToThread(&threads[numberOfPlayers]);
threads[numberOfPlayers].start();

//connect(&threads[numberOfPlayers], SIGNAL(finished()), &Players[numberOfPlayers].connection, SLOT(deleteLater()));
connect(this, SIGNAL(operate()), &Players[numberOfPlayers].connection, SLOT(manageconnection()));
emit operate();


connect(&Players[numberOfPlayers].connection, SIGNAL(sendmessage(QString)),this, SLOT(receiveMessage(QString)));
emit sendtoupdatePlayers(true,"Player connected");
numberOfPlayers = numberOfPlayers + 1;
} // numberOfPlayers <4

}

void gameServer::receiveMessage(QString message)
{
    qDebug()<<"receive message :" << message;
emit sendtoupdateStatus(message);
}

 void gameServer::receiveRegistration(QString serverPort, QString name, QString IP, QString remoteP)
 {
  bool successlocal;
  bool successremote;
  int remoteport;
  int myport;

  myport = serverPort.toInt(&successlocal,10);
  if(successlocal == false)
  {
   qDebug() << "invalid  local port received from GUI";
  }
  Port = myport;
  startServer();

  remoteport = remoteP.toInt(&successremote,10);
   if(successremote == false)
   {
    qDebug() << "invalid  remote port received from GUI";
   }

    //make connection to central game server, at IP and port

 }

 //All I want for christmas is my two front teeth...



