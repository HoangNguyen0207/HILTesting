#ifndef HEXAPODSTATUSCOMMANDPROCESSER_H
#define HEXAPODSTATUSCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class BaseInfo;
class HexapodStatusMessage;

class HexapodStatusCommandProcesser  : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    HexapodStatusCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);
private:
    BaseInfo *baseInfo = nullptr;
    HexapodStatusMessage *message;
};

#endif // HEXAPODSTATUSCOMMANDPROCESSER_H
