#ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class connectionThread : public QThread
{
    Q_OBJECT
public:
    explicit connectionThread(int ID, QObject *parent = 0);
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
    void sendmessage(QString);
public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    int socketDescriptor;
};


#endif // CONNECTIONTHREAD_H


