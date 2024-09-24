#ifndef ENABLERESPONSEHANDLER_H
#define ENABLERESPONSEHANDLER_H

#include "basehandler.h"

class EnableResponseHandler  : public BaseHandler
{
public:
    EnableResponseHandler();

    // BaseHandler interface
public:
    void handle(IOMessage *message);
};

#endif // ENABLERESPONSEHANDLER_H
