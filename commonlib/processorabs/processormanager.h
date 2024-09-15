#pragma once

#include <QObject>
#include <QMap>
#include <QVector>
#include "processorabstract.h"

//This class for handleing message bus in the whole system
class ProcessorAbstract;

class ProcessorManager : public QObject
{
        Q_OBJECT
    public:
        static ProcessorManager* getInstance()
        {
            static ProcessorManager self;
            return &self;
        }

        ~ProcessorManager();
        bool registerProcessor(ProcessorAbstract* processor);
        bool deregisterProcessor(QString processorName);
        bool publish(QSharedPointer<BaseMessage> msg, QString processorName);
    private:
        ProcessorManager();
        QMap<QString, ProcessorAbstract*> mMapProcessor;
};


