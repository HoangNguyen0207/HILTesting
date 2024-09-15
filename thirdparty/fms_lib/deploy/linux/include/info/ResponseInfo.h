#ifndef RESPONSEINFO_H
#define RESPONSEINFO_H

#include "constant.h"
#include <QString>

struct ResponseInfo
{
    MSG_TYPE type;
    short state;
    QString response;
};

#endif // RESPONSEINFO_H
