#ifndef STOPCOMMANDPROCESSER_H
#define STOPCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class BaseInfo;
class StopMessage;

class StopCommandProcesser : public EnableCommandProcesser
{
public:
    StopCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd) override;
    void sendCommand(BaseInfo *baseInfo) override;

private:
    BaseInfo *baseInfo = nullptr;
    StopMessage *message = nullptr;
};

#endif // STOPCOMMANDPROCESSER_H
