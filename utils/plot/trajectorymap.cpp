#include "trajectorymap.h"
#include <sstream>
#include "logger/logger.h"
#include <math.h>
#include "chartdir.h"
#include <QTimerEvent>

TrajectoryMap::TrajectoryMap(QQuickPaintedItem *parent)
    : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
    mpChartViewer = new QmlChartViewer(this);
    mpChartViewer->setPosition(QPointF(0,0));
    mpChartViewer->setSize(QSizeF(this->width(), this->height()));

    connect(mpChartViewer,&QmlChartViewer::clicked,this,&TrajectoryMap::onClickChart);
    connect(mpChartViewer,&QmlChartViewer::viewPortChanged,this,&TrajectoryMap::onViewPortChanged);
    connect(mpChartViewer,&QmlChartViewer::mouseMoveChart,this,&TrajectoryMap::onMouseMoveChart);
    connect(mpChartViewer,&QmlChartViewer::mouseDoubleClicked,this,&TrajectoryMap::onDoubleClickChart);

    connect(this,&TrajectoryMap::widthChanged,this,&TrajectoryMap::slotUpdateCustomPlotSize);
    connect(this,&TrajectoryMap::heightChanged,this,&TrajectoryMap::slotUpdateCustomPlotSize);

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

TrajectoryMap::~TrajectoryMap()
{
    delete mpChartViewer->getChart();
}

void TrajectoryMap::paint(QPainter *painter)
{

}

void TrajectoryMap::setZoomDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setZoomDirection(direction);
}

void TrajectoryMap::setScrollDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setScrollDirection(direction);
}

void TrajectoryMap::setMouseUsage(const QmlChartViewer::MouseUsage &mouseUsage)
{
    mpChartViewer->setMouseUsage(mouseUsage);
}

void TrajectoryMap::fitChart(const QmlChartViewer::Direction &dir)
{

}

void TrajectoryMap::createPositionTrajectory(const QVariantMap &data)
{
    double aziAmp = data["aziAmp"].toDouble();
    double aziFreq = data["aziFreq"].toDouble();
    double aziPhase = data["aziPhase"].toDouble();
    double aziOffset = data["aziOffset"].toDouble();

    double elvAmp = data["elvAmp"].toDouble();
    double elvFreq = data["elvFreq"].toDouble();
    double elvPhase = data["elvPhase"].toDouble();
    double elvOffset = data["elvOffset"].toDouble();

    double duration = data["duration"].toDouble();

    mDuration = duration;

    drawSineWaveLayer(AZI_POS_SETUP,aziAmp,aziFreq,aziPhase,aziOffset);
    drawSineWaveLayer(ELV_POS_SETUP,elvAmp,elvFreq,elvPhase,elvOffset);
}

void TrajectoryMap::onMouseMoveChart()
{

}

void TrajectoryMap::onViewPortChanged()
{
    if (mpChartViewer->needUpdateChart())
    {
        drawChart(mpChartViewer);
    }
    if (mpChartViewer->needUpdateImageMap())
    {

    }
}

void TrajectoryMap::onClickChart(Qt::MouseButton button)
{

}

void TrajectoryMap::onDoubleClickChart(QMouseEvent *event)
{

}

void TrajectoryMap::slotUpdateCustomPlotSize()
{
    drawChart(mpChartViewer);
}

void TrajectoryMap::initCurvePropertiesList()
{
    CurveDataSeries tmp;
    tmp.id = AZI_POS_SETUP;
    tmp.color = 0xFFC500;
    tmp.name = "AZI Setup";
    tmp.symbolSize = 8;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    tmp.id = ELV_POS_SETUP;
    tmp.color = 0x54CAAA;
    tmp.name = "ELV Setup";
    tmp.symbolSize = 8;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    tmp.id = AZI_POS_MONITOR;
    tmp.color = 0xCCC500;
    tmp.name = "AZI Monitor";
    tmp.symbolSize = 8;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    tmp.id = ELV_POS_MONITOR;
    tmp.color = 0x44C500;
    tmp.name = "ELV Monitor";
    tmp.symbolSize = 8;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);
}

void TrajectoryMap::replot()
{
    mpChartViewer->updateViewPort(true,true);
}

void TrajectoryMap::drawChart(QmlChartViewer *viewer)
{
    int width = static_cast<int>(this->width());
    int height = static_cast<int>(this->height());

    XYChart* c = new XYChart(width,height, Chart::Transparent);

    int leftMargin = 40;
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

    // Resize X axis
    resizeXAxis(mDuration);

    viewer->setFullRange("y", mMinYValue, mMaxYValue);
    viewer->setFullRange("x", mMinXValue, mMaxXValue);
    viewer->setZoomInHeightLimit(0.000001);
    viewer->setZoomInWidthLimit(0.000001);
    viewer->syncLinearAxisWithViewPort("x", c->xAxis());
    viewer->syncLinearAxisWithViewPort("y", c->yAxis());

    drawLegend(c);
    delete viewer->getChart();
    viewer->setChart(c);
}

void TrajectoryMap::drawLegend(XYChart *c)
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

void TrajectoryMap::timerEvent(QTimerEvent *event)
{

}

void TrajectoryMap::resizeXAxis(double time)
{
    mMinXValue = 0;
    mMaxXValue = time;
}

void TrajectoryMap::drawSineWaveLayer(unsigned int layerId, double amp, double freq, double phase, double offset)
{
    mCurveList[layerId].xSeries.clear();
    mCurveList[layerId].ySeries.clear();

    std::pair<double, double> sinePoint;

    double currentTime = 0;
    phase = phase * D2R;

    while(currentTime < mDuration)
    {
        sinePoint.first = currentTime;
        sinePoint.second = amp * sin(2 * PI * freq * currentTime + phase) + offset;
        mCurveList[layerId].xSeries.push_back(sinePoint.first);
        mCurveList[layerId].ySeries.push_back(sinePoint.second);
        currentTime += (double)SETUP_POSITION_TIMER_INTERVAL / 1000;
    }
    replot();
}
