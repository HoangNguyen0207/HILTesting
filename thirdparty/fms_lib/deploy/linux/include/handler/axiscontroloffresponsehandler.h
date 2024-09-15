#ifndef AXISCONTROLOFFRESPONSEHANDLER_H
#define AXISCONTROLOFFRESPONSEHANDLER_H

#include "basehandler.h"

class AxisControlOffResponseHandler : public BaseHandler
{
public:
    AxisControlOffResponseHandler();
public:
    void handle(IOMessage *message);
};

#endif // AXISCONTROLOFFRESPONSEHANDLER_H
