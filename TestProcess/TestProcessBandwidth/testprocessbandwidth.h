#ifndef TESTPROCESSBANDWIDTH_H
#define TESTPROCESSBANDWIDTH_H

#include "../testprocess.h"

class TestProcessBandwidth : public TestProcess
{
public:
    TestProcessBandwidth(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);

    virtual int run() override;

private:
    int mIndex {0};
    std::vector<TestProcessBandwidthData> mData;

    double mMaxVelocity;
    double mMaxAcceleration;
};

#endif // TESTPROCESSBANDWIDTH_H
