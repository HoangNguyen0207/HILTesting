#ifndef MOVINGABSCOMMANDPROCESSER_H
#define MOVINGABSCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class MovingAbsCommandProcesser : public CommandProcesserInterface
{
public:
    MovingAbsCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // MOVINGABSCOMMANDPROCESSER_H
