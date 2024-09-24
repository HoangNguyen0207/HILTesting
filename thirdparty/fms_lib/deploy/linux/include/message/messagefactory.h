#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

class IOMessage;
#include "constant.h"
#include "FmsApi_global.h"

class FMSAPI_EXPORT MessageFactory
{
public:
    MessageFactory(void);
    static MessageFactory *getInstance();
    IOMessage *createMessage(uint8 type);

private:
    static MessageFactory *instance;
    ~MessageFactory(void);
};

#endif // MESSAGEFACTORY_H
