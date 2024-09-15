#ifndef CONTROLONRESPONSEMESSAGE_H
#define CONTROLONRESPONSEMESSAGE_H

#include "IOMessage.h"

class ControlOnResponseMessage : public IOMessage
{
public:
    ControlOnResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CONTROLONRESPONSEMESSAGE_H
