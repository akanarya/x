#include <QtGui/QApplication>
#include "mainwindow.h"
b1 .2 .3x
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
