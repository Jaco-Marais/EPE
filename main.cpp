#include "gmwindow.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gmWindow w;
    w.show();

    return a.exec();
}
