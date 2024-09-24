#ifndef FMSCONFIG_H
#define FMSCONFIG_H

#include "FmsApi_global.h"
#include "configlib.h"

class FMSAPI_EXPORT FmsConfig : public ConfigLib
{
public:
    FmsConfig(const QString& fileName = "config.ini");
    static FmsConfig* Instance(const QString& fileName = "config.ini");
    void loadConfigure();
    static void LoadConfigure();
    void saveConfigure();
    static void SaveConfigure();
private:
    static FmsConfig* m_FmsConfig;
public:
    static const QString NETWORK_GROUP;
    static const QString UDP_SENDING_PORT;
    static const QString UDP_SENDING_ADDRESS;
    static const QString UDP_RECEIVE_PORT;

public:
    quint16 UdpSendingPort;
    QString UdpSendingAddress;
    quint16 UdpReceivePort;

};

#endif // FMSCONFIG_H
