#ifndef HEXAPODSTATUSRESPONSEHANDLER_H
#define HEXAPODSTATUSRESPONSEHANDLER_H

#include "basehandler.h"

class HexapodStatusResponseHandler : public BaseHandler
{
public:
    HexapodStatusResponseHandler();

public:
    void handle(IOMessage *message);
};

#endif // HEXAPODSTATUSRESPONSEHANDLER_H
