#ifndef CONTROLOFFMESSAGE_H
#define CONTROLOFFMESSAGE_H

#include "IOMessage.h"

class ControlOffMessage : public IOMessage
{
public:
    ControlOffMessage();
    ~ControlOffMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

};

#endif // CONTROLOFFMESSAGE_H
