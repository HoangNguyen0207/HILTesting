#ifndef RESETRESPONSEHANDLER_H
#define RESETRESPONSEHANDLER_H

#include "basehandler.h"

class ResetResponseHandler : public BaseHandler
{
public:
    ResetResponseHandler();

    // BaseHandler interface
public:
    void handle(IOMessage *message);
};

#endif // RESETRESPONSEHANDLER_H
