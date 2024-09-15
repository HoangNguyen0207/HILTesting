#ifndef MOVEABSRESPONSEMESSAGE_H
#define MOVEABSRESPONSEMESSAGE_H

#include "IOMessage.h"

class MoveAbsResponseMessage : public IOMessage
{
public:
    MoveAbsResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // MOVEABSRESPONSEMESSAGE_H
