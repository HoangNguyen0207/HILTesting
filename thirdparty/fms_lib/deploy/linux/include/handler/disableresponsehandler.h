#ifndef DISABLERESPONSEHANDLER_H
#define DISABLERESPONSEHANDLER_H

#include "basehandler.h"

class DisableResponseHandler : public BaseHandler
{
public:
    DisableResponseHandler();

    void handle(IOMessage *message) override;
};

#endif // DISABLERESPONSEHANDLER_H
