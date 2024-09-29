#ifndef SYSTEMSTATUSHANDLER_H
#define SYSTEMSTATUSHANDLER_H

#include "basehandler.h"

class SystemStatusHandler : public BaseHandler
{
public:
    SystemStatusHandler();

    void handle(IOMessage *message) override;
};

#endif // SYSTEMSTATUSHANDLER_H
