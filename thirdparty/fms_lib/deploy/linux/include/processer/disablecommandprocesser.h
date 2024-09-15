#ifndef DISABLECOMMANDPROCESSER_H
#define DISABLECOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class DisableCommandProcesser : public EnableCommandProcesser
{
public:
    DisableCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // DISABLECOMMANDPROCESSER_H
