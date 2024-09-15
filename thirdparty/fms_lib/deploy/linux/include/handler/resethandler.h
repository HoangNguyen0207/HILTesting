#ifndef RESETHANDLER_H
#define RESETHANDLER_H

#include "basehandler.h"

class ResetHandler : public BaseHandler
{
public:
    ResetHandler();

    // BaseHandler interface
public:
    void handle(IOMessage *message);
};

#endif // RESETHANDLER_H
