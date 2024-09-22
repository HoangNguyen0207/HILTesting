#include "outputchart.h"
#include <sstream>
#include "logger/logger.h"
#include <math.h>

OutputChart::OutputChart(QQuickPaintedItem *parent) : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
    mpChartViewer = new QmlChartViewer(this);
    mpChartViewer->setPosition(QPointF(0,0));
    mpChartViewer->setSize(QSizeF(this->width(), this->height()));

    connect(mpChartViewer,&QmlChartViewer::clicked,this,&OutputChart::onClickChart);
    connect(mpChartViewer,&QmlChartViewer::viewPortChanged,this,&OutputChart::onViewPortChanged);
    connect(mpChartViewer,&QmlChartViewer::mouseMoveChart,this,&OutputChart::onMouseMoveChart);
    connect(mpChartViewer,&QmlChartViewer::mouseDoubleClicked,this,&OutputChart::onDoubleClickChart);

    connect(this,&OutputChart::widthChanged,this,&OutputChart::slotUpdateCustomPlotSize);
    connect(this,&OutputChart::heightChanged,this,&OutputChart::slotUpdateCustomPlotSize);

    // Initially set the mouse to drag to scroll mode
    setMouseUsage(QmlChartViewer::MouseUsage::MouseUsageScroll);
    // Enable mouse wheel zooming by setting the zoom ratio to 1.1 per wheel event
    mpChartViewer->setMouseWheelZoomRatio(1.1);

    CurveDataSeries tmp;
    tmp.id = POWER_CURVE_ID;
    tmp.color = 0xFFC500;
    tmp.name = "Data";
    tmp.symbolSize = 14;
    tmp.symbol = Chart::NoSymbol;
    tmp.lineWidth = 1;
    tmp.isDashLine = false;
    tmp.needToDraw = true;
    tmp.needToShow = true;
    mCurveList.push_back(tmp);

    setZoomDirection(QmlChartViewer::Direction::HorizontalVertical);
    setScrollDirection(QmlChartViewer::Direction::HorizontalVertical);
    mpChartViewer->updateViewPort(true,true);
}

OutputChart::~OutputChart()
{

}

void OutputChart::paint(QPainter *painter)
{

}

void OutputChart::setZoomDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setZoomDirection(direction);
}

void OutputChart::setScrollDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setScrollDirection(direction);
}

void OutputChart::setMouseUsage(const QmlChartViewer::MouseUsage &mouseUsage)
{
    mpChartViewer->setMouseUsage(mouseUsage);
}

void OutputChart::fitChart(const QmlChartViewer::Direction &dir)
{

}

void OutputChart::testRealtimePower(bool isTest)
{
    if(isTest)
    {
        mMaxXValue = 20;
        mCurveList[POWER_CURVE_ID].xSeries.clear();
        mCurveList[POWER_CURVE_ID].ySeries.clear();
        mTestTimerId = this->startTimer(DataInterval);
    }else
    {
        mCurrentTime = 0;
        this->killTimer(mTestTimerId);
    }
}

void OutputChart::setTrackAxisEnable(bool isEnable)
{
    this->mTrackAxisEnable = isEnable;
}

void OutputChart::setTimeFrameEnable(bool isEnable)
{
    this->mTimeFrameEnable = isEnable;
}

void OutputChart::slotUpdateCustomPlotSize()
{
    drawChart(mpChartViewer);
}

void OutputChart::replot()
{
    mpChartViewer->updateViewPort(true,true);
}

void OutputChart::drawTrackCursor(QmlChartViewer *viewer, int mouseX)
{
    crossHair((XYChart*)viewer->getChart(),viewer->getPlotAreaMouseX(),viewer->getPlotAreaMouseY());
    viewer->updateDisplay();
    viewer->removeDynamicLayer("mouseleaveplotarea");
}

