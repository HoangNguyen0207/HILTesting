#include "basemessage.h"

BaseMessage::BaseMessage(QObject *parent) : QObject(parent)
{

}

BaseMessage::~BaseMessage()
{

}

int16_t BaseMessage::getMessageType() const
{
    return mMessageType;
}

void BaseMessage::setMessageType(const int16_t &type)
{
    this->mMessageType = type;
}
