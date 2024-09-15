#ifndef HOMINGMESSAGE_H
#define HOMINGMESSAGE_H

#include "IOMessage.h"

class HomingMessage : public IOMessage
{
public:
    HomingMessage();


    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // HOMINGMESSAGE_H
