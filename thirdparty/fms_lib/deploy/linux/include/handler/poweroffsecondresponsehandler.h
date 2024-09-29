#ifndef POWEROFFSECONDRESPONSEHANDLER_H
#define POWEROFFSECONDRESPONSEHANDLER_H

#include "basehandler.h"

class PowerOffSecondResponseHandler : public BaseHandler
{
public:
    PowerOffSecondResponseHandler();
    void handle(IOMessage *message) override;
};

#endif // POWEROFFSECONDRESPONSEHANDLER_H
