#ifndef CONTROLONRESPONSEHANDLER_H
#define CONTROLONRESPONSEHANDLER_H

#include "basehandler.h"

class ControlOnResponseHandler : public BaseHandler
{
public:
    ControlOnResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // CONTROLONRESPONSEHANDLER_H
