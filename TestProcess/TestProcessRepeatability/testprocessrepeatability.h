#ifndef TESTPROCESSREPEATABILITY_H
#define TESTPROCESSREPEATABILITY_H

#include "../testprocess.h"

class TestProcessRepeatability : public TestProcess
{
public:
    TestProcessRepeatability(DEVICE::TYPE device, int axis, ControlParamType control_param, SpecificationParamType spec);

    virtual int run() override;

private:
    int mIndex {0};

    std::vector<TestProcessPositionData> mData;
    std::vector<double> mRefCoordinate;
};

#endif // TESTPROCESSREPEATABILITY_H
