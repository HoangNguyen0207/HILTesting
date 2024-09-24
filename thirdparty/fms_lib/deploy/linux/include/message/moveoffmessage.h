#ifndef MOVEOFFMESSAGE_H
#define MOVEOFFMESSAGE_H

#include "IOMessage.h"

class MoveOffMessage : public IOMessage
{
public:
    MoveOffMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // MOVEOFFMESSAGE_H
