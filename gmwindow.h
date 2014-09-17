#ifndef GMWINDOW_H
#define GMWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "gameserver.h"
namespace Ui {
class gmWindow;
}

class gmWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gmWindow(QWidget *parent = 0);
    ~gmWindow();

private:
    Ui::gmWindow *ui;
        gameServer gm;

public slots:
    void updateConnectedPlayers(bool,QString);
    void updateStatus(QString);
    void updateGeneral(QString, QString, QString);

private slots:
    void on_regButton_clicked();

signals:
        void Registration(QString,QString, QString, QString);

};

#endif // GMWINDOW_H
