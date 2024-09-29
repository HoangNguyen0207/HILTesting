#ifndef CFGLIMWSSETCOMMANDPROCESSER_H
#define CFGLIMWSSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include "info/moveabsinfo.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgLimInfo;
class CfgLimWsSetMessage;

class CfgLimWsSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimWsSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

    MoveAbsInfo *getInfo() const;
    void setInfo(MoveAbsInfo *value);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    //    CfgLimInfo *info = nullptr;
    CfgLimWsSetMessage *message = nullptr;
    MoveAbsInfo *info = nullptr;
};

#endif // CFGLIMWSSETCOMMANDPROCESSER_H
