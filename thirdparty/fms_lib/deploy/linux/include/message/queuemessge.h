#ifndef QUEUEMESSGE_H
#define QUEUEMESSGE_H

#include <QObject>
#include <QByteArray>
#include <QMutex>
#include <QTimer>

class QueueMessge : public QObject
{
    Q_OBJECT
public:
    explicit QueueMessge(QObject *parent = nullptr);
    ~QueueMessge();
    void swapDataQueues();
public slots:
    void on_pushData(QByteArray data);
    void on_popData();

signals:
    void sigParseMessageData(QByteArray);
private slots:
    void onTimeoutProcessData();
private:
    QByteArray *inputQueue;
    QByteArray *outputQueue;
    QMutex mutexQueue;
    QTimer timerProcessMessage;
};

#endif // QUEUEMESSGE_H
