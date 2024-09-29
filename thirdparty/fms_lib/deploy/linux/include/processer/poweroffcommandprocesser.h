#ifndef POWEROFFCOMMANDPROCESSER_H
#define POWEROFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class BaseInfo;
class PowerOffMessage;

class PowerOffCommandProcesser : public EnableCommandProcesser
{
public:
    PowerOffCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd) override;
    void sendCommand(BaseInfo *baseInfo) override;

private:
    BaseInfo *baseInfo = nullptr;
    PowerOffMessage *message = nullptr;
};

#endif // POWEROFFCOMMANDPROCESSER_H
