#pragma once
#include <QObject>

class TMSDevice : public QObject
{
        Q_OBJECT
    public:
        TMSDevice(QObject *parent = nullptr);
        ~TMSDevice();

        int sendCommand(const QString& cmd);
        int enable();
        int disable();
        int reset();
        int controllerOn();
        int controllerOff();
        int powerOff();
        int stopMoving();
        int homing();
        int moveOff();
        int moveAbsPosition(double tx, double ty, double rx, double ry);
        int queryStatus();
        int queryVelocity();
        int queryAcc();
        int queryHomeOffset();
        int queryLimitWorkSpace();
        int queryLimitVelocity();
        int queryLimitAcc();
        int configVelocity(double tx, double ty, double rx, double ry);
        int configLimitVelocity(double tx, double ty, double rx, double ry);
        int configAcc(double tx, double ty, double rx, double ry);
        int configLimitAcc(double tx, double ty, double rx, double ry);
        int configHomeOffset(double tx, double ty, double rx, double ry);

    signals:
        void sigReceiveResponse(QString response);

    private slots:
        void onReceiveResponse(QString response);


};

