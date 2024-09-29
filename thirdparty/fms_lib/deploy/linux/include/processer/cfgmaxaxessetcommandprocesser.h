#ifndef CFGMAXAXESSETCOMMANDPROCESSER_H
#define CFGMAXAXESSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

#include <QObject>
#include "info/ResponseInfo.h"

class CfgSpdSetInfo;

class CfgMaxAxesSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgMaxAxesSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgSpdSetInfo *info = nullptr;
};

#endif // CFGMAXAXESSETCOMMANDPROCESSER_H
