#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QSharedPointer>
#include "logger/logger.h"
#include <QNetworkInterface>
#include <QNetworkProxy>

class TcpClientConnector : public QObject
{
        Q_OBJECT
    public:
        TcpClientConnector();
        TcpClientConnector(const QString& ip, int port);
        ~TcpClientConnector() override;

        bool startIO();
        bool stopIO();
        bool send(const char* data2send, int length);
        void setTcpIP(const QString& ip);
        void setTcpPort(int port);
        bool isConnected();

    signals:
        void handleIOMessage(QSharedPointer<char> data, int length);
        void sigTcpDisconnected();
        void sigTcpConnected();

    public slots:

    private slots:
        void handleReadyRead();
        void handleStateChanged(QAbstractSocket::SocketState state);
        void onSocketDisconnected();
        void onSocketConnected();

    private:
        QString mTcpIP;
        int mTcpPort {0};
        QTcpSocket* mTcpSocket {nullptr};
        bool mStateConnected {false};

    private:
        void setStateConnect(bool state);

};

