#ifndef MOVEABSRESPONSEHANDLER_H
#define MOVEABSRESPONSEHANDLER_H

#include "basehandler.h"

class MoveAbsResponseHandler : public BaseHandler
{
public:
    MoveAbsResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // MOVEABSRESPONSEHANDLER_H
