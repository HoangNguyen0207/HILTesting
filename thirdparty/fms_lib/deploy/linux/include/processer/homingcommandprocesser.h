#ifndef HOMINGCOMMANDPROCESSER_H
#define HOMINGCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class HomingCommandProcesser : public EnableCommandProcesser
{
public:
    HomingCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // HOMINGCOMMANDPROCESSER_H
