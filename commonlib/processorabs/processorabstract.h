#pragma once

#include <QObject>
#include "workerthread.h"
#include "../messageabs/basemessage.h"
#include "../logger/logger.h"
#include <QSharedPointer>
#include <QTimer>
#include <QVector>
#include "processormanager.h"

class ProcessorAbstract : public QObject
{
        Q_OBJECT
    public:
        ProcessorAbstract(const QString& processorName);
        virtual ~ProcessorAbstract();
        QString getProcessorName() const;
        bool publish(QSharedPointer<BaseMessage> msg, const QString& processorName);

    signals:
        void sendMessage(QSharedPointer<BaseMessage> msg);
        void startProcess();
        void stopProcess();

    public slots:
        virtual void onMessage(QSharedPointer<BaseMessage> msg) = 0;
        virtual void onStartProcess();
        virtual void onStopProcess();

    private:
        ProcessorAbstract(const ProcessorAbstract&) = delete;
        ProcessorAbstract(ProcessorAbstract&&) = delete;
        ProcessorAbstract& operator=(const ProcessorAbstract&) = delete;
        ProcessorAbstract& operator=(ProcessorAbstract &&) = delete;

    private:
        QString mProcessorName;
        WorkerThread mThread;
};

