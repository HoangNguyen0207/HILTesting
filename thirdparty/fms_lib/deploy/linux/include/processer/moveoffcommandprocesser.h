#ifndef MOVEOFFCOMMANDPROCESSER_H
#define MOVEOFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class MoveOffCommandProcesser : public EnableCommandProcesser
{
public:
    MoveOffCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // MOVEOFFCOMMANDPROCESSER_H
