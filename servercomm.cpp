#include "servercomm.h"
#include <QDebug>
servercomm::servercomm(QObject *parent) :
    QObject(parent)
{

}

void servercomm::setID(int ID)
{
     this->socketDescriptor = ID;
}

void servercomm::manageconnection()
{
    //thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(ReadyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";

    //exec();
}



void servercomm::ReadyRead()
{
    QByteArray Data = socket->readAll();

     qDebug() << socketDescriptor << " Data in: " << Data;
    emit sendmessage(Data);
     socket->write(Data);
}

void servercomm::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    exit(0);
}
