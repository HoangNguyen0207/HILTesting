#ifndef HOMINGRESPONSEHANDLER_H
#define HOMINGRESPONSEHANDLER_H

#include "basehandler.h"

class HomingResponseHandler : public BaseHandler
{
public:
    HomingResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // HOMINGRESPONSEHANDLER_H
