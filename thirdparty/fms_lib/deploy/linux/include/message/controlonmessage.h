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
};

#endif // CONTROLONMESSAGE_H
