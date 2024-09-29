#ifndef DISABLECOMMANDPROCESSER_H
#define DISABLECOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class DisableMessage;

class DisableCommandProcesser : public EnableCommandProcesser
{
public:
    DisableCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;

private:
    DisableMessage *message = nullptr;
};

#endif // DISABLECOMMANDPROCESSER_H
