#ifndef STOPHANDLER_H
#define STOPHANDLER_H

#include "basehandler.h"

class StopHandler : public BaseHandler
{
public:
    StopHandler();
    void handle(IOMessage *message) override;
};

#endif // STOPHANDLER_H
