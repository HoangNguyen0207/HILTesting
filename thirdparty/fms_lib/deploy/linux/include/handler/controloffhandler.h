#ifndef CONTROLOFFHANDLER_H
#define CONTROLOFFHANDLER_H

#include "basehandler.h"

class ControlOffHandler : public BaseHandler
{
public:
    ControlOffHandler();
    void handle(IOMessage *message) override;
};

#endif // CONTROLOFFHANDLER_H
