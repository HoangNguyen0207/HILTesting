#include "processorabstract.h"

ProcessorAbstract::ProcessorAbstract(const QString &processorName)
    : mProcessorName(processorName)
{
    ProcessorManager::getInstance()->registerProcessor(this);
    mThread.setObjectName(processorName);
    this->moveToThread(&mThread);
    connect(&mThread,&WorkerThread::finished,this,&ProcessorAbstract::deleteLater);
    mThread.start(QThread::Priority::NormalPriority);

    //note
    connect(this, &ProcessorAbstract::sendMessage, this, &ProcessorAbstract::onMessage, Qt::QueuedConnection);
    connect(this, &ProcessorAbstract::startProcess, this, &ProcessorAbstract::onStartProcess, Qt::QueuedConnection);
    connect(this, &ProcessorAbstract::stopProcess, this, &ProcessorAbstract::onStopProcess, Qt::BlockingQueuedConnection);
}

ProcessorAbstract::~ProcessorAbstract()
{
    LOG_DEBUG("[%s] Destructor", mProcessorName.toStdString().c_str());
    ProcessorManager::getInstance()->deregisterProcessor(mProcessorName);
    mThread.quit();
    mThread.wait();
}

QString ProcessorAbstract::getProcessorName() const
{
    return mProcessorName;
}

bool ProcessorAbstract::publish(QSharedPointer<BaseMessage> msg, const QString &processorName)
{
    if (msg == nullptr)
    {
        LOG_DEBUG("Publish a null message!!");
        return false;
    }
    else
    {
        ProcessorManager::getInstance()->publish(msg, processorName);
        return true;
    }
}

void ProcessorAbstract::onStartProcess()
{
    LOG_DEBUG("Start process %s - LWP = %s", getProcessorName().toStdString().c_str(), mThread.currentThreadId());
}

void ProcessorAbstract::onStopProcess()
{
    LOG_DEBUG("Stop process %s - LWP = %s", getProcessorName().toStdString().c_str(), mThread.currentThreadId());
}
