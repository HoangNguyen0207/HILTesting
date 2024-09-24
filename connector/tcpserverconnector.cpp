#include "tcpserverconnector.h"

TcpServerConnector::TcpServerConnector(int port) : mTcpPort(port)
{
    connect(&mTcpServer, &QTcpServer::newConnection, this, &TcpServerConnector::receiveNewConnection);
}

TcpServerConnector::~TcpServerConnector()
{
    if(mTcpSocket)
    {
        delete mTcpSocket;
        mTcpSocket = nullptr;
    }
}

bool TcpServerConnector::startIO()
{
    if(!mTcpServer.listen(QHostAddress::Any, static_cast<uint16_t>(mTcpPort)))
    {
        LOG_ERROR("Listen Error: %s",mTcpSocket->errorString().toStdString());
        return false;
    }

    LOG_DEBUG("Tcp Server Listening...");
    return true;
}

void TcpServerConnector::stopIO()
{
    mTcpServer.close();
}

bool TcpServerConnector::send(QByteArray data)
{
    qint64 bytesWritten = -1;
    bytesWritten = mTcpSocket->write(data);
    if(bytesWritten == -1)
    {
        LOG_ERROR("Socket can not write");
        return false;
    }else
    {
        return true;
    }
}

void TcpServerConnector::setPort(int port)
{
    mTcpPort = port;
}

void TcpServerConnector::receiveNewConnection()
{
    mTcpSocket = mTcpServer.nextPendingConnection();
    if(!mTcpSocket)
    {
        return;
    }
    connect(mTcpSocket,&QTcpSocket::readyRead,this,&TcpServerConnector::handleReadyRead);
}

void TcpServerConnector::handleReadyRead()
{
    QByteArray dataTcp = mTcpSocket->readAll();
    int length = dataTcp.size();
    QSharedPointer<char> t = QSharedPointer<char>(new char[length]);

    memcpy(t.get(),dataTcp.data(),static_cast<uint32_t>(length));
    emit handleIOMessage(t,length);
}
