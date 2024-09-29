#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>
#include <QMap>
#include <QList>

enum MSG_TYPE
{
    NONE = -1,
    ENABLE = 1,
    DISABLE = 2,
    RESET = 3,
    CONTROLON = 4,
    CONTROLOFF = 5,
    POWEROFF = 6,
    STOP = 7,
    HOMING = 8,
    MOVE_ABS = 9,

//    AXIS_HOMING = 10, //bo
//    AXIS_CONTROLON = 11, //bo
//    AXIS_CONTROLOFF = 12, //bo
    HEXAPOD_STATUS = 13,
//    ACTUATORS_STATUS = 14,

    CFG_VELOCITY_SET = 15,
    CFG_VELOCITY_GET = 16,
    CFG_ACC_SET = 17,
    CFG_ACC_GET = 18,

    CFG_LIM_WS_SET = 19,
    CFG_LIM_WS_GET = 20,

    CFG_LIM_VELOCITY_SET = 21,
    CFG_LIM_VELOCITY_GET = 22,
    CFG_LIM_ACC_SET = 23,
    CFG_LIM_ACC_GET = 24,

    MOVEOFF = 25,
    SYSTEM_STATUS = 26,

    CFG_MAX_AXES_SET = 33,
    CFG_MAX_AXES_GET = 34,
    CFG_MIN_AXES_SET = 35,
    CFG_MIN_AXES_GET = 36,
//    POWER_OFF_SECOND = 37,
    CFG_HOME_OFFSET_SET = 37,
    CFG_HOME_OFFSET_GET = 38,


    ENABLE_RESPONSE = 101,
    DISABLE_RESPONSE = 102,
    RESET_RESPONSE = 103,
    CONTROLON_RESPONSE = 104,
    CONTROLOFF_RESPONSE = 105,
    POWEROFF_RESPONSE = 106,
    STOP_RESPONSE = 107,
    HOMING_RESPONSE = 108,
    MOVE_ABS_RESPONSE = 109,

//    AXIS_HOMING_RESPONSE = 110,
//    AXIS_CONTROLON_RESPONSE = 111,
//    AXIS_CONTROLOFF_RESPONSE = 112,
    HEXAPOD_STATUS_RESPONSE = 113,
//    ACTUATORS_STATUS_RESPONSE = 114,

    CFG_SPD_SET_RESPONSE = 115,
    CFG_SPD_GET_RESPONSE = 116,
    CFG_ACC_SET_RESPONSE = 117,
    CFG_ACC_GET_RESPONSE = 118,

    CFG_LIM_WS_SET_RESPONSE = 119,
    CFG_LIM_WS_GET_RESPONSE = 120,

    CFG_LIM_SPD_SET_RESPONSE = 121,
    CFG_LIM_SPD_GET_RESPONSE = 122,
    CFG_LIM_ACC_SET_RESPONSE = 123,
    CFG_LIM_ACC_GET_RESPONSE = 124,

    MOVEOFF_RESPONSE = 125,
//    POWER_OFF_SECOND_RESPONSE = 126,
};

const QList<int> onePriorityCommand = {MSG_TYPE::STOP, MSG_TYPE::POWEROFF};
const QList<int> notQueueCommand = {MSG_TYPE::MOVE_ABS};
const QList<int> ableMovingCommand = {MSG_TYPE::STOP, MSG_TYPE::POWEROFF, MSG_TYPE::MOVE_ABS, HEXAPOD_STATUS};

enum MSG_RETURN
{
    FAIL = -1,
    SUCCESS = 0
};

const int INT_FAIL = -1;
const int INT_SUCCESS = 0;

typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
//typedef signed char int8;
typedef char int8; //tienpv13 changed this due to dlib
template<class T> inline T _min(T a, T b) { return (a > b) ? b : a; }
template<class T> inline T _max(T a, T b) { return (a < b) ? b : a; }

const QString regularCommand = "^[A-Z]+#*[A-Z]*\\?*";
const QString regularCommandTwo = "^[A-Z]+(#[A-Z]+){2}\\?*";
const QString validStartComd = "^[A-Z]+#*[A-Z]*\\?*";
const QString regularCommandAndParam = "^[A-Z]+#*[A-Z]*\\?*(-?[0-9]+.*[0-9]*)*,*";

enum COMMAND_ERROR
{
    VALID_SYNTAX = 0,
    SYNTAX_ERROR = -1,
    UnknownCommandWord = -6,
};

const QMap<int, QString> mapErrors = {{-1, "SYNTAX_ERROR"}};

#endif // CONSTANT_H

