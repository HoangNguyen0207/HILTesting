#ifndef CONTROLOFFCOMMANDPROCESSER_H
#define CONTROLOFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ControlOffMessage;

class ControlOffCommandProcesser : public EnableCommandProcesser
{
public:
    ControlOffCommandProcesser();
    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;

private:
    ControlOffMessage *message = nullptr;
};

#endif // CONTROLOFFCOMMANDPROCESSER_H
