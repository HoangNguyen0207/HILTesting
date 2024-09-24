#ifndef ACTUATORSSTATUSRESPONSEHANDLER_H
#define ACTUATORSSTATUSRESPONSEHANDLER_H

#include "basehandler.h"

class ActuatorsStatusResponseHandler : public BaseHandler
{
public:
    ActuatorsStatusResponseHandler();
    // BaseHandler interface
public:
    void handle(IOMessage *message);
};

#endif // ACTUATORSSTATUSRESPONSEHANDLER_H
