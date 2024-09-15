#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialConnector : public QObject
{
        Q_OBJECT
    public:
        SerialConnector();
        SerialConnector(const std::string& portName);
        ~SerialConnector();

        bool startIO();
        bool stopIO();
        void send(char* data, int length);

        void setPortName(const std::string& portName);
        void setBaudrate(const QSerialPort::BaudRate& baudrate);
        void setParity(const QSerialPort::Parity& parity);
        void setStopBits(const QSerialPort::StopBits& stopBits);
        void setDataBits(const QSerialPort::DataBits& dataBits);
        void setFlowControl(const QSerialPort::FlowControl& flowControl);

        bool isConnected();

        bool waitForReadyRead(int timeout);

        QByteArray read();

    signals:
        void sigReadIOMessage(QSharedPointer<char> data, int length);
        void sigPortDisconnected();
        void sigPortConnected();

    private slots:
        void onPortConnected();
        void onPortDisconnected();
        void handleReadyRead();
        void setConnectStatus(bool status);

    private:
        QSharedPointer<QSerialPort> mSerialPort{nullptr};
        std::string mPortName{""};
        QSerialPort::BaudRate mBaudrate{QSerialPort::Baud115200};
        QSerialPort::Parity mParity{QSerialPort::NoParity};
        QSerialPort::StopBits mStopBits{QSerialPort::OneStop};
        QSerialPort::DataBits mDataBits{QSerialPort::Data8};
        QSerialPort::FlowControl mFlowControl{QSerialPort::NoFlowControl};
        bool mConnectStatus{false};
        QByteArray mRecByteArray;

};

