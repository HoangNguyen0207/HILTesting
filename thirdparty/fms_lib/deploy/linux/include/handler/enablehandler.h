#ifndef ENABLEHANDLER_H
#define ENABLEHANDLER_H

#include "basehandler.h"

class EnableHandler : public BaseHandler
{
public:
    EnableHandler();
    void handle(IOMessage *message) override;
};

#endif // ENABLEHANDLER_H
