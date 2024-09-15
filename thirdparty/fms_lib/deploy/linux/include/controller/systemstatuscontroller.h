#ifndef SYSTEMSTATUSCONTROLLER_H
#define SYSTEMSTATUSCONTROLLER_H

#include <QObject>
#include <QMutex>

class SystemStatusController : public QObject
{
    Q_OBJECT
public:
    explicit SystemStatusController(QObject *parent = nullptr);

    static SystemStatusController* Instance();
    int getHomingState() const;
    void setHomingState(int value);

    int getErrorState() const;
    void setErrorState(int value);

    bool getIsMoving();
    void setIsMoving(bool value);

    void handleSystemStatus(int homing, int error);

signals:

private:
    static SystemStatusController *m_SystemStatusController;
    int homingState ;
    int errorState;
    bool isMoving;
    QMutex movingMutex;

};

#endif // SYSTEMSTATUSCONTROLLER_H
