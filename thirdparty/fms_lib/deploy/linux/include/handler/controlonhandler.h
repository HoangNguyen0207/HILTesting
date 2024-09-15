#ifndef CONTROLONHANDLER_H
#define CONTROLONHANDLER_H

#include "basehandler.h"

class ControlOnHandler : public BaseHandler
{
public:
    ControlOnHandler();

    void handle(IOMessage *message) override;
};

#endif // CONTROLONHANDLER_H
