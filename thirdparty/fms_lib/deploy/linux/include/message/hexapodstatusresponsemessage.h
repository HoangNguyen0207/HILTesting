#ifndef HEXAPODSTATUSRESPONSEMESSAGE_H
#define HEXAPODSTATUSRESPONSEMESSAGE_H

#include "IOMessage.h"

class HexapodStatusResponseMessage : public IOMessage
{
public:
    HexapodStatusResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getO1() const;
    void setO1(const uint32 &value);

    double getO2() const;
    void setO2(double value);

    double getO3() const;
    void setO3(double value);

    double getO4() const;
    void setO4(double value);

    double getO5() const;
    void setO5(double value);

    double getO6() const;
    void setO6(double value);

    double getO7() const;
    void setO7(double value);

    double getO8() const;
    void setO8(double value);

    double getO9() const;
    void setO9(double value);

    double getO10() const;
    void setO10(double value);

    double getO11() const;
    void setO11(double value);

    double getO12() const;
    void setO12(double value);

    double getO13() const;
    void setO13(double value);

    short getState() const;
    void setState(short value);

private:
    short state;
    uint32 o1;
    double o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13;
};

#endif // HEXAPODSTATUSRESPONSEMESSAGE_H
