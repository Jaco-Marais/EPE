#include "gmwindow.h"
#include "ui_gmwindow.h"
#include <QDebug>
gmWindow::gmWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gmWindow)
{
    ui->setupUi(this);
    gm.setMaxPendingConnections(4);



connect(&gm, SIGNAL(sendtoupdatePlayers(bool,QString)),this, SLOT(updateConnectedPlayers(bool, QString)));
connect(&gm, SIGNAL(sendtoupdateStatus(QString)),this, SLOT(updateStatus(QString)));
connect(this, SIGNAL(Registration(QString, QString, QString, QString)),&gm, SLOT(receiveRegistration(QString,QString,QString, QString)));
connect(&gm, SIGNAL(sendGeneral(QString, QString, QString)),this, SLOT(updateGeneral(QString,QString, QString)));
}

   void gmWindow::updateConnectedPlayers(bool connected, QString playerName)
   {
       if(connected)
    ui->listPlayers->addItem(playerName);
       else
       {

       ui->listPlayers->takeItem(0);
       }
   }


 void gmWindow::updateStatus(QString status)
 {


       qDebug()<<"update status with :" << status;
      ui->listStatus->addItem(status);

 }

void gmWindow::updateGeneral(QString status, QString IP, QString port)
{
    ui->regStatus->setText( status );
    ui->serverIP->setText( IP );
}

gmWindow::~gmWindow()
{
    delete ui;
}


void gmWindow::on_regButton_clicked()
{
    emit Registration( ui->serverPort->text(),ui->serverName->displayText(), ui->remoteServerIP->text(), ui->remoteServerPort->displayText() );

}
