#ifndef SERVERCOMM_H
#define SERVERCOMM_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
class servercomm : public QObject
{
    Q_OBJECT
public:
    explicit servercomm(QObject *parent = 0);
    void setID(int);
signals:
    void error(QTcpSocket::SocketError socketerror);
        void sendmessage(QString);
public slots:
    void manageconnection();
    void ReadyRead();
    void disconnected();
private:
    int socketDescriptor;
    QTcpSocket *socket;

};

#endif // SERVERCOMM_H
#ifndef SERVERCOMM_H
#define SERVERCOMM_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
class servercomm : public QObject
{
    Q_OBJECT
public:
    explicit servercomm(QObject *parent = 0);
    void setID(int);
signals:
    void error(QTcpSocket::SocketError socketerror);
        void sendmessage(QString);
public slots:
    void manageconnection();
    void ReadyRead();
    void disconnected();
private:
    int socketDescriptor;
    QTcpSocket *socket;

};

#endif // SERVERCOMM_H
