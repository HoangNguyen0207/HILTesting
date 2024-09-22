#ifndef TESTPROCESSPOSITION_H
#define TESTPROCESSPOSITION_H

#include "../testprocess.h"

class TestProcessPosition : public TestProcess
{
public:
    TestProcessPosition(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);

    virtual int run() override;

private:
    int mIndex {0};
    std::vector<TestProcessPositionData> mData;
    std::vector<double> mRefCoordinate;
};

#endif // TESTPROCESSPOSITION_H
