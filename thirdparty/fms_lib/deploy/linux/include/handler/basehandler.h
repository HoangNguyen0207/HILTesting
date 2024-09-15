#ifndef BASEHANDLER_H
#define BASEHANDLER_H

#include "FmsApi_global.h"
#include "constant.h"
#include <QObject>
class IOMessage;

class FMSAPI_EXPORT BaseHandler: public QObject
{
public:
    BaseHandler();
    virtual void handle(IOMessage *message) = 0;
    ~BaseHandler(void);
};

#endif // BASEHANDLER_H
