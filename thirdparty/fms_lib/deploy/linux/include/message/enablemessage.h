#pragma once

#include "IOMessage.h"

class EnableMessage : public IOMessage
{
public:
    EnableMessage();
    ~EnableMessage() override;

	int serialToData(char *dest, int length) override;
	int parseFromData(char *mesData, int mesLen) override;

private:

};
