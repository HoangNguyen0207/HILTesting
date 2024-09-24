#include "tcpclientconnector.h"


TcpClientConnector::TcpClientConnector()
{

}

TcpClientConnector::TcpClientConnector(const QString &ip, int port) : mTcpIP(ip), mTcpPort(port)
{

}

TcpClientConnector::~TcpClientConnector()
{

}

bool TcpClientConnector::stopIO()
{
    bool ret = true;

    if(mTcpSocket)
    {
        if(mTcpSocket->state() != QAbstractSocket::UnconnectedState)
        {
            mTcpSocket->disconnectFromHost();
        }

        mTcpSocket->close();

        if(mTcpSocket->isOpen())
        {
            ret = false;
        }
        delete mTcpSocket;
        mTcpSocket = nullptr;
    }else
    {
        LOG_DEBUG("%s TcpSocket is null", mTcpIP.toStdString().c_str());
    }

    return ret;
}

bool TcpClientConnector::send(const char *data2send, int length)
{
    bool ret {false};
    qint64 bytesWritten = mTcpSocket->write(data2send, length);
    if (bytesWritten == -1)
    {
        LOG_ERROR("Socket can not write: %s (%d bytes)",  data2send, length);
    }
    else if (bytesWritten != length)
    {
        LOG_ERROR("Socket write %d bytes in total %d",  bytesWritten, length);
    }
    else
    {
        LOG_DEBUG("Socket sent %s",data2send);
        ret = true;
    }
    return ret;
}

void TcpClientConnector::setTcpIP(const QString &ip)
{
    mTcpIP = ip;
}

void TcpClientConnector::setTcpPort(int port)
{
    mTcpPort = port;
}

bool TcpClientConnector::isConnected()
{
    return mStateConnected;
}

void TcpClientConnector::setStateConnect(bool state)
{
    mStateConnected = state;
}

bool TcpClientConnector::startIO()
{
    if(!mTcpSocket)
    {
        mTcpSocket = new QTcpSocket();
        connect(mTcpSocket, &QTcpSocket::readyRead, this, &TcpClientConnector::handleReadyRead);
        connect(mTcpSocket, &QTcpSocket::stateChanged, this, &TcpClientConnector::handleStateChanged);
        connect(mTcpSocket, &QTcpSocket::disconnected,this, &TcpClientConnector::onSocketDisconnected);
    }

    if(mTcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        mTcpSocket->connectToHost(mTcpIP,static_cast<quint16>(mTcpPort));

        if(mTcpSocket->waitForConnected())
        {
            LOG_DEBUG("Tcp is connected at ip: %s, port: %d", mTcpIP.toStdString().c_str(),mTcpPort);
            return true;
        }
    }

    if(mTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        LOG_DEBUG("Tcp is connected at ip: %s, port: %d", mTcpIP.toStdString().c_str(),mTcpPort);
        return true;
    }

    LOG_DEBUG("Tcp cannot connect to ip: %s, port: %d", mTcpIP.toStdString().c_str(), mTcpPort);
    return false;
}

void TcpClientConnector::handleReadyRead()
{
    QByteArray dataTcp = mTcpSocket->readAll();
    int length = dataTcp.size();
    QSharedPointer<char> t = QSharedPointer<char>(new char[length]);

    memcpy(t.get(),dataTcp.data(),static_cast<uint32_t>(length));
    emit handleIOMessage(t,length);
}

void TcpClientConnector::onSocketDisconnected()
{
    setStateConnect(false);
    emit sigTcpDisconnected();
}

void TcpClientConnector::onSocketConnected()
{
    setStateConnect(true);
    emit sigTcpConnected();
}

void TcpClientConnector::handleStateChanged(QAbstractSocket::SocketState state)
{
    switch (state)
    {
        case QAbstractSocket::SocketState::ListeningState:
        {
            LOG_DEBUG("Change socket state %s to ListeningState", mTcpIP.toStdString().c_str());
            break;
        }
        case QAbstractSocket::SocketState::ClosingState:
        {
            LOG_DEBUG("Change socket state %s to ClosingState", mTcpIP.toStdString().c_str());
            break;
        }
        case QAbstractSocket::SocketState::BoundState:
        {
            LOG_DEBUG("Change socket state %s to BoundState", mTcpIP.toStdString().c_str());
            break;
        }
        case QAbstractSocket::SocketState::HostLookupState:
        {
            LOG_DEBUG("Change socket state %s to HostLookupState", mTcpIP.toStdString().c_str());
            break;
        }
        case QAbstractSocket::SocketState::ConnectingState:
        {
            LOG_DEBUG("Change socket state %s to ConnectingState", mTcpIP.toStdString().c_str());
            break;
        }
        case QAbstractSocket::SocketState::ConnectedState:
        {
            LOG_DEBUG("Change socket state %s to ConnectedState", mTcpIP.toStdString().c_str());
            onSocketConnected();
            break;
        }
        case QAbstractSocket::SocketState::UnconnectedState:
        {
            LOG_DEBUG("Change socket state %s to UnconnectedState", mTcpIP.toStdString().c_str());
            onSocketDisconnected();
            break;
        }
        default:
        break;
    }
}
