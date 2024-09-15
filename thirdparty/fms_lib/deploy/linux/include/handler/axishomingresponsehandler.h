#ifndef AXISHOMINGRESPONSEHANDLER_H
#define AXISHOMINGRESPONSEHANDLER_H

#include "basehandler.h"

class AxisHomingResponseHandler : public BaseHandler
{
public:
    AxisHomingResponseHandler();
public:
    void handle(IOMessage *message);
};

#endif // AXISHOMINGRESPONSEHANDLER_H
