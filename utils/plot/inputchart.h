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


class InputChart : public QQuickPaintedItem
{
        Q_OBJECT
    public:
        InputChart(QQuickPaintedItem* parent = nullptr);
        ~InputChart() override;

        void paint(QPainter *painter) override;
        Q_INVOKABLE void setZoomDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setScrollDirection(const QmlChartViewer::Direction& direction);
        Q_INVOKABLE void setMouseUsage(const QmlChartViewer::MouseUsage& mouseUsage);
        Q_INVOKABLE void fitChart(const QmlChartViewer::Direction& dir);

    protected:
        void slotUpdateCustomPlotSize();
        void replot();
        // Draw chart
        void drawChart(QmlChartViewer* viewer);
        void drawLegend(XYChart* c);
        // Update other controls as viewport changes
        void updateControls(QmlChartViewer* viewer);
        // update imgmap
        void updateImageMap(QmlChartViewer* viewer);
        void reFindMinMaxYValue();
    private:
        std::vector<CurveDataSeries> mCurveList;
        // QuickChartViewer control
        QmlChartViewer *mpChartViewer{nullptr};



        QTimer* mTimer;
        QTimer* mTimerDraw;

        double mMinYValue {-180};
        double mMaxYValue {180};
        double mMinXValue {0};
        double mMaxXValue {180};

    signals:

    public slots:

    protected slots:
        void updateChart();
        void onMouseMoveChart(QMouseEvent* event);      // Mouse move on chart
        void onViewPortChanged();
        void onClickChart(QMouseEvent* event);
        void onDoubleClickChart(QMouseEvent* event);
        void updateAndDraw();
};

