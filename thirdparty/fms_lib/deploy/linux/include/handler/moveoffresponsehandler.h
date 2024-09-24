#ifndef MOVEOFFRESPONSEHANDLER_H
#define MOVEOFFRESPONSEHANDLER_H

#include "basehandler.h"

class MoveOffResponseHandler : public BaseHandler
{
public:
    MoveOffResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // MOVEOFFRESPONSEHANDLER_H
