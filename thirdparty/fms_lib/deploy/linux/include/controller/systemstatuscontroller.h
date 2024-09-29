#ifndef SYSTEMSTATUSCONTROLLER_H
#define SYSTEMSTATUSCONTROLLER_H

#include <QObject>
#include <QMutex>
#include "message/systemstatusmessage.h"
#include "message/hexapodstatusresponsemessage.h"

class SystemStatusController : public QObject
{
    Q_OBJECT
public:
    explicit SystemStatusController(QObject *parent = nullptr);

    static SystemStatusController* Instance();

    bool getIsMoving();
    void setIsMoving(bool value);

    void handleSystemStatus(uint8 homing, uint8 error);

    void handleSystemStatus(SystemStatusMessage* messaage);
    void handleSystemStatus(HexapodStatusResponseMessage* messaage);

    QString getHexapodStatus();

    bool getIsMovable() const;
    void setIsMovable(bool value);

    uint8 getHomingState() const;
    void setHomingState(const uint8 &value);

    uint8 getErrorState() const;
    void setErrorState(const uint8 &value);

signals:

private:
    static SystemStatusController *m_SystemStatusController;
    uint8 homingState ;
    uint8 errorState;
    bool isMoving;
    bool isMovable;
    QString statusStr;
    QMutex movingMutex;

};

#endif // SYSTEMSTATUSCONTROLLER_H
