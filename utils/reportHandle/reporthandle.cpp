#include "reporthandle.h"
#include <QDir>
#include <QTime>
#include <QDate>
#include "utils/math_helper/math_helper.h"
#include "typedef/system_def.h"

static std::map<DEVICE::TYPE, std::string> mDeviceName {
    {DEVICE::TYPE::FMS, "FMS"},
    {DEVICE::TYPE::TMS, "TMS"}
};

static std::map<DEVICE::FMS_AXIS, std::string> mFmsAxisName {
    {DEVICE::FMS_AXIS::ROLL,  "Roll"},
    {DEVICE::FMS_AXIS::PITCH, "Pitch"},
    {DEVICE::FMS_AXIS::YAW,   "Yaw"},
    {DEVICE::FMS_AXIS::X,     "X"},
    {DEVICE::FMS_AXIS::Y,     "Y"},
    {DEVICE::FMS_AXIS::Z,     "Z"}
};

static std::map<DEVICE::TMS_AXIS, std::string> mTmsAxisName {
    {DEVICE::TMS_AXIS::X,     "X"},
    {DEVICE::TMS_AXIS::Y,     "Y"},
    {DEVICE::TMS_AXIS::GYMBAL_X,  "Gymbal_X"},
    {DEVICE::TMS_AXIS::GYMBAL_Y,  "Gymbal_Y"}
};

static std::map<TEST_DEFINE::TEST_PROCESS, std::string> mTestName {
    {TEST_DEFINE::TEST_PROCESS::POSITION,        "Độ chính xác vị trí"},
    {TEST_DEFINE::TEST_PROCESS::REPEATABILITY,   "Độ chính xác lặp lại"},
    {TEST_DEFINE::TEST_PROCESS::RESOLUTION,      "Độ phân giải vị trí"},
    {TEST_DEFINE::TEST_PROCESS::MAX_VEL,         "Vận tốc lớn nhất"},
    {TEST_DEFINE::TEST_PROCESS::MIN_VEL,         "Vận tốc nhỏ nhất"},
    {TEST_DEFINE::TEST_PROCESS::MAX_ACC,         "Gia tốc lớn nhất"},
    {TEST_DEFINE::TEST_PROCESS::BANDWIDTH,       "Băng thông điều khiển"},
    {TEST_DEFINE::TEST_PROCESS::DELAY,           "Độ trễ phần cứng"},
    {TEST_DEFINE::TEST_PROCESS::LOAD,            "Tải"},
    {TEST_DEFINE::TEST_PROCESS::MAX_POS,         "Giới hạn vị trí"}
};

static std::map<TEST_DEFINE::TEST_PROCESS, std::string> mTestFileName {
    {TEST_DEFINE::TEST_PROCESS::POSITION,        "Position"},
    {TEST_DEFINE::TEST_PROCESS::REPEATABILITY,   "Repeatability"},
    {TEST_DEFINE::TEST_PROCESS::RESOLUTION,      "Resolution"},
    {TEST_DEFINE::TEST_PROCESS::MAX_VEL,         "MaxVelocity"},
    {TEST_DEFINE::TEST_PROCESS::MIN_VEL,         "MinVelocity"},
    {TEST_DEFINE::TEST_PROCESS::MAX_ACC,         "MaxAcceleration"},
    {TEST_DEFINE::TEST_PROCESS::BANDWIDTH,       "Bandwidth"},
    {TEST_DEFINE::TEST_PROCESS::DELAY,           "Delay"},
    {TEST_DEFINE::TEST_PROCESS::LOAD,            "Load"},
    {TEST_DEFINE::TEST_PROCESS::MAX_POS,         "MaxPosition"}
};


ReportHandle::ReportHandle()
{

}

ReportHandle::~ReportHandle()
{

}

void ReportHandle::saveImageGraph(QString& path)
{

}

ReportHandle* ReportHandle::getInstance()
{
    static ReportHandle instance;
    return &instance;
}

