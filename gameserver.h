#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QTcpServer>
#include "connectionthread.h"
#include "servercomm.h"
#include <QNetworkInterface>
#include <QDebug>
struct playerStruct{
 QString screenName;
 servercomm connection;

};

class gameServer : public QTcpServer
{
        Q_OBJECT
public:
    explicit gameServer(QObject *parent = 0);
    bool startServer();

private:
    int numberOfPlayers;
    int Port;
    QString password;
    playerStruct Players[4];
    QThread threads[4];
 signals:
  void sendtoupdatePlayers(bool,QString);
  void sendtoupdateStatus(QString);
  void operate();
  void sendGeneral(QString, QString, QString);
public slots:
 void receiveMessage(QString);
 void receiveRegistration(QString,QString, QString, QString, QString);
protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // GAMESERVER_H
