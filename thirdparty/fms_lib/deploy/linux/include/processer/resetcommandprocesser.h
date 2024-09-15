#ifndef RESETCOMMANDPROCESSER_H
#define RESETCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ResetCommandProcesser : public EnableCommandProcesser
{
public:
    ResetCommandProcesser();
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // RESETCOMMANDPROCESSER_H
