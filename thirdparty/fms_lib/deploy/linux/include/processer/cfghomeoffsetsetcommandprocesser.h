#ifndef CFGHOMEOFFSETSETCOMMANDPROCESSER_H
#define CFGHOMEOFFSETSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"
#include "info/moveabsinfo.h"

class CfgHomeOffsetSetCommandProcesser : public QObject,  public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgHomeOffsetSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

    MoveAbsInfo *getInfo() const;
    void setInfo(MoveAbsInfo *value);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    MoveAbsInfo *info = nullptr;
};

#endif // CFGHOMEOFFSETSETCOMMANDPROCESSER_H
