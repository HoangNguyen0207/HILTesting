#ifndef MOVEOFFRESPONSEMESSAGE_H
#define MOVEOFFRESPONSEMESSAGE_H

#include "IOMessage.h"

class MoveOffResponseMessage : public IOMessage
{
public:
    MoveOffResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // MOVEOFFRESPONSEMESSAGE_H
