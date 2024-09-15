#ifndef POWEROFFHANDLER_H
#define POWEROFFHANDLER_H

#include "basehandler.h"

class PowerOffHandler : public BaseHandler
{
public:
    PowerOffHandler();
    void handle(IOMessage *message) override;
};

#endif // POWEROFFHANDLER_H
