#include "mainwindow.h"

#include "fmsapi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FmsManager::Instance()->initialize();

    MainWindow w;
    w.show();
    return a.exec();
}
