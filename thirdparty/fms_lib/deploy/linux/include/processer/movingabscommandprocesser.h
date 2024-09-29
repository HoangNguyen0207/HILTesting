#ifndef MOVINGABSCOMMANDPROCESSER_H
#define MOVINGABSCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include "info/moveabsinfo.h"

class MoveAbsMessage;

#include <QThread>
#include <QObject>
#include "info/moveabsinfo.h"

class MovingAbsCommandProcesser : public QObject,  public CommandProcesserInterface
{
    Q_OBJECT
public:
    MovingAbsCommandProcesser();

signals:
    void sigInitKinematic();
    void sigSetInputKinematic(double tx, double ty, double tz, double rx, double ry, double rz);
    void sigStartStepKinematic();
    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

    MoveAbsInfo *getInfo() const;
    void setInfo(MoveAbsInfo *value);

private:
    QThread preProcesserThread;
    MoveAbsInfo *info = nullptr;

};

#endif // MOVINGABSCOMMANDPROCESSER_H
