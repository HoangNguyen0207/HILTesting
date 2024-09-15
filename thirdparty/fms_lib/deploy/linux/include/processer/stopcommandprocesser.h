#ifndef STOPCOMMANDPROCESSER_H
#define STOPCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class StopCommandProcesser : public EnableCommandProcesser
{
public:
    StopCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd) override;
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // STOPCOMMANDPROCESSER_H
