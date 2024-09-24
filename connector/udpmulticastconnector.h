#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QSharedPointer>
#include "typedef/globalvar.h"
#include "logger/logger.h"
#include <QNetworkInterface>
#include <QNetworkProxy>

class UdpMulticastConnector : public QObject
{
        Q_OBJECT
    public:
        UdpMulticastConnector(const QString& macAddr,
                              const QString& groupIp,
                              int localPort, int destPort);
        void stopIO();
        bool sendData(const char* data, int length);
    signals:
        void connected();
        void disconnected();
        void completeReadData(QSharedPointer<char> data, qint64 length);

    public slots:
        bool startIO();
        void handleReadyRead();
        void handleState(QAbstractSocket::SocketState state);

    private:
        QString mMac {"0"};
        QString mGroupIpAddress {"0"};
        int mLocalPort {0};
        int mDestPort {0};
        QSharedPointer<QUdpSocket> mUdpSocket{nullptr};
        QSharedPointer<char> mReceiveDataPtr {nullptr};
};

