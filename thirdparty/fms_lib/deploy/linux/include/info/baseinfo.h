#ifndef BASEINFO_H
#define BASEINFO_H

#include "constant.h"
#include <QString>

class BaseInfo
{
public:
    BaseInfo();

    uint8 getPriority() const;
    void setPriority(const uint8 &value);

    QString getCmd() const;
    void setCmd(const QString &value);

protected:
    uint8 priority;
    QString cmd;
};

#endif // BASEINFO_H
