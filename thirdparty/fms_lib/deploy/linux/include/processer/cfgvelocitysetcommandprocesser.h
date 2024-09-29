#ifndef CFGVELOCITYSETCOMMANDPROCESSER_H
#define CFGVELOCITYSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

#include <QObject>
#include "info/ResponseInfo.h"

class CfgSpdSetInfo;

class CfgVelocitySetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgVelocitySetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgSpdSetInfo *info = nullptr;
};

#endif // CFGVELOCITYSETCOMMANDPROCESSER_H
