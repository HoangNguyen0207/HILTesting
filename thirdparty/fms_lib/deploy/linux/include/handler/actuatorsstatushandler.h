#ifndef ACTUATORSSTATUSHANDLER_H
#define ACTUATORSSTATUSHANDLER_H

#include "basehandler.h"

class ActuatorsStatusHandler : public BaseHandler
{
public:
    ActuatorsStatusHandler();
    void handle(IOMessage *message) override;
};

#endif // ACTUATORSSTATUSHANDLER_H
