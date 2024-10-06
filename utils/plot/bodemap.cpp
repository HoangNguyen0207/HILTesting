#include "bodemap.h"
#include <sstream>
#include "logger/logger.h"
#include <math.h>
#include "chartdir.h"
#include <QTimerEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <QStringLiteral>
#include "flux/store/mainstore.h"

BodeMap::BodeMap(QQuickPaintedItem *parent)
    : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
    mpChartViewer = new QmlChartViewer(this);
    mpChartViewer->setPosition(QPointF(0,0));
    mpChartViewer->setSize(QSizeF(this->width(), this->height()));

    connect(mpChartViewer,&QmlChartViewer::clicked,this,&BodeMap::onClickChart);
    connect(mpChartViewer,&QmlChartViewer::viewPortChanged,this,&BodeMap::onViewPortChanged);
    connect(mpChartViewer,&QmlChartViewer::mouseMoveChart,this,&BodeMap::onMouseMoveChart);
    connect(mpChartViewer,&QmlChartViewer::mouseDoubleClicked,this,&BodeMap::onDoubleClickChart);

    connect(this,&BodeMap::widthChanged,this,&BodeMap::slotUpdateCustomPlotSize);
    connect(this,&BodeMap::heightChanged,this,&BodeMap::slotUpdateCustomPlotSize);

    // Initially set the mouse to drag to scroll mode
    setMouseUsage(QmlChartViewer::MouseUsage::MouseUsageScroll);
    // Enable mouse wheel zooming by setting the zoom ratio to 1.1 per wheel event
    mpChartViewer->setMouseWheelZoomRatio(1.1);

    // Init curve properties
    initCurvePropertiesList();

    setZoomDirection(QmlChartViewer::Direction::HorizontalVertical);
    setScrollDirection(QmlChartViewer::Direction::HorizontalVertical);
    mpChartViewer->updateViewPort(true,true);
}

BodeMap::~BodeMap()
{
    delete mpChartViewer->getChart();
}

void BodeMap::paint(QPainter *painter)
{

}

void BodeMap::setZoomDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setZoomDirection(direction);
}

void BodeMap::setScrollDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setScrollDirection(direction);
}

void BodeMap::setMouseUsage(const QmlChartViewer::MouseUsage &mouseUsage)
{
    mpChartViewer->setMouseUsage(mouseUsage);
}

void BodeMap::fitChart(const QmlChartViewer::Direction &dir)
{

}

void BodeMap::onDistanceCalcModeTriggered()
{
    if(!mDistanceCalcModeFlag)
    {
        mDistanceCalcModeFlag = true;
    }else
    {
        mCurveList[DISTANCE_CURVE_ID].xSeries.clear();
        mCurveList[DISTANCE_CURVE_ID].ySeries.clear();
        replot();
        mDistanceCalcModeFlag = false;
    }
}

double BodeMap::deltaX() const
{
    return mDeltaX;
}

double BodeMap::deltaY() const
{
    return mDeltaY;
}

void BodeMap::setDeltaX(double deltaX)
{
    if (qFuzzyCompare(mDeltaX, deltaX))
        return;

    mDeltaX = deltaX;
    emit deltaXChanged(mDeltaX);
}

void BodeMap::setDeltaY(double deltaY)
{
    if (qFuzzyCompare(mDeltaY, deltaY))
        return;

    mDeltaY = deltaY;
    emit deltaYChanged(mDeltaY);
}

void BodeMap::onMouseMoveChart()
{
    drawTrackCursor(this->mpChartViewer);
}

void BodeMap::onViewPortChanged()
{
    if (mpChartViewer->needUpdateChart())
    {
        drawChart(mpChartViewer);
    }
    if (mpChartViewer->needUpdateImageMap())
    {

    }
}

void BodeMap::onClickChart(Qt::MouseButton button)
{

}

void BodeMap::onDoubleClickChart(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        XYChart* c = static_cast<XYChart*>(mpChartViewer->getChart());
        if(mDistanceCalcModeFlag)
        {
            drawSelectedDistancePoint(c->getXValue(event->x()),c->getYValue(event->y()));
        }
    }
}

void BodeMap::slotUpdateCustomPlotSize()
{
    drawChart(mpChartViewer);
}

void BodeMap::initCurvePropertiesList()
{
    CurveDataSeries tmp;
    tmp.id = DISTANCE_CURVE_ID;
    tmp.color = 0x00FFFF;
    tmp.name = "Distance";
    tmp.symbolSize = 8;
    tmp.symbol = Chart::CircleSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = true;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    tmp.id = AMP_CURVE_ID;
    tmp.color = 0x00FF00;
    tmp.name = "";
    tmp.symbolSize = 14;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    tmp.id = HZ_CURVE_ID;
    tmp.color = 0xFFFF00;
    tmp.name = "";
    tmp.symbolSize = 14;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);
}

