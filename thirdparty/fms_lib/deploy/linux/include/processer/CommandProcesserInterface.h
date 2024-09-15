#ifndef COMMANDPROCESSERINTERFACE_H
#define COMMANDPROCESSERINTERFACE_H

#include <QString>
#include "info/baseinfo.h"

class CommandProcesserInterface
{
public:
    virtual ~CommandProcesserInterface() {}
    virtual void processCmd(const QString& cmd) = 0;
    virtual void processParameter(BaseInfo* baseInfo) = 0;
    virtual void sendCommand(BaseInfo* baseInfo) = 0;
};

#endif // COMMANDPROCESSERINTERFACE_H
