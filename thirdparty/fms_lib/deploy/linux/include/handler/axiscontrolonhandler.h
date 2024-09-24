#ifndef AXISCONTROLONHANDLER_H
#define AXISCONTROLONHANDLER_H

#include "basehandler.h"

class AxisControlOnHandler : public BaseHandler
{
public:
    AxisControlOnHandler();
    void handle(IOMessage *message) override;
};

#endif // AXISCONTROLONHANDLER_H