void ReportHandle::createReportPositionError(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    if(centerCoordinate.size() != 0 || isLinear == 0)
    {
        QString centerNote = QString("Tọa độ tâm quay của trục: X = %1; Y = %2; Z = %3")
                           .arg(centerCoordinate.at(0)).arg(centerCoordinate.at(1)).arg(centerCoordinate.at(2));
        createNote(report, centerNote);
    }

    QString refNote = QString("Tọa độ tham chiếu ở vị trí homing: X = %1; Y = %2; Z = %3")
                             .arg(refCoordinate.at(0)).arg(refCoordinate.at(1)).arg(refCoordinate.at(2));
    createNote(report, refNote);

    QVector<QVector<QVariant>> mTableValue;

    QVector<QVariant> header;
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí điều khiển")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ X")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Y")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Z")));
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí thực tế")));
    header.push_back(QVariant::fromValue(QStringLiteral("Sai số")));
    mTableValue.push_back(header);

    for(std::vector<TestProcessPositionData>::iterator it = data.begin();
         it != data.end(); it++)
    {
        QVector<QVariant> rowData;
        rowData.push_back(QVariant::fromValue(it->cmdPosition));
        rowData.push_back(QVariant::fromValue(it->x));
        rowData.push_back(QVariant::fromValue(it->y));
        rowData.push_back(QVariant::fromValue(it->z));
        rowData.push_back(QVariant::fromValue(it->measurePosition));
        rowData.push_back(QVariant::fromValue(it->err));
        mTableValue.push_back(rowData);
    }

    createTable(report, mTableValue, QStringLiteral("Bảng đo vị trí"));

    savePdfReport(report, info);
}

void ReportHandle::createReportRepeatability(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    if(centerCoordinate.size() != 0 || isLinear == 0)
    {
        QString centerNote = QString("Tọa độ tâm quay của trục: X = %1; Y = %2; Z = %3")
                           .arg(centerCoordinate.at(0)).arg(centerCoordinate.at(1)).arg(centerCoordinate.at(2));
        createNote(report, centerNote);
    }

    QString refNote = QString("Tọa độ tham chiếu ở vị trí homing: X = %1; Y = %2; Z = %3")
                             .arg(refCoordinate.at(0)).arg(refCoordinate.at(1)).arg(refCoordinate.at(2));
    createNote(report, refNote);

    QVector<QVector<QVariant>> mTableValue;

    QVector<QVariant> header;
    header.push_back(QVariant::fromValue(QStringLiteral("Lần đo")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ X")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Y")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Z")));
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí lặp lại")));
    mTableValue.push_back(header);

    int index = 1;

    for(std::vector<TestProcessPositionData>::iterator it = data.begin();
         it != data.end(); it++)
    {
        QVector<QVariant> rowData;
        rowData.push_back(QVariant::fromValue(index));
        rowData.push_back(QVariant::fromValue(it->x));
        rowData.push_back(QVariant::fromValue(it->y));
        rowData.push_back(QVariant::fromValue(it->z));
        rowData.push_back(QVariant::fromValue(it->measurePosition));
        mTableValue.push_back(rowData);
        index++;
    }

    createTable(report, mTableValue, QStringLiteral("Bảng đo vị trí lặp lại"));

    savePdfReport(report, info);
}

void ReportHandle::createReportResolution(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    if(centerCoordinate.size() != 0 || isLinear == 0)
    {
        QString centerNote = QString("Tọa độ tâm quay của trục: X = %1; Y = %2; Z = %3")
                           .arg(centerCoordinate.at(0)).arg(centerCoordinate.at(1)).arg(centerCoordinate.at(2));
        createNote(report, centerNote);
    }

    QString refNote = QString("Tọa độ tham chiếu ở vị trí homing: X = %1; Y = %2; Z = %3")
                             .arg(refCoordinate.at(0)).arg(refCoordinate.at(1)).arg(refCoordinate.at(2));
    createNote(report, refNote);

    QVector<QVector<QVariant>> mTableValue;

    QVector<QVariant> header;
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí điều khiển")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ X")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Y")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Z")));
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí thực tế")));
    header.push_back(QVariant::fromValue(QStringLiteral("Sai số")));
    mTableValue.push_back(header);

    for(std::vector<TestProcessPositionData>::iterator it = data.begin();
         it != data.end(); it++)
    {
        QVector<QVariant> rowData;
        rowData.push_back(QVariant::fromValue(it->cmdPosition));
        rowData.push_back(QVariant::fromValue(it->x));
        rowData.push_back(QVariant::fromValue(it->y));
        rowData.push_back(QVariant::fromValue(it->z));
        rowData.push_back(QVariant::fromValue(it->measurePosition));
        rowData.push_back(QVariant::fromValue(it->err));
        mTableValue.push_back(rowData);
    }

    createTable(report, mTableValue, QStringLiteral("Bảng đo vị trí"));

    savePdfReport(report, info);
}

