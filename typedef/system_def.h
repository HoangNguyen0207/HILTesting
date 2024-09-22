#ifndef SYSTEM_DEF_H
#define SYSTEM_DEF_H

#include <QMetaType>

typedef struct {
    double mAmplitude[6];
    double mFrequency[6];
    double mPositionStep[6];
    double mLowerPosition[6];
    double mUpperPosition[6];
    double mPositionRepeat;
    bool mIsLinear;
} ControlParamType;

typedef struct {
    double mSpecification[6];
} SpecificationParamType;

//typedef struct {
//    double MaxRotationAngle;
//    double MaxLinearHorPosition;
//    double MaxRotationVelocity;
//    double MinRotationVelocity;
//    double MaxLinearHorVelocity;
//    double MaxLinearVerVelocity;
//    double AngleResolution;
//    double MaxRotationAcc;
//    double MaxLinearAcc;
//    double RotationErrPosition;
//    double RotationErrRepeatability;
//    double Bandwidth;
//    double HardwareDelay;
//} FmsSystemConfig;

//typedef struct {
//    double MaxLinearXPos;
//    double MaxLinearYPos;
//    double MaxLinearVelocity;
//    double MinLinearVelocity;
//    double MaxLinearAcc;
//    double LinearErrPosition;
//    double LinearErrRepeatability;
//    double Bandwidth;
//    double HardwareDelay;
//    double MaxRotationPos;
//    double MaxRotationVelocity;
//} TmsSystemConfig;

//typedef struct {
//    double HeightSMR;
//    double TmsToRotationAxisDistance;
//    double FmsMaxVelRotationTestAmp;
//    double FmsMaxVelRotationTestFreq;
//    double FmsMaxVelLinearHorTestAmp;
//    double FmsMaxVelLinearHorTestFreq;
//    double FmsMaxVelLinearVerTestAmp;
//    double FmsMaxVelLinearVerTestFreq;
//    double FmsBandwidthRotationTestAmp;
//    double FmmsBandwidthLinearTestAmp;
//    double FmsPositionTestAngle;
//    double FmsRepeatabilityTestAngle;
//    double FmsMinVelTestAngle;
//    double TmsMaxVelLinearTestAmp;
//    double TmsMaxVelLinearTestFreq;
//    double TmsMaxVelRotationTestAmp;
//    double TmsMaxVelRotationTestFreq;
//    double TmsBandwidthTestAmp;
//    double TmsPositionTestDist;
//    double TmsRepeatabilityTestDist;
//    std::vector<double> FmsRollCenter;
//    std::vector<double> FmsPitchCenter;
//    std::vector<double> FmsYawCenter;
//    std::vector<double> TmsGymbalXCenter;
//    std::vector<double> TmsGymbalYCenter;
//} MeasureSetupConfig;

class DEVICE
{
    Q_GADGET
public:
    enum class TYPE {
        FMS,
        TMS,
        CLOSED_LOOP
    };
    Q_ENUMS(TYPE)

    enum class FMS_AXIS
    {
        ROLL,
        PITCH,
        YAW,
        X,
        Y,
        Z
    };
    Q_ENUMS(FMS_AXIS)

    enum class TMS_AXIS
    {
        X,
        Y,
        GYMBAL_X,
        GYMBAL_Y
    };
    Q_ENUMS(TMS_AXIS)
};

class TEST_DEFINE {
    Q_GADGET
public:
    enum class TEST_PROCESS
    {
        POSITION,
        REPEATABILITY,
        RESOLUTION,
        MIN_VEL,
        MAX_VEL,
        MAX_ACC,
        BANDWIDTH,
        DELAY,
        CONTROL,
        CLOSED_LOOP,
        LOAD,
        MAX_POS,
        REALTIME_CONTROL,
        NONE
    };
    Q_ENUMS(TEST_PROCESS)

    enum class STATE
    {
        IDLE,
        RUNNING,
        PAUSE
    };
    Q_ENUMS(STATE)
};

enum CONFIG_FILE_TYPE {
    FMS_CFG,
    TMS_CFG,
    MEASUREMENT_CFG
};

typedef struct
{
    double frequency;
    double amplitude;
    std::vector<double> position;
    double gain;
} TestProcessBandwidthData;

typedef struct {
    double cmdPosition;
    double measurePosition;
    double x;
    double y;
    double z;
    double err;
} TestProcessPositionData;

#define TEST_PROCESS_ERROR                  -5
#define TEST_PROCESS_PAUSE                  -4
#define TEST_PROCESS_IDLE                   -3
#define TEST_PROCESS_FAIL                   -1
#define TEST_PROCESS_RUNNING                0
#define TEST_PROCESS_PASS                   1
#define TEST_PROCESS_WAIT_INPUT_CENTER      2
#define TEST_PROCESS_WAIT_INPUT_0           3

#endif // SYSTEM_DEF_H
