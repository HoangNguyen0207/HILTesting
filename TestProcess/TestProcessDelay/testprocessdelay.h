#ifndef TESTPROCESSDELAY_H
#define TESTPROCESSDELAY_H

#include "../testprocess.h"

class TestProcessDelay : public TestProcess
{
public:
    TestProcessDelay(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);

    virtual int run() override;

private:
    std::vector<double> mControlPosition;
    std::vector<double> mFeedbackPosition;
    int mIndex {0};
};

#endif // TESTPROCESSDELAY_H
