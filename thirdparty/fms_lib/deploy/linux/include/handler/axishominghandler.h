#ifndef AXISHOMINGHANDLER_H
#define AXISHOMINGHANDLER_H

#include "basehandler.h"

class AxisHomingHandler : public BaseHandler
{
public:
    AxisHomingHandler();
    void handle(IOMessage *message) override;
};

#endif // AXISHOMINGHANDLER_H