void OutputChart::trackLineAxis(XYChart *c, int mouseX)
{
    // Clear the current dynamic layer and get the DrawArea object to draw on it.
    DrawArea *d = c->initDynamicLayer();

    // The plot area object
    PlotArea *plotArea = c->getPlotArea();

    // Get the data x-value that is nearest to the mouse, and find its pixel coordinate.
    double xValue = c->getNearestXValue(mouseX);
    int xCoor = c->getXCoor(xValue);

    // The vertical track line is drawn up to the highest data point (the point with smallest
    // y-coordinate). We need to iterate all datasets in all layers to determine where it is.
    int minY = plotArea->getBottomY();

    // Iterate through all layers to find the highest data point
    for(int i = 0; i < c->getLayerCount(); ++i) {
        Layer *layer = c->getLayerByZ(i);

        // The data array index of the x-value
        int xIndex = layer->getXIndexOf(xValue);

        // Iterate through all the data sets in the layer
        for(int j = 0; j < layer->getDataSetCount(); ++j) {
            DataSet *dataSet = layer->getDataSetByZ(j);

            double dataPoint = dataSet->getPosition(xIndex);
            if ((dataPoint != Chart::NoValue) && (dataSet->getDataColor() != (int)Chart::Transparent))
                minY = (std::min)(minY, c->getYCoor(dataPoint, dataSet->getUseYAxis()));
        }
    }

    // Draw a vertical track line at the x-position up to the highest data point.
    //    d->vline((std::max)(minY, plotArea->getTopY()), plotArea->getBottomY() + 6, xCoor,
    //        d->dashLineColor(0x000000, 0x0101));

    // Draw a label on the x-axis to show the track line position
    //    std::ostringstream xlabel;
    //    xlabel << "<*font,bgColor=000000*> " << c->xAxis()->getFormattedLabel(xValue, "mmm dd, yyyy")
    //        << " <*/font*>";
    //    TTFText *t = d->text(xlabel.str().c_str(), "Arial Bold", 8);
    //    t->draw(xCoor, plotArea->getBottomY() + 6, 0xffffff, Chart::Top);
    //    t->destroy();

    // Iterate through all layers to build the legend array
    for(int i = 0; i < c->getLayerCount(); ++i) {
        Layer *layer = c->getLayerByZ(i);

        // The data array index of the x-value
        int xIndex = layer->getXIndexOf(xValue);

        // Iterate through all the data sets in the layer
        for(int j = 0; j < layer->getDataSetCount(); ++j) {
            DataSet *dataSet = layer->getDataSetByZ(j);

            // The positional value, axis binding, pixel coordinate and color of the data point.
            double dataPoint = dataSet->getPosition(xIndex);
            Axis *yAxis = dataSet->getUseYAxis();
            int yCoor = c->getYCoor(dataPoint, yAxis);
            int color = dataSet->getDataColor();

            // Draw the axis label only for visible data points of named data sets
            if ((dataPoint != Chart::NoValue) && (color != (int)Chart::Transparent) && (yCoor >=
                                                                                        plotArea->getTopY()) && (yCoor <= plotArea->getBottomY())) {
                // The axis label consists of 3 parts - a track dot for the data point, an axis label,
                // and a line joining the track dot to the axis label.

                // Draw the line first. The end point of the line at the axis label side depends on
                // whether the label is at the left or right side of the axis (that is, on whether the
                // axis is on the left or right side of the plot area).
                int xPos = yAxis->getX() + ((yAxis->getAlignment() == Chart::Left) ? -4 : 4);
                d->hline(xCoor, xPos, yCoor, d->dashLineColor(color, 0x0101));

                // Draw the track dot
                d->circle(xCoor, yCoor, 4, 4, color, color);

                // Draw the axis label. If the axis is on the left side of the plot area, the labels
                // should right aligned to the axis, and vice versa.
                std::ostringstream axisLabel;
                axisLabel << "<*font,bgColor=" << std::hex << color << "*> "
                          << c->formatValue(dataPoint, "{value|P4}")	<< " <*/font*>";
                TTFText *t = d->text(axisLabel.str().c_str(), "Arial Bold", 8);
                t->draw(xPos, yCoor, 0xffffff,
                        ((yAxis->getAlignment() == Chart::Left) ? Chart::Right : Chart::Left));
                t->destroy();
            }
        }
    }
}

void OutputChart::crossHair(XYChart *c, int mouseX, int mouseY)
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

void OutputChart::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == mTestTimerId)
    {
        mCurrentTime += (double)DataInterval/1000;
        double power = 100*sin(mCurrentTime);

        mCurveList[POWER_CURVE_ID].xSeries.push_back(mCurrentTime);
        mCurveList[POWER_CURVE_ID].ySeries.push_back(power);

        if(mTimeFrameEnable)
        {
            mMinXValue = mCurrentTime - mTimeFrame;
            mMaxXValue = mCurrentTime;
        }else
        {
            mMinXValue = 0;
        }
        replot();
    }
}

void OutputChart::scaleTimeAxis(double currentTime)
{
    if(currentTime > mMaxXValue)
    {
        mMaxXValue = currentTime;
    }
}

void OutputChart::onMouseMoveChart()
{
    if(this->mTrackAxisEnable)
    {
        drawTrackCursor(this->mpChartViewer,this->mpChartViewer->getPlotAreaMouseX());
    }
}

