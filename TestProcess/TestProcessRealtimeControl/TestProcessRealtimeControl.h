#ifndef _TESTPROCESSREALTIMECONTROL_H_
#define _TESTPROCESSREALTIMECONTROL_H_

#include "../testprocess.h"

class TestProcessRealtimeControl : public TestProcess
{
public:
    TestProcessRealtimeControl(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec);
    ~TestProcessRealtimeControl();

    virtual int run() override;

private:
    std::vector<double> mPosition[3];
    std::vector<double> mCtrlPosition[3];
    int mMaxAxis;
    int mSendCount;
};

#endif

