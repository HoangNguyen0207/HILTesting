#ifndef CFGACCGETCOMMANDPROCESSER_H
#define CFGACCGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgAccGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgAccGetCommandProcesser();
public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);
};

#endif // CFGACCGETCOMMANDPROCESSER_H
