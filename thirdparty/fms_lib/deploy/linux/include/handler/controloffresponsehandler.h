#ifndef CONTROLOFFRESPONSEHANDLER_H
#define CONTROLOFFRESPONSEHANDLER_H

#include "basehandler.h"

class ControlOffResponseHandler : public BaseHandler
{
public:
    ControlOffResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // CONTROLOFFRESPONSEHANDLER_H
