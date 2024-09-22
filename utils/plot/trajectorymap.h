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

class TrajectoryMap : public QQuickPaintedItem
{
        Q_OBJECT
        Q_PROPERTY(double deltaX READ deltaX WRITE setDeltaX NOTIFY deltaXChanged)
        Q_PROPERTY(double deltaY READ deltaY WRITE setDeltaY NOTIFY deltaYChanged)
        constexpr static int DISTANCE_CURVE_ID = 0;

    public:
        TrajectoryMap(QQuickPaintedItem* parent = nullptr);
        ~TrajectoryMap() override;
        void paint(QPainter *painter) override;
        Q_INVOKABLE void setZoomDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setScrollDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setMouseUsage(const QmlChartViewer::MouseUsage& mouseUsage);
        Q_INVOKABLE void fitChart(const QmlChartViewer::Direction& dir);
        Q_INVOKABLE void onDistanceCalcModeTriggered();

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

    private:
        // Draw chart
        void initCurvePropertiesList();
        void replot();
        void drawChart(QmlChartViewer* viewer);
        void drawLegend(XYChart* c);

        // Resize XY axis
        void resizeXAxis(double time);
        void resizeYAxis(double amp);

        // Draw track cursor when the mouse move over the plot area
        void drawTrackCursor(QmlChartViewer *viewer);
        void drawCrossHair(XYChart *c, int mouseX, int mouseY);
        void drawSelectedDistancePoint(double posX, double posY);

    private:
        // Data curve
        std::vector<CurveDataSeries> mCurveList;
        // QuickChartViewer control
        QmlChartViewer *mpChartViewer{nullptr};
        // XY axis
        double mMinYValue {0};
        double mMaxYValue {200};
        double mMinXValue {0};
        double mMaxXValue {200};
        // Distance calc mode
        bool mDistanceCalcModeFlag{false};
        // Delta XY
        double mDeltaX;
        double mDeltaY;
};

