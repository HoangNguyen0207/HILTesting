#ifndef KINEMATICCONTROLLER_H
#define KINEMATICCONTROLLER_H

#include <QObject>

#include "kinematic/full_limmit_motion_GEN.h"
#include "kinematic/inverse_kinematic_GEN.h"

class KinematicController : public QObject
{
    Q_OBJECT
public:
    KinematicController(QObject *parent = nullptr);

    static KinematicController* Instance();
    void initialize();
    double* stepKinematic(double value_MP[6]);

private:
    static KinematicController *m_KinematicControllerr;
    double outActuatorInverse[6]={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    double *outActuator = NULL;
    double homingZero[6] ={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    double* gethomeZero=NULL;
    double *outCmdActuatorLimit = NULL;
    double inpuDirectData[6] ={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};

    full_limmit_motion_GENModelClass limitMotion;
    inverse_kinematic_GEN inverseKinematic, inverseKinematic1;
};

#endif // KINEMATICCONTROLLER_H