void ReportHandle::createReportMaxPosition(InforReport info, std::vector<TestProcessPositionData>& data, std::vector<double>& refCoordinate, std::vector<double>& centerCoordinate, bool isLinear)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    if(centerCoordinate.size() != 0 || isLinear != 0)
    {
        QString centerNote = QString("Tọa độ tâm quay của trục: X = %1; Y = %2; Z = %3")
                           .arg(centerCoordinate.at(0)).arg(centerCoordinate.at(1)).arg(centerCoordinate.at(2));
        createNote(report, centerNote);
    }

    QString refNote = QString("Tọa độ tham chiếu ở vị trí homing: X = %1; Y = %2; Z = %3")
                             .arg(refCoordinate.at(0)).arg(refCoordinate.at(1)).arg(refCoordinate.at(2));
    createNote(report, refNote);

    QVector<QVector<QVariant>> mTableValue;

    QVector<QVariant> header;
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí điều khiển")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ X")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Y")));
    header.push_back(QVariant::fromValue(QStringLiteral("Tọa độ Z")));
    header.push_back(QVariant::fromValue(QStringLiteral("Vị trí thực tế")));
    mTableValue.push_back(header);

    for(std::vector<TestProcessPositionData>::iterator it = data.begin();
         it != data.end(); it++)
    {
        QVector<QVariant> rowData;
        rowData.push_back(QVariant::fromValue(it->cmdPosition));
        rowData.push_back(QVariant::fromValue(it->x));
        rowData.push_back(QVariant::fromValue(it->y));
        rowData.push_back(QVariant::fromValue(it->z));
        rowData.push_back(QVariant::fromValue(it->measurePosition));
        mTableValue.push_back(rowData);
    }

    createTable(report, mTableValue, QStringLiteral("Bảng đo vị trí"));

    savePdfReport(report, info);
}

