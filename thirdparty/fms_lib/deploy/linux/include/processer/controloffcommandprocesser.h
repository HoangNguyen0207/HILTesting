#ifndef CONTROLOFFCOMMANDPROCESSER_H
#define CONTROLOFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ControlOffCommandProcesser : public EnableCommandProcesser
{
public:
    ControlOffCommandProcesser();
    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // CONTROLOFFCOMMANDPROCESSER_H
