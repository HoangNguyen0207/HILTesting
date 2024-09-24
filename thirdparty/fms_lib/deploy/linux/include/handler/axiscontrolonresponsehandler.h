#ifndef AXISCONTROLONRESPONSEHANDLER_H
#define AXISCONTROLONRESPONSEHANDLER_H

#include "basehandler.h"

class AxisControlOnResponseHandler : public BaseHandler
{
public:
    AxisControlOnResponseHandler();
public:
    void handle(IOMessage *message);
};

#endif // AXISCONTROLONRESPONSEHANDLER_H
