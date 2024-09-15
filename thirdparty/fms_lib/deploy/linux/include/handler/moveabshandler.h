#ifndef MOVEABSHANDLER_H
#define MOVEABSHANDLER_H

#include "basehandler.h"

class MoveAbsHandler : public BaseHandler
{
public:
    MoveAbsHandler();

    void handle(IOMessage *message) override;
};

#endif // MOVEABSHANDLER_H
