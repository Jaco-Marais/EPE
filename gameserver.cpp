#include "gameserver.h"
#include <QDebug>
gameServer::gameServer(QObject *parent) :
    QTcpServer(parent)
{
 Port =1234;
 numberOfPlayers = 0;
}

bool gameServer::startServer()
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
        return true;
    }
    else
    {
        qDebug() << errorString()<< "Could not start server on port " << Port;
          return false;
    }


}

void gameServer::incomingConnection(qintptr socketDescriptor)
{
    try
    {
if( numberOfPlayers <4)
{
qDebug() << socketDescriptor << " Connecting...";

Players[numberOfPlayers].connection.setID(socketDescriptor);
Players[numberOfPlayers].connection.moveToThread(&threads[numberOfPlayers]);
threads[numberOfPlayers].start();

connect(&threads[numberOfPlayers], SIGNAL(finished()), &Players[numberOfPlayers].connection, SLOT(deleteLater()));
connect(this, SIGNAL(operate()), &Players[numberOfPlayers].connection, SLOT(manageconnection()),Qt::QueuedConnection);
emit operate();
bool a;
//a= QMetaObject::invokeMethod(&Players[numberOfPlayers].connection, "manageconnection", Qt::AutoConnection);

connect(&Players[numberOfPlayers].connection, SIGNAL(sendmessage(QString)),this, SLOT(receiveMessage(QString)),Qt::QueuedConnection);
emit sendtoupdatePlayers(true,"Player connected");
numberOfPlayers = numberOfPlayers + 1;
} // numberOfPlayers <4
    }
    catch (...)
    {
     qDebug()<<errorString();

    }
}

void gameServer::receiveMessage(QString message)
{
    qDebug()<<"receive message :" << message;
emit sendtoupdateStatus(message);
}

 void gameServer::receiveRegistration(QString serverPort, QString name, QString serverPass,QString remoteIP, QString remoteP)
 {
  bool successlocal;
  bool successremote;
  bool successfulstart = false;
  int remoteport;
  int myport;
  bool allgood = true;

  myport = serverPort.toInt(&successlocal,10);
  if(successlocal == false)
  {
      allgood = false;
   qDebug() << "invalid  local port received from GUI";
  }

  remoteport = remoteP.toInt(&successremote,10);
   if(successremote == false)
   {
    allgood = false;
    qDebug() << "invalid  remote port received from GUI";
   }

   if(serverPass.length() == 0)
   {
   allgood = false;
   qDebug()<< "Blank server password specified";
   }

   if(name.length() == 0)
   {
   allgood = false;
   qDebug()<< "Blank server name specified";
   }


  if(allgood)
  {
  successfulstart =  startServer();
  }

  if(successfulstart == false)
  {
   allgood = false;
  }

   if(allgood)
    {
   password = serverPass;
   Port = myport;
     qDebug() <<"contacting remote server";
    //make connection to central game server, at IP and port
    }
     else
   {
    qDebug()<< "invalid parameters";
   }

 }


