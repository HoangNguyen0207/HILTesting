#ifndef DISABLEHANDLER_H
#define DISABLEHANDLER_H

#include "basehandler.h"

class DisableHandler : public BaseHandler
{
public:
    DisableHandler();
    void handle(IOMessage *message) override;
};

#endif // DISABLEHANDLER_H
