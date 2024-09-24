#pragma once

#include <QObject>
#include <QTimer>
#include <QSharedPointer>
#include "logger/logger.h"
#include <QNetworkInterface>
#include <QNetworkProxy>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServerConnector : public QObject
{
        Q_OBJECT
    public:
        explicit TcpServerConnector(int port);
        ~TcpServerConnector();
        bool startIO();
        void stopIO();
        bool send(QByteArray data);
        void setPort(int port);

    signals:
        void handleIOMessage(QSharedPointer<char> data, int length);

    public slots:

    private slots:
        void receiveNewConnection();
        void handleReadyRead();
    private:

    private:
        QTcpServer mTcpServer;
        QTcpSocket* mTcpSocket{nullptr};
        int mTcpPort {0};
};

