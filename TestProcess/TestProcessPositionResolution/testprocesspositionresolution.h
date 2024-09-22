#ifndef TESTPROCESSPOSITIONRESOLUTION_H
#define TESTPROCESSPOSITIONRESOLUTION_H

#include "../testprocess.h"

class TestProcessPositionResolution : public TestProcess
{
public:
    TestProcessPositionResolution(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);

    virtual int run() override;

private:
    std::vector<double> mRefCoordinate;
    std::vector<TestProcessPositionData> mData;
    int mIndex {0};
};

#endif // TESTPROCESSPOSITIONRESOLUTION_H
