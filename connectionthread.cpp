#include "connectionthread.h"

connectionThread::connectionThread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}


void connectionThread::run()
{
    //thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";

    exec();
}


void connectionThread::readyRead()
{
    QByteArray Data = socket->readAll();

     qDebug() << socketDescriptor << " Data in: " << Data;
    emit sendmessage(Data);
     socket->write(Data);
}

void connectionThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    exit(0);
}
