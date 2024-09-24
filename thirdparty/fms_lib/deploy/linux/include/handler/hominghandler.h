#ifndef HOMINGHANDLER_H
#define HOMINGHANDLER_H

#include "basehandler.h"

class HomingHandler : public BaseHandler
{
public:
    HomingHandler();
    void handle(IOMessage *message) override;
};

#endif // HOMINGHANDLER_H
