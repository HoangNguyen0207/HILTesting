#ifndef AXISCONTROLOFFHANDLER_H
#define AXISCONTROLOFFHANDLER_H

#include "basehandler.h"

class AxisControlOffHandler : public BaseHandler
{
public:
    AxisControlOffHandler();

    void handle(IOMessage *message) override;
};

#endif // AXISCONTROLOFFHANDLER_H
