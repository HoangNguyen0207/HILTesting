#ifndef KINEMATICCONTROLLER_H
#define KINEMATICCONTROLLER_H

#include <QObject>

#include "kinematic/process_motion.h"
#include "kinematic/process_inv.h"
#include <QElapsedTimer>
#include "network/udpcontroller.h"
#include "info/moveabsinfo.h"

class KinematicController : public QObject
{
    Q_OBJECT
public:
    KinematicController(QObject *parent = nullptr);

    static KinematicController* Instance();

    void setCfgAcc(const double& p1, const double& p2,
                   const double& p3, const double& p4,
                   const double& p5, const double& p6);
    QString getCfgAcc();

    void setCfgSpd(const double& p1, const double& p2,
                   const double& p3, const double& p4,
                   const double& p5, const double& p6);
    QString getCfgSpd();

    void setCfgMaxAxes(const double& p1, const double& p2,
                   const double& p3, const double& p4,
                   const double& p5, const double& p6);
    QString getCfgMaxAxes();

    void setCfgMinAxes(const double& p1, const double& p2,
                   const double& p3, const double& p4,
                   const double& p5, const double& p6);
    QString getCfgMinAxes();

    void setInfo(MoveAbsInfo *value);

    double *getinputDirectData();

public slots:

    void onInitialize();
    void onStepKinematic();


private:
    void sendMoveAbsMessage();
    void onSetInputDirectData(double tx, double ty, double tz, double rx, double ry, double rz);

private:
    static KinematicController *m_KinematicControllerr;
    double outActuatorInverse[6]={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    double *outActuator = NULL;
    double homingZero[6] ={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    double* gethomeZero=NULL;
    double *outCmdActuatorLimit = NULL;
    double inputDirectData[6] ={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    double inputKinematic[6] = {0, 0, 0, 0, 0, 0};

    ProcessMotionClass limitMotion;
    ProcessInv inverseKinematic, inverseKinematic1;
    const double PI = 3.14159265358979;
    const double DegtoRad = PI/180;
    QElapsedTimer timer;
    UDPController *udpController = nullptr;
    MoveAbsInfo *info = nullptr;

};

#endif // KINEMATICCONTROLLER_H