void OutputChart::onViewPortChanged()
{
    if (mpChartViewer->needUpdateChart())
    {
        drawChart(mpChartViewer);
    }
    if (mpChartViewer->needUpdateImageMap())
    {

    }
}

void OutputChart::onClickChart(Qt::MouseButton button)
{

}

void OutputChart::onDoubleClickChart(QMouseEvent *event)
{

}

void OutputChart::drawChart(QmlChartViewer *viewer)
{
    int width = static_cast<int>(this->width());
    int height = static_cast<int>(this->height());

    XYChart* c = new XYChart(width,height + ChartConstances::DEFAULT_LICENSE_LABEL_MARGIN, ChartConstances::DEFAULT_XY_CHART_BACKGROUND);

    int leftMargin = 60;
    int topMargin = 5;
    int rightMargin = 5;
    int bottomMargin = 70;

    int plotAreaX = static_cast<int>(this->x()) + leftMargin ; //0 left margin
    int plotAreaY = static_cast<int>(this->y()) + topMargin; //0 top margin

    int plotAreaWidth = c->getWidth() - leftMargin - rightMargin; // right margin
    int plotAreaHeight = c->getHeight() - bottomMargin; // bottom margin

    c->setPlotArea(plotAreaX,plotAreaY,plotAreaWidth,plotAreaHeight,
                   ChartConstances::DEFAULT_PLOTAREA_BACKGROUND,                              // background color
                   ChartConstances::DEFAULT_PLOTAREA_SECOND_BACKGROUND, Chart::Transparent,// second background color, edge color
                   ChartConstances::DEFAULT_GRID_COLOR, Chart::Transparent); // H-Grid color, V-Grid color

    c->setClipping();

    c->getLegend()->setLineStyleKey();
    // Set the x and y axis stems to transparent and the label font to 10pt Arial
    // Set the y-axis tick length to 0 to disable the tick and put the labels closer to the axis.
    // Configure the x-axis tick length to 1 to put the labels closer to the axis.
    c->yAxis()->setLabelGap(5);
    c->xAxis()->setLabelGap(5);
    c->yAxis()->setTickLength(ChartConstances::DEFAULT_LABLE_STICK);
    c->xAxis()->setTickLength(ChartConstances::DEFAULT_LABLE_STICK);
    c->xAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->yAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->xAxis()->setColors(ChartConstances::DEFAULT_AXIS_COLOR);
    c->yAxis()->setColors(ChartConstances::DEFAULT_AXIS_COLOR);
    c->yAxis()->setTitle("", "./fonts/Arial.ttf", 10, ChartConstances::DEFAULT_YTITLE_COLOR);
    c->xAxis()->setTitle("Time (s)", "./fonts/Arial.ttf", 10, ChartConstances::DEFAULT_XTITLE_COLOR);
    c->xAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_XLABLE_COLOR);
    c->yAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_YLABLE_COLOR);
    // Set axes width to 2 pixels
    c->xAxis()->setWidth(1);
    c->yAxis()->setWidth(1);
    // The default ChartDirector settings has a denser y-axis grid spacing and less-dense
    // x-axis grid spacing. In this demo, we want the tick spacing to be symmetrical.
    // We use around 50 pixels between major ticks and 25 pixels between minor ticks.
    c->xAxis()->setTickDensity(50);
    c->yAxis()->setTickDensity(50);

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

    scaleTimeAxis(mCurrentTime);

    viewer->setFullRange("y", mMinYValue, mMaxYValue);
    viewer->setFullRange("x", mMinXValue, mMaxXValue);
    viewer->setZoomInHeightLimit(0.0001);
    viewer->setZoomInWidthLimit(0.0001);
    viewer->syncLinearAxisWithViewPort("x", c->xAxis());
    viewer->syncLinearAxisWithViewPort("y", c->yAxis());


    // Set the chart image to the QuickChartViewer
    drawLegend(c);

    delete viewer->getChart();
    viewer->setChart(c);

    if(viewer->isMouseOnPlotArea() && this->mTrackAxisEnable)
    {
        drawTrackCursor(viewer,viewer->getPlotAreaMouseX());
    }

}

void OutputChart::drawLegend(XYChart *c)
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
    TTFText* t = d->text(legendText.str().c_str(), "./fonts/Arial.ttf", 10);
    t->draw(plotArea->getLeftX() + 5, plotArea->getTopY() - 3, 0xffffff, Chart::TopLeft);
    t->destroy();
}


