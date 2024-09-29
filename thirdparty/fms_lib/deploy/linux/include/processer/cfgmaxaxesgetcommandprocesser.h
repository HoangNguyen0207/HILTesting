#ifndef CFGMAXAXESGETCOMMANDPROCESSER_H
#define CFGMAXAXESGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgMaxAxesGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgMaxAxesGetCommandProcesser();

public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);
};

#endif // CFGMAXAXESGETCOMMANDPROCESSER_H
