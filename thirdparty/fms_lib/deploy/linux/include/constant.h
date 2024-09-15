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
    AXIS_HOMING = 10,
    AXIS_CONTROLON = 11,
    AXIS_CONTROLOFF = 12,
    HEXAPOD_STATUS = 13,
    ACTUATORS_STATUS = 14,
    CFG_SPD_SET = 15,
    CFG_SPD_GET = 16,
    CFG_ACC_SET = 17,
    CFG_ACC_GET = 18,
    CFG_LIM_WS_SET = 19,
    CFG_LIM_WS_GET = 20,
    CFG_LIM_SPD_SET = 21,
    CFG_LIM_SPD_GET = 22,
    CFG_LIM_ACC_SET = 23,
    CFG_LIM_ACC_GET = 24,
    MOVEOFF = 25,
    SYSTEM_STATUS = 26,


    ENABLE_RESPONSE = 101,
    DISABLE_RESPONSE,
    RESET_RESPONSE,
    CONTROLON_RESPONSE,
    CONTROLOFF_RESPONSE,
    POWEROFF_RESPONSE,
    STOP_RESPONSE,
    HOMING_RESPONSE,
    MOVE_ABS_RESPONSE,
    AXIS_HOMING_RESPONSE,
    AXIS_CONTROLON_RESPONSE,
    AXIS_CONTROLOFF_RESPONSE,
    HEXAPOD_STATUS_RESPONSE,
    ACTUATORS_STATUS_RESPONSE,
    CFG_SPD_SET_RESPONSE,
    CFG_SPD_GET_RESPONSE,
    CFG_ACC_SET_RESPONSE,
    CFG_ACC_GET_RESPONSE,
    CFG_LIM_WS_SET_RESPONSE,
    CFG_LIM_WS_GET_RESPONSE,
    CFG_LIM_SPD_SET_RESPONSE,
    CFG_LIM_SPD_GET_RESPONSE,
    CFG_LIM_ACC_SET_RESPONSE,
    CFG_LIM_ACC_GET_RESPONSE,
    MOVEOFF_RESPONSE,
};

const QList<int> onePriorityCommand = {MSG_TYPE::STOP, MSG_TYPE::POWEROFF};
const QList<int> notQueueCommand = {MSG_TYPE::MOVE_ABS};

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

