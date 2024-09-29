#ifndef POWEROFFSECONDMESSAGE_H
#define POWEROFFSECONDMESSAGE_H

#include "IOMessage.h"

class PowerOffSecondMessage : public IOMessage
{
public:
    PowerOffSecondMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // POWEROFFSECONDMESSAGE_H
