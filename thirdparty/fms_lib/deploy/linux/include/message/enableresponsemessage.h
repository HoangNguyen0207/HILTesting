#ifndef ENABLERESPONSEMESSAGE_H
#define ENABLERESPONSEMESSAGE_H

#include "IOMessage.h"

class EnableResponseMessage : public IOMessage
{
public:
    EnableResponseMessage();
    ~EnableResponseMessage() override;

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;

};

#endif // ENABLERESPONSEMESSAGE_H
