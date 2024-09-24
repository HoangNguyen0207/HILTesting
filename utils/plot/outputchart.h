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

// 100ms per data point, chart contains 1 min of data = 600 data points.
static const int DataInterval = 100;
static const int sampleSize = 60 * 1000 / DataInterval;

class OutputChart : public QQuickPaintedItem
{
        Q_OBJECT
        static constexpr unsigned POWER_CURVE_ID = 0;

    public:
        OutputChart(QQuickPaintedItem* parent = nullptr);
        ~OutputChart() override;

        void paint(QPainter *painter) override;
        Q_INVOKABLE void setZoomDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setScrollDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setMouseUsage(const QmlChartViewer::MouseUsage& mouseUsage);
        Q_INVOKABLE void fitChart(const QmlChartViewer::Direction& dir);

        // Test power realtime
        Q_INVOKABLE void testRealtimePower(bool isTest);

        // Enable/disable track axis
        Q_INVOKABLE void setTrackAxisEnable(bool isEnable);

        // Enable/disable time frame
        Q_INVOKABLE void setTimeFrameEnable(bool isEnable);

    private:
        // Draw chart
        void replot();
        void drawChart(QmlChartViewer* viewer);
        void drawLegend(XYChart* c);

        // Draw track cursor when the mouse move over the plot area
        void drawTrackCursor(QmlChartViewer *viewer, int mouseX);
        void trackLineAxis(XYChart *c, int mouseX);
        void crossHair(XYChart *c, int mouseX, int mouseY);

        // Timer event
        void timerEvent(QTimerEvent* event) override;

        // Scale xAxis according to currentTime
        void scaleTimeAxis(double currentTime);

    private:
        std::vector<CurveDataSeries> mCurveList;
        // QuickChartViewer control
        QmlChartViewer *mpChartViewer{nullptr};

        double mMinYValue {-180};
        double mMaxYValue {180};
        double mMinXValue {0};
        double mMaxXValue {20};

        // Time value axis
        double mZeroTime{0};
        double mLastTime{10};
        double mCurrentTime{0};
        double mTimeFrame{5};

        // Test TimerId
        int mTestTimerId{0};

        // Track axis enable
        bool mTrackAxisEnable{false};

        // Time frame enable
        bool mTimeFrameEnable{false};

    signals:

    private slots:
        void onMouseMoveChart();
        void onViewPortChanged();
        void onClickChart(Qt::MouseButton button);
        void onDoubleClickChart(QMouseEvent* event);
        void slotUpdateCustomPlotSize();
};

