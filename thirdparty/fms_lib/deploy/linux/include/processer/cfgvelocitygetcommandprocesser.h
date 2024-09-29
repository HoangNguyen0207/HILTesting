#ifndef CFGVELOCITYGETCOMMANDPROCESSER_H
#define CFGVELOCITYGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgVelocityGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgVelocityGetCommandProcesser();

public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);
};

#endif // CFGVELOCITYGETCOMMANDPROCESSER_H
