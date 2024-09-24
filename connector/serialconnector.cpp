#include "serialconnector.h"
#include "logger/logger.h"
#include <QDebug>

SerialConnector::SerialConnector()
{

}

SerialConnector::SerialConnector(const std::string &portName)
    : mPortName(portName)
{

}

SerialConnector::~SerialConnector()
{

}

bool SerialConnector::startIO()
{
    mSerialPort = QSharedPointer<QSerialPort>(new QSerialPort);
    mSerialPort->setPortName(QString::fromStdString(mPortName));
    mSerialPort->setBaudRate(mBaudrate);
    mSerialPort->setParity(mParity);
    mSerialPort->setStopBits(mStopBits);
    mSerialPort->setDataBits(mDataBits);
    mSerialPort->setFlowControl(mFlowControl);

    if(mSerialPort->open(QIODevice::ReadWrite))
    {
        LOG_DEBUG("Open port %s successfully",this->mPortName);
        QObject::connect(mSerialPort.get(),&QSerialPort::readyRead,this,&SerialConnector::handleReadyRead);
        onPortConnected();
    }else
    {
        LOG_DEBUG("Open port %s failed",this->mPortName);
        qDebug() << mSerialPort->error();
        onPortDisconnected();
        return false;
    }
    return true;
}

bool SerialConnector::stopIO()
{
    if(mSerialPort)
    {
        mSerialPort->close();
        onPortDisconnected();
    }
    return true;
}

void SerialConnector::send(char *data, int length)
{
    QByteArray sendData(data,length);
    const quint64 bytesWriten = mSerialPort->write(sendData);
    if(mSerialPort->waitForBytesWritten(1000))
    {

    }
    if(bytesWriten == length)
    {
//        LOG_DEBUG("Send data %s successfully",QString(data).toStdString().c_str());
    }else
    {
        LOG_DEBUG("Send data %s failed",QString(data).toStdString().c_str());
    }
}

void SerialConnector::setPortName(const std::string &portName)
{
    this->mPortName = portName;
}

void SerialConnector::setBaudrate(const QSerialPort::BaudRate &baudrate)
{
    this->mBaudrate = baudrate;
}

void SerialConnector::setParity(const QSerialPort::Parity &parity)
{
    this->mParity = parity;
}

void SerialConnector::setStopBits(const QSerialPort::StopBits &stopBits)
{
    this->mStopBits = stopBits;
}

void SerialConnector::setDataBits(const QSerialPort::DataBits &dataBits)
{
    this->mDataBits = dataBits;
}

void SerialConnector::setFlowControl(const QSerialPort::FlowControl &flowControl)
{
    this->mFlowControl = flowControl;
}

bool SerialConnector::isConnected()
{
    return this->mConnectStatus;
}

bool SerialConnector::waitForReadyRead(int timeout)
{
    return mSerialPort->waitForReadyRead(timeout);
}

QByteArray SerialConnector::read()
{
    return mRecByteArray;
}

void SerialConnector::onPortConnected()
{
    setConnectStatus(true);
    emit sigPortConnected();
}

void SerialConnector::onPortDisconnected()
{
    setConnectStatus(false);
    emit sigPortDisconnected();
}

void SerialConnector::handleReadyRead()
{
    QByteArray dataSerial = mSerialPort->readAll();
    int length = dataSerial.size();

    QSharedPointer<char> t = QSharedPointer<char>(new char[length]);
    memcpy(t.get(),dataSerial.data(),static_cast<uint32_t>(length));
    emit sigReadIOMessage(t,length);

    mRecByteArray.clear();
    mRecByteArray = dataSerial;
}

void SerialConnector::setConnectStatus(bool status)
{
    this->mConnectStatus = status;
}