void BodeMap::replot()
{
    mpChartViewer->updateViewPort(true,true);
}

void BodeMap::drawChart(QmlChartViewer *viewer)
{
    int width = static_cast<int>(this->width());
    int height = static_cast<int>(this->height());

    XYChart* c = new XYChart(width,height,0xFFFFFF);

    int leftMargin = 50;
    int topMargin = 15;
    int rightMargin = 15;
    int bottomMargin = 25;

    int plotAreaX = static_cast<int>(this->x()) + leftMargin ; //0 + left margin
    int plotAreaY = static_cast<int>(this->y()) + topMargin; //0 + top margin

    int plotAreaWidth = (c->getWidth() - leftMargin) - rightMargin; // right margin
    int plotAreaHeight = (c->getHeight() - topMargin - ChartConstances::DEFAULT_LICENSE_LABEL_MARGIN) - bottomMargin; // bottom margin

    c->setPlotArea(plotAreaX,plotAreaY,plotAreaWidth,plotAreaHeight,
                   ChartConstances::DEFAULT_PLOTAREA_BACKGROUND,                              // background color
                   ChartConstances::DEFAULT_PLOTAREA_SECOND_BACKGROUND,                       // second background color
                   ChartConstances::DEFAULT_PLOTAREA_EDGE_COLOR,                              // edge color
                   ChartConstances::DEFAULT_GRID_COLOR,                                       // H-Grid color
                   ChartConstances::DEFAULT_GRID_COLOR);                                      // V-Grid color

    c->setClipping();

    c->getLegend()->setLineStyleKey();
    c->xAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->yAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->xAxis()->setColors(Chart::Transparent);
    c->yAxis()->setColors(Chart::Transparent);
    c->yAxis()->setTitle("", "./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_YTITLE_COLOR);
    c->xAxis()->setTitle("", "./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_XTITLE_COLOR);
    c->xAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_XLABLE_COLOR);
    c->yAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_YLABLE_COLOR);

    c->xAxis()->setWidth(2);
    c->yAxis()->setWidth(2);
    c->xAxis()->setTickDensity(50);
    c->yAxis()->setTickDensity(40);

    // Add a line layers for the curves, using lines width of 2 pixels
    for(auto it = mCurveList.begin(); it != mCurveList.end(); it++)
    {
        if (it->xSeries.size() > 0 && it->needToDraw)
        {
            LineLayer* layer = c->addLineLayer();
            layer->setLineWidth(ChartConstances::DEFAULT_LINE_WIDTH);
            layer->setFastLineMode();
            DoubleArray tmp(it->xSeries.data(), static_cast<int>(it->ySeries.size()));
            layer->setXData(tmp);
            DataSet* data;
            if (it->isDashLine)
                data = layer->addDataSet(DoubleArray(it->ySeries.data(), static_cast<int>(it->ySeries.size())),
                                         c->dashLineColor(it->color, Chart::DashLine), it->name.c_str());
            else
                data = layer->addDataSet(DoubleArray(it->ySeries.data(), static_cast<int>(it->ySeries.size())),
                                         it->color, it->name.c_str());
            data->setDataSymbol(it->symbol, it->symbolSize);
            data->setLineWidth(it->lineWidth);
            if (!(it->needToShow))
            {
                data->setLineWidth(0);
            }
        }
    }

    viewer->setFullRange("y", mMinYValue, mMaxYValue);
    viewer->setFullRange("x", mMinXValue, mMaxXValue);
    viewer->setZoomInHeightLimit(0.000001);
    viewer->setZoomInWidthLimit(0.000001);
    viewer->syncLinearAxisWithViewPort("x", c->xAxis());
    viewer->syncLinearAxisWithViewPort("y", c->yAxis());

    drawLegend(c);
    delete viewer->getChart();
    viewer->setChart(c);

    if(viewer->isMouseOnPlotArea())
    {
        drawTrackCursor(viewer);
    }
}

