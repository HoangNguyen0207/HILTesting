#pragma once
#include <QString>
#include <QStringLiteral>

#define CMD_ENABLE                                  "ENABLE"
#define CMD_DISABLE                                 "DISABLE"
#define CMD_RESET                                   "RESET"
#define CMD_CONTROL_ON                              "CONTROLON"
#define CMD_CONTROL_OFF                             "CONTROLOFF"
#define CMD_POWER_OFF                               "POWEROFF"
#define CMD_STOP                                    "STOP"
#define CMD_HOMING                                  "HOMING"
#define CMD_MOVE_OFF                                "MOVEOFF"

#define CMD_MOVE_ABS(tx,ty,tz,rx,ry,rz)             "MOVE#ABS" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_VELOCITY(tx,ty,tz,rx,ry,rz)             "CFG#VELOCITY" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_ACC(tx,ty,tz,rx,ry,rz)                  "CFG#ACC" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_HOME_OFFSET(tx,ty,tz,rx,ry,rz)          "CFG#HOME#OFFSET" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_LIM_WS(tx,ty,tz,rx,ry,rz)               "CFG#LIM#WS" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_LIM_VELOCITY(tx,ty,tz,rx,ry,rz)         "CFG#LIM#VELOCITY" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define CFG_LIM_ACC(tx,ty,tz,rx,ry,rz)              "CFG#LIM#ACC" + QString::number(tx) \
                                                    + "," + QString::number(ty) \
                                                    + "," + QString::number(tz) \
                                                    + "," + QString::number(rx) \
                                                    + "," + QString::number(ry) \
                                                    + "," + QString::number(rz)

#define QRY_HEXAPOD                                 "STA#HEXAPOD?"
#define QRY_VELOCITY                                "CFG#VELOCITY?"
#define QRY_ACC                                     "CFG#ACC?"
#define QRY_HOME_OFFSET                             "CFG#HOME#OFFSET?"
#define QRY_LIM_WS                                  "CFG#LIM#WS?"
#define QRY_LIM_VELOCITY                            "CFG#LIM#VELOCITY?"
#define QRY_LIM_ACC                                 "CFG#LIM#ACC?"
