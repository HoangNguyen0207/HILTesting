#ifndef HEXAPODSTATUSRESPONSEMESSAGE_H
#define HEXAPODSTATUSRESPONSEMESSAGE_H

#include "IOMessage.h"

class HexapodStatusResponseMessage : public IOMessage
{
public:
    HexapodStatusResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint8 getHoming() const;
    void setHoming(const uint8 &value);

    uint8 getMoveOff() const;
    void setMoveOff(const uint8 &value);

    uint8 getPowerOn() const;
    void setPowerOn(const uint8 &value);

    uint8 getErrorSystem() const;
    void setErrorSystem(const uint8 &value);

    uint8 getStop() const;
    void setStop(const uint8 &value);

    uint8 getReady() const;
    void setReady(const uint8 &value);

    uint8 getMovingAbsMode() const;
    void setMovingAbsMode(const uint8 &value);

    uint8 getLimitJoint() const;
    void setLimitJoint(const uint8 &value);

    uint8 getLimitWorkspace() const;
    void setLimitWorkspace(const uint8 &value);

    uint8 getLimitSwitchSensor() const;
    void setLimitSwitchSensor(const uint8 &value);

    uint8 getBrakeModule() const;
    void setBrakeModule(const uint8 &value);

    uint8 getInputEmergency() const;
    void setInputEmergency(const uint8 &value);

    uint8 getInputStart() const;
    void setInputStart(const uint8 &value);

    uint8 getInputReset() const;
    void setInputReset(const uint8 &value);

    uint8 getOutputWait() const;
    void setOutputWait(const uint8 &value);

    uint8 getOutputOk() const;
    void setOutputOk(const uint8 &value);

    uint8 getOutputOn() const;
    void setOutputOn(const uint8 &value);

    uint8 getOutputError() const;
    void setOutputError(const uint8 &value);

    QList<double> getPositionOfActuator() const;
    void setPositionOfActuator(const QList<double> &value);

    QList<double> getVelocityOfActuator() const;
    void setVelocityOfActuator(const QList<double> &value);

    QList<double> getAccOfActuator() const;
    void setAccOfActuator(const QList<double> &value);

    QList<uint8> getErrorActutor() const;
    void setErrorActutor(const QList<uint8> &value);

    QList<uint16> getErrorIdActuators() const;
    void setErrorIdActuators(const QList<uint16> &value);

    QString toString() override;
    template<typename T>
    QString listToString(QList<T> list)
    {
        QString listStr;
        for (int i = 0; i < list.size(); i++)
        {
            listStr += QString::number(list[i]) + ", ";
        }
        return listStr;
    }

    short getState() const;
    void setState(short value);

private:
    short state;
    uint8 homing;
    uint8 moveOff;
    uint8 powerOn;
    uint8 errorSystem;
    uint8 stop;
    uint8 ready;
    uint8 movingAbsMode;
    uint8 limitJoint;
    uint8 limitWorkspace;
    uint8 limitSwitchSensor;
    uint8 brakeModule;
    uint8 inputEmergency, inputStart, inputReset, outputWait, outputOk, outputOn, outputError;
    QList<double> positionOfActuator;
    QList<double> velocityOfActuator;
    QList<double> accOfActuator;
    QList<uint8> errorActutor;
    QList<uint16> errorIdActuators;
};

#endif // HEXAPODSTATUSRESPONSEMESSAGE_H
