#ifndef STOPRESPONSEHANDLER_H
#define STOPRESPONSEHANDLER_H

#include "basehandler.h"

class StopResponseHandler : public BaseHandler
{
public:
    StopResponseHandler();

public:
    void handle(IOMessage *message);
};

#endif // STOPRESPONSEHANDLER_H
