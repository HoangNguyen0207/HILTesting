#include "processormanager.h"

ProcessorManager::ProcessorManager()
{

}

ProcessorManager::~ProcessorManager()
{

}

bool ProcessorManager::registerProcessor(ProcessorAbstract* processor)
{
    if(mMapProcessor.contains(processor->getProcessorName()))
    {
        LOG_ERROR("Processor has already existed!!!");
        return false;
    }else
    {
        mMapProcessor.insert(processor->getProcessorName(), processor);
        return true;
    }
}

bool ProcessorManager::deregisterProcessor(QString processorName)
{
    if(!mMapProcessor.contains(processorName))
    {
        LOG_ERROR("Processor hasnt existed yet!!!");
        return false;
    }else
    {
        mMapProcessor.remove(processorName);
        return true;
    }
}

bool ProcessorManager::publish(QSharedPointer<BaseMessage> msg, QString processorName)
{
    if(!mMapProcessor.contains(processorName))
    {
        LOG_ERROR("Service is not registered yet: %s!!!", processorName.toStdString().c_str());
        return false;
    }else
    {
        emit mMapProcessor[processorName]->sendMessage(msg);
        return true;
    }
}


