#pragma once
#include "fmsapi.h"
#include "fmsmanager.h"
#include "FMSCommand.h"

struct FMSDemandData
{
        double tx;
        double ty;
        double tz;
        double rx;
        double ry;
        double rz;
};

class FMSDevice : public QObject
{
        Q_OBJECT
    public:
        FMSDevice(QObject *parent = nullptr);
        ~FMSDevice();

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
        int moveAbsPosition(double tx, double ty,
                            double tz, double rx,
                            double ry, double rz);
        int queryStatus();
        int queryVelocity();
        int queryAcc();
        int queryHomeOffset();
        int queryLimitWorkSpace();
        int queryLimitVelocity();
        int queryLimitAcc();

        int configVelocity(double tx, double ty,
                           double tz, double rx,
                           double ry, double rz);
        int configLimitVelocity(double tx, double ty,
                                double tz, double rx,
                                double ry, double rz);
        int configAcc(double tx, double ty,
                      double tz, double rx,
                      double ry, double rz);
        int configLimitAcc(double tx, double ty,
                           double tz, double rx,
                           double ry, double rz);
        int configHomeOffset(double tx, double ty,
                             double tz, double rx,
                             double ry, double rz);

        void setDemandData(const FMSDemandData& data);
        FMSDemandData getFMSDemandData() const;

    signals:
        void sigReceiveResponse(QString response);

    private slots:
        void onReceiveResponse(QString response);

    private:
        FMSDemandData mDemandData;
};

