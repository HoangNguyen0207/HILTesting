#ifndef CONTROLONMESSAGE_H
#define CONTROLONMESSAGE_H

#include "IOMessage.h"

class ControlOnMessage : public IOMessage
{
public:
    ControlOnMessage();
    ~ControlOnMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    double getTx() const;
    void setTx(double value);

    double getTy() const;
    void setTy(double value);

    double getTz() const;
    void setTz(double value);

    double getRx() const;
    void setRx(double value);

    double getRy() const;
    void setRy(double value);

    double getRz() const;
    void setRz(double value);

private:
    double tx, ty, tz, rx, ry, rz;
};

#endif // CONTROLONMESSAGE_H
