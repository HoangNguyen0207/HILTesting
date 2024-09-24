#ifndef TESTPROCESS_H
#define TESTPROCESS_H

#include <QObject>
#include "typedef/system_def.h"

#define MAX_DIFF_ANGLE_VALUE        0.001
#define TEST_STEP_TIME_INTERVAL     2               //msec
#define TEST_STEP_MAX_COUNT         (5000)         //one step is 2ms --> count for 10sec if stuck in one step

enum TEST_STEP {
    TESTSTEP_0, TESTSTEP_1,TESTSTEP_2, TESTSTEP_3,
    TESTSTEP_4, TESTSTEP_5,TESTSTEP_6, TESTSTEP_7,
    TESTSTEP_8, TESTSTEP_9,TESTSTEP_10, TESTSTEP_11,
    TESTSTEP_FINISH
};

class TestProcess
{
public:
    TestProcess(DEVICE::TYPE device, ControlParamType control_param, SpecificationParamType spec);
    TestProcess(DEVICE::TYPE device, int axis, ControlParamType control_param, SpecificationParamType spec);

    virtual ~TestProcess() = default;
    virtual int run() = 0;
    void abort();
    void pause();
    void resume();
    void error();

    void updateCoordinate(std::vector<double>& position);
    void setCenterCoordination(std::vector<double>& center);

protected:
    ControlParamType mCtrlParam;
    SpecificationParamType mSpec;

    DEVICE::TYPE mDevice;
    int mAxis;

    enum TEST_STEP mStep {TEST_STEP::TESTSTEP_FINISH};
    int mStepCount {0};
    bool mPause {true};
    int mResult {TEST_PROCESS_IDLE};

    std::vector<double> mSmrCoordinate;
    std::vector<double> mCenterCoordinate;

protected:
    void homing(DEVICE::TYPE device);
    void moveAbs(DEVICE::TYPE device, int axis, double position);
    void moveSine(DEVICE::TYPE device, int axis, double amp, double freq);
    std::vector<double> getPosition(DEVICE::TYPE device);
    bool isHoming(DEVICE::TYPE device);
    void configDeviceSpec(DEVICE::TYPE device, double maxVel, double maxAcc);

    void setPlotData(bool state);

    int getCount(double sec);
};

#endif // TESTPROCESS_H
