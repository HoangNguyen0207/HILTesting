#ifndef ENABLECOMMANDPROCESSER_H
#define ENABLECOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class EnableCommandProcesser : public CommandProcesserInterface
{
public:
    EnableCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // ENABLECOMMANDPROCESSER_H
