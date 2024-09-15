#include "udpunicastconnector.h"



UdpUnicastConnector::UdpUnicastConnector()
{
    if(!mReceiveDataPtr)
    {
        mReceiveDataPtr = QSharedPointer<char>(new char[DataSize::IODeviceBufferSize]);
    }
}

UdpUnicastConnector::UdpUnicastConnector(const QString &macAddr, const int &localPort, const QString &remoteIp, const int &remotePort)
    : mMac(macAddr), mLocalPort(localPort), mRemoteIp(remoteIp), mRemotePort(remotePort)
{
    if(!mReceiveDataPtr)
    {
        mReceiveDataPtr = QSharedPointer<char>(new char[DataSize::IODeviceBufferSize]);
    }
}

UdpUnicastConnector::~UdpUnicastConnector()
{
    stopIO();
}

int UdpUnicastConnector::localPort() const
{
    return mLocalPort;
}

void UdpUnicastConnector::setLocalPort(int localPort)
{
    mLocalPort = localPort;
}

QString UdpUnicastConnector::remoteIp() const
{
    return mRemoteIp;
}

void UdpUnicastConnector::setRemoteIp(const QString &remoteIp)
{
    mRemoteIp = remoteIp;
}

int UdpUnicastConnector::remotePort() const
{
    return mRemotePort;
}

void UdpUnicastConnector::setRemotePort(int remotePort)
{
    mRemotePort = remotePort;
}

void UdpUnicastConnector::stopIO()
{
    mUdpSocket->close();
    emit disconnected();
}

bool UdpUnicastConnector::sendData(const char *data, int length)
{
    qint64 byteWritten;
    byteWritten = mUdpSocket->writeDatagram(data,length,QHostAddress(mRemoteIp),(quint16)mRemotePort);
    if(byteWritten == -1)
    {
        LOG_ERROR("Socket can not write: %s (%d bytes)",  data, length);
        return false;
    }else if(byteWritten != length)
    {
        LOG_ERROR("Socket write %d bytes in total %d",  byteWritten, length);
        return false;
    }else
    {
        LOG_DEBUG("Send true Udp Msg");
        return true;
    }
}

bool UdpUnicastConnector::startIO()
{
    if(!mUdpSocket)
    {
        mUdpSocket = QSharedPointer<QUdpSocket>(new QUdpSocket());
        connect(mUdpSocket.data(),&QUdpSocket::stateChanged,this,&UdpUnicastConnector::handleState);
    }

    if(mUdpSocket->state() == QAbstractSocket::BoundState)
    {
        LOG_DEBUG("UDP is bound on port %d", mLocalPort);
        emit connected();
        return true;
    }

    if(mUdpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();
        for(int i=0; i<allInterfaces.size(); i++)
        {
            mUdpSocket->setProxy(QNetworkProxy::NoProxy);
            LOG_DEBUG("MAC address: %s", allInterfaces[i].hardwareAddress().toStdString().c_str());
            LOG_DEBUG("MAC from Config: %s", mMac.toStdString().c_str());

            QString macAdd = allInterfaces[i].hardwareAddress();
            if(macAdd == mMac)
            {
                if(!mUdpSocket->bind(QHostAddress::AnyIPv4, (quint16)mLocalPort, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint))
                {
                    LOG_DEBUG("Cannot bind port %d", mLocalPort);

                }else
                {
                    connect(mUdpSocket.data(),&QUdpSocket::readyRead,this,&UdpUnicastConnector::handleReadyRead);
                    emit connected();
                    LOG_DEBUG("Bound port %d success", mLocalPort);
                    return true;
                }
            }
        }
    }

    LOG_DEBUG("UDP Socket state is unspecified");
    return false;
}

void UdpUnicastConnector::handleReadyRead()
{
    //Clear receiveData array
    memset(mReceiveDataPtr.get(), '\0', DataSize::IODeviceBufferSize);
    qint64 ret;
    qint64 length = mUdpSocket->pendingDatagramSize();

    ret = mUdpSocket->readDatagram(mReceiveDataPtr.get(),length);

    if(ret == -1)
    {
        LOG_DEBUG("Receive data failed");
    }

    emit completeReadData(mReceiveDataPtr,length);
}

void UdpUnicastConnector::handleState(QAbstractSocket::SocketState state)
{
    switch (state)
    {
        case QAbstractSocket::SocketState::UnconnectedState:
        {
            break;
        }
        default:
            break;
    }
}

QString UdpUnicastConnector::mac() const
{
    return mMac;
}

void UdpUnicastConnector::setMac(const QString &mac)
{
    mMac = mac;
}
