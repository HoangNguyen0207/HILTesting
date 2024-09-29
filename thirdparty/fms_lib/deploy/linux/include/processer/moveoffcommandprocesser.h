#ifndef MOVEOFFCOMMANDPROCESSER_H
#define MOVEOFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class MoveOffMessage;

class MoveOffCommandProcesser : public EnableCommandProcesser
{
public:
    MoveOffCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;

private:
    MoveOffMessage *message = nullptr;
};

#endif // MOVEOFFCOMMANDPROCESSER_H
