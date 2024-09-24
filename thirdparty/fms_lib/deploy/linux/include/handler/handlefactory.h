#ifndef HANDLEFACTORY_H
#define HANDLEFACTORY_H

#include "FmsApi_global.h"
#include "constant.h"

class BaseHandler;

class FMSAPI_EXPORT HandleFactory
{
public:
    HandleFactory();
    static HandleFactory *getInstance();
    BaseHandler *createHandler(uint8 type);
private:
    ~HandleFactory(void);
    static HandleFactory *instance;
};

#endif // HANDLEFACTORY_H
