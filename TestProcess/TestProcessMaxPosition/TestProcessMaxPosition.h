#ifndef _TESTPROCESSMAXPOSITION_H_
#define _TESTPROCESSMAXPOSITION_H_

#include "../testprocess.h"

class TestProcessMaxPosition : public TestProcess
{
public:
    TestProcessMaxPosition(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);
    ~TestProcessMaxPosition();

    virtual int run() override;

private:
    std::vector<TestProcessPositionData> mData;
    std::vector<double> mRefCoordinate;

    int mIndex;
};

#endif
