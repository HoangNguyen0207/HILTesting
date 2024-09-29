#ifndef ENABLECOMMANDPROCESSER_H
#define ENABLECOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class BaseInfo;
class EnableMessage;

class EnableCommandProcesser : public CommandProcesserInterface
{
public:
    EnableCommandProcesser();
    ~EnableCommandProcesser();

    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
private:
    BaseInfo *baseInfo = nullptr;
    EnableMessage *message = nullptr;
};

#endif // ENABLECOMMANDPROCESSER_H
