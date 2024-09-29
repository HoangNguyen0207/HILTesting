#ifndef CFGACCSETCOMMANDPROCESSER_H
#define CFGACCSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgSpdSetInfo;

class CfgAccSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgAccSetCommandProcesser();

public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgSpdSetInfo *info = nullptr;
};

#endif // CFGACCSETCOMMANDPROCESSER_H
