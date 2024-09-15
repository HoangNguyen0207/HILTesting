#include "udpmulticastconnector.h"

UdpMulticastConnector::UdpMulticastConnector(const QString &macAddr, const QString &groupIp, int localPort, int destPort)
    : mMac(macAddr), mGroupIpAddress(groupIp), mLocalPort(localPort), mDestPort(destPort)
{
    mReceiveDataPtr = QSharedPointer<char>(new char[DataSize::IODeviceBufferSize]);
}

void UdpMulticastConnector::stopIO()
{
    mUdpSocket->close();
    emit disconnected();
}

bool UdpMulticastConnector::sendData(const char *data, int length)
{
    qint64 byteWritten;
    byteWritten = mUdpSocket->writeDatagram(data,length,QHostAddress(mGroupIpAddress),(quint16)mDestPort);
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

bool UdpMulticastConnector::startIO()
{
    if(!mUdpSocket)
    {
        mUdpSocket = QSharedPointer<QUdpSocket>(new QUdpSocket());
        connect(mUdpSocket.data(), &QUdpSocket::stateChanged, this, &UdpMulticastConnector::handleState);
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
                if(!mUdpSocket->bind(QHostAddress::AnyIPv4, (quint16)mLocalPort, QAbstractSocket::ShareAddress))
                {
                    LOG_DEBUG("Cannot bind port %d", mLocalPort);

                }else
                {
                    LOG_DEBUG("Bound port %d success", mLocalPort);
                }

                if(!mUdpSocket->joinMulticastGroup(QHostAddress(mGroupIpAddress), allInterfaces[i]))
                {
                    LOG_DEBUG("Cannot join multicast group %s", mGroupIpAddress.toStdString().c_str());
                }else
                {
                    LOG_DEBUG("UdpMulticastConnector connect successfully throuht group addess %s, macAddr = %s",mGroupIpAddress.toStdString().c_str(),
                                                                                                                 mMac.toStdString().c_str());
                    connect(mUdpSocket.data(),&QUdpSocket::readyRead,this,&UdpMulticastConnector::handleReadyRead);
                    emit connected();
                    return true;
                }
            }
        }
    }

    LOG_DEBUG("UDP Socket state is unspecified");
    return false;
}

void UdpMulticastConnector::handleReadyRead()
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

void UdpMulticastConnector::handleState(QAbstractSocket::SocketState state)
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
