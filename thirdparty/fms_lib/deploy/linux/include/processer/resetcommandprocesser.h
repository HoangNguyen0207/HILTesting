#ifndef RESETCOMMANDPROCESSER_H
#define RESETCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ResetMessage;

class ResetCommandProcesser : public EnableCommandProcesser
{
public:
    ResetCommandProcesser();
public:
    void sendCommand(BaseInfo *baseInfo) override;

private:
    ResetMessage *message = nullptr;
};

#endif // RESETCOMMANDPROCESSER_H
