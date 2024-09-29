#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include "message/queuemessge.h"
#include <QThread>

class UdpReceiver : public QObject
{
    Q_OBJECT
public:
    explicit UdpReceiver(QObject *parent = nullptr);

public slots:
    void iniSocketAndReceiveMessage(uint recvPort);
    void onParseMessage(QByteArray data);

signals:
    void sigSaveMessage(QByteArray data);
    void sigStartQueueWorker();

private slots:
    void readPendingDatagrams();

private:
    void processDatagram(QNetworkDatagram& dataGram);
    quint16 m_receivePort;
    QUdpSocket* m_pUdpReceiveSocket = nullptr;
    QueueMessge *queueMessage = nullptr;
    int counter = 0;
    QThread queueThread;
};

#endif // UDPRECEIVER_H
