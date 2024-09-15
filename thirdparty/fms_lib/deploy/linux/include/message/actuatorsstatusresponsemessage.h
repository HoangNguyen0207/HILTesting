#ifndef ACTUATORSSTATUSRESPONSEMESSAGE_H
#define ACTUATORSSTATUSRESPONSEMESSAGE_H

#include "IOMessage.h"

#include <QList>

class ActuatorsStatusResponseMessage : public IOMessage
{
public:
    ActuatorsStatusResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    int getO1() const;
    void setO1(int newO1);

    int getO2() const;
    void setO2(int newO2);

    const QList<int> &getStatus() const;
    void setStatus(const QList<int> &newStatus);

    const QList<double> &getPosition() const;
    void setPosition(const QList<double> &newPosition);

    short getState() const;
    void setState(short value);

private:
    short state;
    int o1;
    QList<int> status;
    QList<double> position;
};

#endif // ACTUATORSSTATUSRESPONSEMESSAGE_H
