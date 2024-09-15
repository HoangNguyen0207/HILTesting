#pragma once

#include <QString>
#include <QObject>
#include <typeinfo>

class BaseMessage : public QObject
{
        Q_OBJECT
    public:
        explicit BaseMessage(QObject *parent = nullptr);
        virtual ~BaseMessage();
        int16_t getMessageType() const;
        void setMessageType(const int16_t& type);

    private:
        int16_t mMessageType;
};

