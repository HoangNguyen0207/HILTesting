#ifndef POWEROFFCOMMANDPROCESSER_H
#define POWEROFFCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class PowerOffCommandProcesser : public EnableCommandProcesser
{
public:
    PowerOffCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd) override;
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // POWEROFFCOMMANDPROCESSER_H
