#include <QCoreApplication>

#include "network/udpcontroller.h"
#include "fmsconfig.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FmsConfig::Instance(":/config_processer.ini");
    UDPController::InitSocket(FmsConfig::Instance()->UdpSendingPort,
                                  FmsConfig::Instance()->UdpReceivePort, true);
    qDebug() << FmsConfig::Instance()->UdpSendingPort << ", " << FmsConfig::Instance()->UdpReceivePort;

    return a.exec();
}
