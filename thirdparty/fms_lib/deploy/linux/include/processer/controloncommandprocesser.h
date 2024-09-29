#ifndef CONTROLONCOMMANDPROCESSER_H
#define CONTROLONCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ControlOnMessage;

class ControlOnCommandProcesser : public EnableCommandProcesser
{
public:
    ControlOnCommandProcesser();

public:
    void sendCommand(BaseInfo *baseInfo) override;

private:
    ControlOnMessage *message = nullptr;
};

#endif // CONTROLONCOMMANDPROCESSER_H