void BodeMap::drawLegend(XYChart *c)
{
    c->initDynamicLayer();
    // The drawarea and plotarea objects
    DrawArea* d = c->getDrawArea();
    PlotArea* plotArea = c->getPlotArea();
    // Container to hold the legend entries
    std::vector<std::string> legendEntries;
    // Iterate through all layers to draw the data labels
    for(int i = 0; i < c->getLayerCount(); i++)
    {
        Layer* layer = c->getLayerByZ(i);
        // Iterate through all the data sets in the layer
        for(int j = 0; j < layer->getDataSetCount(); j++)
        {
            DataSet* dataSet = layer->getDataSetByZ(j);
            const char* dataSetName = dataSet->getDataName();
            // Get the color, name and position of the data label
            int color = dataSet->getDataColor();
            if (dataSetName && *dataSetName && (color != static_cast<int>(Chart::Transparent)))
            {
                // Build the legend entry, consist of the legend icon, name and data value.
                std::ostringstream legendEntry;
                legendEntry << "<*block*>" << dataSet->getLegendIcon() << " " << dataSetName << "<*/*>";
                legendEntries.push_back(legendEntry.str());
            }
        }
    }
    // Create the legend by joining the legend entries
    std::ostringstream legendText;
    for (int i = (static_cast<int>(legendEntries.size())) - 1; i >= 0; --i)
    {
        legendText << "\n" << legendEntries[static_cast<unsigned>(i)];
    }
    // Display the legend on the top of the plot area
    TTFText* t = d->text(legendText.str().c_str(), "./fonts/Arial.ttf", 8);
    t->draw(plotArea->getLeftX() + 5, plotArea->getTopY() - 3, 0xffffff, Chart::TopLeft);
    t->destroy();
}

void BodeMap::resizeXAxis(double minX, double maxX)
{
    mMinXValue = minX;
    mMaxXValue = maxX;
    replot();
}

void BodeMap::resizeYAxis(double minY, double maxY)
{
    mMinYValue = minY;
    mMaxYValue = maxY;
    replot();
}

void BodeMap::drawTrackCursor(QmlChartViewer *viewer)
{
    if(mDistanceCalcModeFlag == true)
    {
        drawCrossHair((XYChart*)viewer->getChart(),viewer->getPlotAreaMouseX(),viewer->getPlotAreaMouseY());
        viewer->updateDisplay();
        viewer->removeDynamicLayer("mouseleaveplotarea");
    }
}

void BodeMap::drawCrossHair(XYChart *c, int mouseX, int mouseY)
{
    // Clear the current dynamic layer and get the DrawArea object to draw on it.
    DrawArea *d = c->initDynamicLayer();

    // The plot area object
    PlotArea *plotArea = c->getPlotArea();

    // Draw a vertical line and a horizontal line as the cross hair
    d->vline(plotArea->getTopY(), plotArea->getBottomY(), mouseX, d->dashLineColor(0xd3d3d3, 0x0101));
    d->hline(plotArea->getLeftX(), plotArea->getRightX(), mouseY, d->dashLineColor(0xd3d3d3, 0x0101));

    // Draw y-axis label
    std::ostringstream ylabel;
    ylabel << "<*block,bgColor=FFFFDD,margin=3,edgeColor=000000*>" << c->formatValue(c->getYValue(
        mouseY, c->yAxis()), "{value|P4}") << "<*/*>";
    TTFText *t = d->text(ylabel.str().c_str(), "Arial Bold", 8);
    t->draw(plotArea->getLeftX() - 5, mouseY, 0x000000, Chart::Right);
    t->destroy();

    // Draw x-axis label
    std::ostringstream xlabel;
    xlabel << "<*block,bgColor=FFFFDD,margin=3,edgeColor=000000*>" << c->formatValue(c->getXValue(
        mouseX), "{value|P4}") << "<*/*>";
    t = d->text(xlabel.str().c_str(), "Arial Bold", 8);
    t->draw(mouseX, plotArea->getBottomY() + 5, 0x000000, Chart::Top);
    t->destroy();
}

void BodeMap::drawSelectedDistancePoint(double posX, double posY)
{
    int numpoint = mCurveList[DISTANCE_CURVE_ID].xSeries.size();
    switch (numpoint)
    {
        case 0:
        {
            mCurveList[DISTANCE_CURVE_ID].xSeries.push_back(posX);
            mCurveList[DISTANCE_CURVE_ID].ySeries.push_back(posY);
            break;
        }
        case 1:
        {
            mCurveList[DISTANCE_CURVE_ID].xSeries.push_back(posX);
            mCurveList[DISTANCE_CURVE_ID].ySeries.push_back(posY);
            break;
        }
        case 2:
        {
            mCurveList[DISTANCE_CURVE_ID].xSeries.clear();
            mCurveList[DISTANCE_CURVE_ID].ySeries.clear();
            mCurveList[DISTANCE_CURVE_ID].xSeries.push_back(posX);
            mCurveList[DISTANCE_CURVE_ID].ySeries.push_back(posY);
            break;
        }
        default: break;
    }

    numpoint = mCurveList[DISTANCE_CURVE_ID].xSeries.size();
    if(numpoint == 2)
    {
        setDeltaX(abs(mCurveList[DISTANCE_CURVE_ID].xSeries[1] - mCurveList[DISTANCE_CURVE_ID].xSeries[0]));
        setDeltaY(abs(mCurveList[DISTANCE_CURVE_ID].ySeries[1] - mCurveList[DISTANCE_CURVE_ID].ySeries[0]));
    }

    replot();
}

void BodeMap::timerEvent(QTimerEvent *event)
{

}