void ReportHandle::createReportMinVelocity(InforReport info, double amplitude, double frequency, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    createNoteVelocity(report, amplitude, frequency);
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createReportMaxVelocity(InforReport info, double amplitude, double frequency, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    createNoteVelocity(report, amplitude, frequency);
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createReportMaxAcceleration(InforReport info, double amplitude, double frequency, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    createNoteAcceleration(report, amplitude, frequency);
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createReportLoad(InforReport info, double amplitude, double frequency, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    createNoteVelocity(report, amplitude, frequency);
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createReportDelay(InforReport info, double realDelay, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    createNoteDelay(report, realDelay);
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createReportBandwidth(InforReport info, std::vector<TestProcessBandwidthData>& data, double amplitude, QString imgPath)
{
    std::shared_ptr<KDReports::Report> report = std::make_shared<KDReports::Report>();
    createPdfReportHeader(report, info);
    KDReports::TextElement noteAmp;
    noteAmp << QStringLiteral("Biên độ điều khiển: %1").arg(amplitude);

    report->addElement(noteAmp);
    report->addElement(KDReports::HLineElement());

    QVector<QVector<QVariant>> mTableValue;

    QVector<QVariant> header;
    header.push_back(QVariant::fromValue(QStringLiteral("Tần số điều khiển")));
    header.push_back(QVariant::fromValue(QStringLiteral("Biên độ thực tế")));
    header.push_back(QVariant::fromValue(QStringLiteral("Độ chia hệ thống")));
    mTableValue.push_back(header);


    for(std::vector<TestProcessBandwidthData>::iterator it = data.begin();
         it != data.end(); it++)
    {
        QVector<QVariant> rowData;
        rowData.push_back(QVariant::fromValue(it->frequency));
        rowData.push_back(QVariant::fromValue(it->amplitude));
        rowData.push_back(QVariant::fromValue(it->gain));
        mTableValue.push_back(rowData);
    }

    createTable(report, mTableValue, QStringLiteral("Bảng đo biến đổi theo băng thông"));
    addImage(report, imgPath);
    savePdfReport(report, info);
}

void ReportHandle::createPdfReportHeader(std::shared_ptr<KDReports::Report> report, InforReport info)
{
    QString resultTest = (info.result == TEST_PROCESS_PASS) ? QStringLiteral("Đạt") : QStringLiteral("Không đạt");
    report->setOrientation(QPrinter::Portrait);
    report->defaultFont();
    report->setWatermarkText(resultTest, 45);

    KDReports::TextElement titleElement(QObject::tr( "Biên bản kiểm tra"));
    titleElement.setPointSize(30);
    titleElement.setBold(true);
    titleElement.setFont(QFont("Sans-serif"));
    report->addElement(titleElement, Qt::AlignHCenter);
    report->addElement(KDReports::HLineElement());

    KDReports::TextElement type_test, name_axis, name_device, result_test, spec;
    type_test.setBold(true);
    name_axis.setBold(true);
    name_device.setBold(true);
    result_test.setBold(true);

    type_test << QString::fromStdString(mTestName[info.testType]);
    name_device << QString::fromStdString(mDeviceName[info.device]);
    if(info.device == DEVICE::TYPE::FMS)
        name_axis << QString::fromStdString(mFmsAxisName[static_cast<DEVICE::FMS_AXIS>(info.axis)]);
    else if(info.device == DEVICE::TYPE::TMS)
        name_axis << QString::fromStdString(mTmsAxisName[static_cast<DEVICE::TMS_AXIS>(info.axis)]);
    result_test << (info.result ? QStringLiteral("Đạt") : QStringLiteral("Không đạt"));
    spec << QString::number(info.specification);

    KDReports::TableElement tableHeader;
    tableHeader.setPadding(0);
    tableHeader.setBorder(0);
    tableHeader.setWidth(100, KDReports::Percent);

    tableHeader.cell(0,0).addElement(KDReports::TextElement("Bài đo:"), Qt::AlignLeft);
    tableHeader.cell(0,1).addElement(type_test, Qt::AlignLeft);
    tableHeader.cell(1,0).addElement(KDReports::TextElement("Thiết bị:"), Qt::AlignLeft);
    tableHeader.cell(1,1).addElement(name_device, Qt::AlignLeft);
    tableHeader.cell(2,0).addElement(KDReports::TextElement("Trục:"), Qt::AlignLeft);
    tableHeader.cell(2,1).addElement(name_axis, Qt::AlignLeft);
    tableHeader.cell(3,0).addElement(KDReports::TextElement("Kết quả"), Qt::AlignLeft);
    tableHeader.cell(3,1).addElement(result_test, Qt::AlignLeft);
    tableHeader.cell(3,0).addElement(KDReports::TextElement("Chỉ tiêu"), Qt::AlignLeft);
    tableHeader.cell(3,1).addElement(spec, Qt::AlignLeft);

    report->addElement(tableHeader);
    report->addElement(KDReports::HLineElement());

}

void ReportHandle::createTable(std::shared_ptr<KDReports::Report> report, QVector<QVector<QVariant> > data, QString title)
{
    const QColor titleElementColor (204, 204, 255);
    QColor failColor;
    failColor.setRed(236);
    failColor.setGreen(132);
    failColor.setBlue(134);
    const QBrush failBackground(failColor);
    KDReports::TextElement tableTitleElement(title);
    tableTitleElement.setBold(true);
    tableTitleElement.setFont(QFont("Sans-serif"));
    report->addElement(tableTitleElement, Qt::AlignHCenter, titleElementColor);

    KDReports::TableElement table;
    table.setPadding(0);
    table.setBorder(1);
    table.setWidth(100, KDReports::Percent);

    int rows = data.size();
    int columns = data.at(0).size();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            table.cell(i,j).setBackground(failBackground);
            table.cell(i,j).addElement(KDReports::TextElement(data.at(i).at(j).toString()), Qt::AlignCenter);
        }
    }
    report->addElement(table, Qt::AlignHCenter);
    report->addElement(KDReports::HLineElement());
}

void ReportHandle::savePdfReport(std::shared_ptr<KDReports::Report> report, InforReport info)
{
    if(!QDir("report").exists())
    {
        QDir().mkpath("report");
    }
    report->exportToFile(QStringLiteral("report/Test") +
            QString::fromStdString(mTestFileName[info.testType])+
            QTime::currentTime().toString("_hh_mm_ss") +
            QDate::currentDate().toString("_dd_MM_yyyy") + "_" +
            (info.result ? "Pass" : "Fail") + ".pdf");
}

void ReportHandle::addImage(std::shared_ptr<KDReports::Report> report, QString imgPath)
{
    report->addPageBreak();
    KDReports::TextElement titleElement(QObject::tr( "Phụ lục hình ảnh"));
    titleElement.setPointSize(20);
    titleElement.setBold(true);
    titleElement.setFont(QFont("Sans-serif"));
    report->addElement(titleElement, Qt::AlignHCenter);
    report->addElement(KDReports::HLineElement());

    QPixmap kdab(imgPath);
    KDReports::ImageElement imageElement(kdab);
    imageElement.setWidth(100, KDReports::Percent);
    report->addElement(imageElement, Qt::AlignHCenter);
}

void ReportHandle::createNote(std::shared_ptr<KDReports::Report> report, QString note)
{
    KDReports::TextElement reportNote;
    reportNote << note;
    report->addElement(reportNote, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());
}

void ReportHandle::createNoteVelocity(std::shared_ptr<KDReports::Report> report, double amplitude, double frequency)
{
    KDReports::TextElement infoAmpDisplay, infoFreqDisplay, calcDescription;
    infoAmpDisplay << QString("Biên độ (A) của quỹ đạo di chuyển đo được: %1").arg(amplitude);
    infoFreqDisplay << QString("Tần số (f) của quỹ đạo di chuyển đo được: %1").arg(frequency);
    calcDescription << QString("Vận tốc tối đa = 2*PI*f*A = %1").arg(2*PI*frequency*amplitude);

    report->addElement(infoAmpDisplay, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());

    report->addElement(infoFreqDisplay, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());

    report->addElement(calcDescription, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());
}

void ReportHandle::createNoteAcceleration(std::shared_ptr<KDReports::Report> report, double amplitude, double frequency)
{
    KDReports::TextElement infoAmpDisplay, infoFreqDisplay, calcDescription;
    infoAmpDisplay << QString("Biên độ (A) của quỹ đạo di chuyển đo được: %1").arg(amplitude);
    infoFreqDisplay << QString("Tần số (f) của quỹ đạo di chuyển đo được: %1").arg(frequency);
    calcDescription << QString("Gia tốc tối đa = A*(2*PI*f)^2 = %1").arg(2*PI*frequency*2*PI*frequency*amplitude);

    report->addElement(infoAmpDisplay, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());

    report->addElement(infoFreqDisplay, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());

    report->addElement(calcDescription, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());
}

void ReportHandle::createNoteDelay(std::shared_ptr<KDReports::Report> report, double delay)
{
    KDReports::TextElement delayDisplay, description;
    delayDisplay << QString("Độ trễ của hệ thống đo được: %1 ms").arg(delay);
    description << QString("Biểu đồ thể hiện ở phần phụ lục hình ảnh");

    report->addElement(delayDisplay, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());

    report->addElement(description, Qt::AlignLeft);
    report->addElement(KDReports::HLineElement());
}
