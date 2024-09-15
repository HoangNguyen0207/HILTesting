#ifndef HEXAPODSTATUSHANDLER_H
#define HEXAPODSTATUSHANDLER_H

#include "basehandler.h"

class HexapodStatusHandler : public BaseHandler
{
public:
    HexapodStatusHandler();
    void handle(IOMessage *message) override;
};

#endif // HEXAPODSTATUSHANDLER_H
