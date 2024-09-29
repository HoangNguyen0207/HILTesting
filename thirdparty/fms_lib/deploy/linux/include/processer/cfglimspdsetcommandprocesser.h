#ifndef CFGLIMSPDSETCOMMANDPROCESSER_H
#define CFGLIMSPDSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgLimInfo;
class CfgLimSpdSetMessage;

class CfgLimSpdSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimSpdSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgLimInfo *info = nullptr;
    CfgLimSpdSetMessage *message = nullptr;
};

#endif // CFGLIMSPDSETCOMMANDPROCESSER_H
