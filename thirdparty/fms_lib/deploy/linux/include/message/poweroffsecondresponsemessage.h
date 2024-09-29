#ifndef POWEROFFSECONDRESPONSEMESSAGE_H
#define POWEROFFSECONDRESPONSEMESSAGE_H

#include "IOMessage.h"

class PowerOffSecondResponseMessage : public IOMessage
{
public:
    PowerOffSecondResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // POWEROFFSECONDRESPONSEMESSAGE_H
