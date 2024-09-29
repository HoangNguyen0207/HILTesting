#ifndef UDPCONTROLLER_H
#define UDPCONTROLLER_H

#include "FmsApi_global.h"
#include <QObject>
#include <QUdpSocket>
#include "message/IOMessage.h"
#include <QThread>
#include "udpreceiver.h"

class FMSAPI_EXPORT UDPController : public QObject
{
    Q_OBJECT

public:
    UDPController();
    ~UDPController();
    static UDPController* Instance();
    static void Release();
    void releaseThread();
    void initThread(QObject* pObject);
    void setPriority(QThread::Priority priority);
    void startThread();
    bool initSocket(uint sendPort = 0, uint recvPort = 0, bool receiver = false);
    static bool InitSocket(uint sendPort = 0, uint recvPort = 0, bool receiver = false);
    void releaseSocket();
    static void ReleaseSocket();
    bool sendData(const char *data, qint64 size, quint32 ipAddress, quint16 port = 0);
    static bool SendData(const char *data, qint64 size, quint32 ipAddress, quint16 port = 0);
    bool sendData(QByteArray data, quint32 ipAddress, quint16 port = 0);
    static bool SendData(QByteArray data, quint32 ipAddress, quint16 port = 0);
    bool sendData(IOMessage* message, quint32 ipAddress, quint16 port = 0);
    static bool SendData(IOMessage* message, quint32 ipAddress, quint16 port = 0);
    bool sendData(IOMessage* message);
    static bool SendData(IOMessage* message);
signals:
    void sigDataReceived(quint32 ipAddress, QByteArray data);
    void siginitReceiveThread(uint recvPort);
public slots:
    void onSendEnableResponseMessage(const int& state);
    void onSendDisableResponseMessage(const int& state);
    void onSendControlOnResponseMessage(const int& state);
    void onSendControlOffResponseMessage(const int& state);
    void onSendHomingResponseMessage(const int& state);
    void onSendMoveAbsResponseMessage(const int& state);
    void onSendStopResponseMessage(const int& state);
private slots:
    void readPendingDatagrams();
    virtual void onStarted() {;}
private:
    void processDatagram(QNetworkDatagram& dataGram);
    static UDPController* m_pInstance;

    QUdpSocket* m_pUdpSendSocket = nullptr;
    QUdpSocket* m_pUdpReceiveSocket = nullptr;
    QHostAddress *m_sendHostAddress;
    quint16 m_sendPort;
    quint16 m_receivePort;
    quint32 m_sendIPAddress;
    UdpReceiver *udpReceiver;
    QThread workerThread;
};

#endif // UDPCONTROLLER_H
