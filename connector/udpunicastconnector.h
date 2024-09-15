#pragma once
#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QSharedPointer>
#include "typedef/globalvar.h"
#include "logger/logger.h"
#include <QNetworkInterface>
#include <QNetworkProxy>

class UdpUnicastConnector : public QObject
{
        Q_OBJECT
    public:
        UdpUnicastConnector();
        UdpUnicastConnector(const QString& macAddr,
                            const int& localPort,
                            const QString& remoteIp, const int& remotePort);
        ~UdpUnicastConnector();

        int localPort() const;
        void setLocalPort(int localPort);

        QString remoteIp() const;
        void setRemoteIp(const QString &remoteIp);

        int remotePort() const;
        void setRemotePort(int remotePort);

        void stopIO();
        bool sendData(const char* data, int length);

        QString mac() const;
        void setMac(const QString &mac);

    signals:
        void connected();
        void disconnected();
        void completeReadData(QSharedPointer<char> data, qint64 length);

    public slots:
        bool startIO();
        void handleReadyRead();
        void handleState(QAbstractSocket::SocketState state);

    private:
        QString mMac{"0"};
        int mLocalPort{0};
        QString mRemoteIp{"0"};
        int mRemotePort{0};
        QSharedPointer<QUdpSocket> mUdpSocket{nullptr};
        QSharedPointer<char> mReceiveDataPtr {nullptr};
};

