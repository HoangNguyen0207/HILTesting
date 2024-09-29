#ifndef HOMINGCOMMANDPROCESSER_H
#define HOMINGCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class HomingMessage;

class HomingCommandProcesser : public EnableCommandProcesser
{
public:
    HomingCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
private:
    HomingMessage *message = nullptr;
};

#endif // HOMINGCOMMANDPROCESSER_H
