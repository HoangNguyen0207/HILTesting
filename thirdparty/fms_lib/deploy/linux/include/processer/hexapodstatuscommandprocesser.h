#ifndef HEXAPODSTATUSCOMMANDPROCESSER_H
#define HEXAPODSTATUSCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class HexapodStatusCommandProcesser : public EnableCommandProcesser
{
public:
    HexapodStatusCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // HEXAPODSTATUSCOMMANDPROCESSER_H
