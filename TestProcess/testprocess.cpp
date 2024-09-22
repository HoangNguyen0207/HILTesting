#include "testprocess.h"


TestProcess::TestProcess(DEVICE::TYPE device, ControlParamType control_param, SpecificationParamType spec)
    : mCtrlParam(control_param), mSpec(spec), mDevice(device)
{
    mPause = false;
    mResult = TEST_PROCESS_RUNNING;
    mStep = TEST_STEP::TESTSTEP_0;
    mSmrCoordinate.clear();
}

TestProcess::TestProcess(DEVICE::TYPE device, int axis, ControlParamType control_param, SpecificationParamType spec)
    : mCtrlParam(control_param), mSpec(spec), mDevice(device), mAxis(axis)
{
    mPause = false;
    mResult = TEST_PROCESS_RUNNING;
    mStep = TEST_STEP::TESTSTEP_0;
    mSmrCoordinate.clear();
}

void TestProcess::abort()
{
    mPause = true;
    mResult = TEST_PROCESS_IDLE;
}

void TestProcess::pause()
{
    mPause = true;
}

void TestProcess::resume()
{
    mPause = false;
}

void TestProcess::error(){
    mPause = true;
    mResult = TEST_PROCESS_ERROR;
}

void TestProcess::updateCoordinate(std::vector<double>& position)
{
    mSmrCoordinate = position;
}

int TestProcess::getCount(double sec)
{
    return static_cast<int>((sec * 1000) / TEST_STEP_TIME_INTERVAL);
}

void TestProcess::setCenterCoordination(std::vector<double>& center)
{
    mCenterCoordinate = center;
}

void TestProcess::homing(DEVICE::TYPE device)
{

}
void TestProcess::moveAbs(DEVICE::TYPE device, int axis, double position)
{

}
void TestProcess::moveSine(DEVICE::TYPE device, int axis, double amp, double freq)
{

}
std::vector<double> TestProcess::getPosition(DEVICE::TYPE device)
{

}

bool TestProcess::isHoming(DEVICE::TYPE device)
{

}

void TestProcess::setPlotData(bool state)
{

}

void TestProcess::configDeviceSpec(DEVICE::TYPE device, double maxVel, double maxAcc)
{

}
