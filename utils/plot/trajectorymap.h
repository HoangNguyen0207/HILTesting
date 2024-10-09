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
#define TIMER_FREQ 200
#define TIMER_INTERVAL 1000/TIMER_FREQ

class TrajectoryMap : public QQuickPaintedItem
{
        Q_OBJECT
        Q_PROPERTY(double deltaX READ deltaX WRITE setDeltaX NOTIFY deltaXChanged)
        Q_PROPERTY(double deltaY READ deltaY WRITE setDeltaY NOTIFY deltaYChanged)
        constexpr static int DISTANCE_CURVE_ID = 0;

        constexpr static int FMS_TX_CURVE_ID = 1;
        constexpr static int FMS_TY_CURVE_ID = 2;
        constexpr static int FMS_TZ_CURVE_ID = 3;
        constexpr static int FMS_RX_CURVE_ID = 4;
        constexpr static int FMS_RY_CURVE_ID = 5;
        constexpr static int FMS_RZ_CURVE_ID = 6;

        constexpr static int TMS_TX_CURVE_ID = 7;
        constexpr static int TMS_TY_CURVE_ID = 8;
        constexpr static int TMS_RX_CURVE_ID = 9;
        constexpr static int TMS_RY_CURVE_ID = 10;


    public:
        TrajectoryMap(QQuickPaintedItem* parent = nullptr);
        ~TrajectoryMap() override;
        void paint(QPainter *painter) override;
        Q_INVOKABLE void setZoomDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setScrollDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setMouseUsage(const QmlChartViewer::MouseUsage& mouseUsage);
        Q_INVOKABLE void fitChart(const QmlChartViewer::Direction& dir);
        Q_INVOKABLE void onDistanceCalcModeTriggered();
        Q_INVOKABLE QString onCreateImageTriggered(const QString& imageName);
        Q_INVOKABLE void onResetMapTriggered();
        Q_INVOKABLE void onWhiteBackgroundModeTriggered();

        // Plot process device
        Q_INVOKABLE void startProcessTimerPlot();
        Q_INVOKABLE void stopProcessTimerPlot();
        Q_INVOKABLE void onFmsTxShowFlagChanged();
        Q_INVOKABLE void onFmsTyShowFlagChanged();
        Q_INVOKABLE void onFmsTzShowFlagChanged();
        Q_INVOKABLE void onFmsRxShowFlagChanged();
        Q_INVOKABLE void onFmsRyShowFlagChanged();
        Q_INVOKABLE void onFmsRzShowFlagChanged();
        Q_INVOKABLE void onTmsTxShowFlagChanged();
        Q_INVOKABLE void onTmsTyShowFlagChanged();
        Q_INVOKABLE void onTmsRxShowFlagChanged();
        Q_INVOKABLE void onTmsRyShowFlagChanged();

        double deltaX() const;
        double deltaY() const;

    public slots:
        void setDeltaX(double deltaX);
        void setDeltaY(double deltaY);

    signals:
        void deltaXChanged(double deltaX);
        void deltaYChanged(double deltaY);

    private slots:
        void onMouseMoveChart();
        void onViewPortChanged();
        void onClickChart(Qt::MouseButton button);
        void onDoubleClickChart(QMouseEvent* event);
        void slotUpdateCustomPlotSize();

        // slot to start or stop plot process
        void onPlotProcessFlagChanged(bool flag);

    private:
        // Draw chart
        void initCurvePropertiesList();
        void replot();
        void drawChart(QmlChartViewer* viewer);
        void drawLegend(XYChart* c);

        // Resize XY axis
        void resizeXAxis(double minX, double maxX);
        void resizeYAxis(double minY, double maxY);

        // Draw track cursor when the mouse move over the plot area
        void drawTrackCursor(QmlChartViewer *viewer);
        void drawCrossHair(XYChart *c, int mouseX, int mouseY);
        void drawSelectedDistancePoint(double posX, double posY);

        // Draw device
        void drawFmsTx(double fmsTx);
        void drawFmsTy(double fmsTy);
        void drawFmsTz(double fmsTz);
        void drawFmsRx(double fmsRx);
        void drawFmsRy(double fmsRy);
        void drawFmsRz(double fmsRz);
        void drawTmsTx(double tmsTx);
        void drawTmsTy(double tmsTy);
        void drawTmsRx(double tmsRx);
        void drawTmsRy(double tmsRy);

        // Timer event
        void timerEvent(QTimerEvent* event) override;

    private:
        // Data curve
        std::vector<CurveDataSeries> mCurveList;
        // QuickChartViewer control
        QmlChartViewer *mpChartViewer{nullptr};
        // XY axis
        double mMinYValue {-30};
        double mMaxYValue {30};
        double mMinXValue {0};
        double mMaxXValue {5};
        // Distance calc mode
        bool mDistanceCalcModeFlag{false};
        // Delta XY
        double mDeltaX;
        double mDeltaY;
        // Timer process
        int mProcessTimerId {0};
        double mCurrentProcessTime {0};
        // Background color
        int mBackgroundColor = ChartConstances::DEFAULT_PLOTAREA_BACKGROUND;
        bool mWhiteModeFlag {false};

};

