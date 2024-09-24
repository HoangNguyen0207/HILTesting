#ifndef REPORTHANDLE_H
#define REPORTHANDLE_H

#include "typedef/system_def.h"
#include "KDReports.h"

#include <map>
#include <iostream>
#include <QVariant>

typedef struct {
    DEVICE::TYPE device;
    int axis;
    TEST_DEFINE::TEST_PROCESS testType;
    bool result;
    double specification;
} InforReport;

class ReportHandle
{
public:
    ReportHandle();
    ~ReportHandle();

    static ReportHandle* getInstance();
    void saveImageGraph(QString& path);

public:
    void createReportPositionError(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear);
    void createReportRepeatability(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear);
    void createReportResolution(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear);
    void createReportMaxPosition(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear);
    void createReportMinVelocity(InforReport info, double amplitude, double frequency, QString imgPath);
    void createReportMaxVelocity(InforReport info, double amplitude, double frequency, QString imgPath);
    void createReportMaxAcceleration(InforReport info, double amplitude, double frequency, QString imgPath);
    void createReportLoad(InforReport info, double amplitude, double frequency, QString imgPath);
    void createReportBandwidth(InforReport info, std::vector<TestProcessBandwidthData>& data, double amplitude, QString imgPath);
    void createReportDelay(InforReport info, double realDelay, QString imgPath);

private:
    void createPdfReportHeader(std::shared_ptr<KDReports::Report> report, InforReport info);
    void createTable(std::shared_ptr<KDReports::Report> report, QVector<QVector<QVariant>> data, QString title);
    void addImage(std::shared_ptr<KDReports::Report> report, QString imgPath);
    void savePdfReport(std::shared_ptr<KDReports::Report> report, InforReport info);
    void createNote(std::shared_ptr<KDReports::Report> report, QString note);
    void createNoteVelocity(std::shared_ptr<KDReports::Report> report, double amplitude, double frequency);
    void createNoteAcceleration(std::shared_ptr<KDReports::Report> report, double amplitude, double frequency);
    void createNoteDelay(std::shared_ptr<KDReports::Report> report, double delay);
};

#endif // REPORTHANDLE_H
