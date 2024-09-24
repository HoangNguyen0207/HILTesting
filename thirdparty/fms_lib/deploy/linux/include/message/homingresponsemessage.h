#ifndef HOMINGRESPONSEMESSAGE_H
#define HOMINGRESPONSEMESSAGE_H

#include "IOMessage.h"

class HomingResponseMessage : public IOMessage
{
public:
    HomingResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // HOMINGRESPONSEMESSAGE_H
