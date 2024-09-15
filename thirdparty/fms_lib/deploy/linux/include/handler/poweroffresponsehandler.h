#ifndef POWEROFFRESPONSEHANDLER_H
#define POWEROFFRESPONSEHANDLER_H

#include "basehandler.h"

class PowerOffResponseHandler : public BaseHandler
{
public:
    PowerOffResponseHandler();
public:
    void handle(IOMessage *message);
};

#endif // POWEROFFRESPONSEHANDLER_H
