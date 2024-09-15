#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QObject>
#include "ResponseObserver.h"
#include "FmsApi_global.h"
#include "constant.h"
#include "info/ResponseInfo.h"

class FMSAPI_EXPORT InputHandler : public QObject
{
    Q_OBJECT
public:
    explicit InputHandler(QObject *parent = nullptr);

    static InputHandler *Instance();

    void sendEnableResponseMessage(const int& state);
    static void SendEnableResponseMessage(const int& state);
    static void SendDisableResponseMessage(const int& state);
    static void SendControlOnResponseMessage(const int& state);
    static void SendControlOffResponseMessage(const int& state);
    static void SendHomingResponseMessage(const int& state);
    static void SendMoveAbsResponseMessage(const int& state);
    void processResponse(const ResponseInfo &responseInfo);
    void setResponseObserver(QObject* object);
signals:
    void sigResponseResult(ResponseInfo responseInfo);
    void sigSendEnableResponseMessage(const int& state);
    void sigSendDisableResponseMessage(const int& state);
    void sigSendControlOnResponseMessage(const int& state);
    void sigSendControlOffResponseMessage(const int& state);
    void sigSendHomingResponseMessage(const int& state);
    void sigSendMoveAbsResponseMessage(const int& state);
private:
    static InputHandler *instance;

    QList<ResponseObserver *> observers;
    ResponseInfo oldInfo;

};

#endif // INPUTHANDLER_H
