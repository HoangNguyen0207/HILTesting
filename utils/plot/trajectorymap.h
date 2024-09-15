#pragma once
#include "qmlchartviewer.h"
#include "graphdata.h"
#include "gencolor.h"
#include <QtQuick>
#include <QTimer>
#include <QDateEdit>
#include <QScrollBar>
#include <QtWidgets/qlabel.h>
#include <QtQuick>
#include <QTimer>
#include <QPushButton>
#include <QTimerEvent>
#include "utils/calculatehelper/calculatehelper.h"

const int SETUP_POSITION_TIMER_FREQ = 500;
const int SETUP_POSITION_TIMER_INTERVAL = 1000 / SETUP_POSITION_TIMER_FREQ; //ms

class TrajectoryMap : public QQuickPaintedItem
{
        Q_OBJECT

        static constexpr unsigned AZI_POS_SETUP = 0;
        static constexpr unsigned ELV_POS_SETUP = 1;
        static constexpr unsigned AZI_POS_MONITOR = 2;
        static constexpr unsigned ELV_POS_MONITOR = 3;

    public:
        TrajectoryMap(QQuickPaintedItem* parent = nullptr);
        ~TrajectoryMap() override;
        void paint(QPainter *painter) override;
        Q_INVOKABLE void setZoomDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setScrollDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setMouseUsage(const QmlChartViewer::MouseUsage& mouseUsage);
        Q_INVOKABLE void fitChart(const QmlChartViewer::Direction& dir);

        // Create Azi, Elv position trajectory
        Q_INVOKABLE void createPositionTrajectory(const QVariantMap& data);

    signals:

    private slots:
        void onMouseMoveChart();
        void onViewPortChanged();
        void onClickChart(Qt::MouseButton button);
        void onDoubleClickChart(QMouseEvent* event);
        void slotUpdateCustomPlotSize();

    private:
        // Draw chart
        void initCurvePropertiesList();
        void replot();
        void drawChart(QmlChartViewer* viewer);
        void drawLegend(XYChart* c);

        // Timer event
        void timerEvent(QTimerEvent* event) override;

        // Resize X axis
        void resizeXAxis(double time);

        // Draw sinewave
        void drawSineWaveLayer(unsigned int layerId, double amp, double freq,
                               double phase, double offset);

    private:
        std::vector<CurveDataSeries> mCurveList;
        // QuickChartViewer control
        QmlChartViewer *mpChartViewer{nullptr};

        double mMinYValue {-2200};
        double mMaxYValue {2200};
        double mMinXValue {0};
        double mMaxXValue {200};

        // Time duration
        double mDuration{10};

};

