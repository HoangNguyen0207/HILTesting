#include "inputchart.h"
#include <sstream>
#include "logger/logger.h"
InputChart::InputChart(QQuickPaintedItem *parent) : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
    mpChartViewer = new QmlChartViewer(this);
    mpChartViewer->setPosition(QPointF(0,0));
    mpChartViewer->setSize(QSizeF(this->width(), this->height()));

//    connect(mpChartViewer,&QmlChartViewer::clicked,this,&TargetChartDemo::onClickChart);
    connect(mpChartViewer,&QmlChartViewer::viewPortChanged,this,&InputChart::onViewPortChanged);
//    connect(mpChartViewer,&QmlChartViewer::mouseMoveChart,this,&TargetChartDemo::onMouseMoveChart);
//    connect(mpChartViewer,&QmlChartViewer::doubleClicked,this,&TargetChartDemo::onDoubleClickChart);
//    connect(mpChartViewer,&QmlChartViewer::updateChart,this,&TargetChartDemo::updateChart);

    connect(this,&InputChart::widthChanged,this,&InputChart::slotUpdateCustomPlotSize);
    connect(this,&InputChart::heightChanged,this,&InputChart::slotUpdateCustomPlotSize);

    // Initially set the mouse to drag to scroll mode
    setMouseUsage(QmlChartViewer::MouseUsage::MouseUsageScroll);
    // Enable mouse wheel zooming by setting the zoom ratio to 1.1 per wheel event
    mpChartViewer->setMouseWheelZoomRatio(1.5);

    setZoomDirection(QmlChartViewer::Direction::HorizontalVertical);
    setScrollDirection(QmlChartViewer::Direction::HorizontalVertical);
    mpChartViewer->updateViewPort(true,true);
}

InputChart::~InputChart()
{

}

void InputChart::paint(QPainter *painter)
{

}

void InputChart::setZoomDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setZoomDirection(direction);
}

void InputChart::setScrollDirection(const QmlChartViewer::Direction &direction)
{
    mpChartViewer->setScrollDirection(direction);
}

void InputChart::setMouseUsage(const QmlChartViewer::MouseUsage &mouseUsage)
{
    mpChartViewer->setMouseUsage(mouseUsage);
}

void InputChart::fitChart(const QmlChartViewer::Direction &dir)
{

}

void InputChart::slotUpdateCustomPlotSize()
{
    drawChart(mpChartViewer);
}

void InputChart::replot()
{
    mpChartViewer->updateViewPort(true,true);
}

void InputChart::drawChart(QmlChartViewer *viewer)
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

    // Add a legend box at left side using horizontal layout. Use 10pt Arial Bold as font. Set the
    // background and border color to DEFAULT_GRID_COLOR and use line style legend key.
    // int legendX = plotAreaX + 5;
    // int legendY = plotAreaY + 3;
    // ChartDir::LegendBox *b = c->addLegend(legendX, legendY, true, "./fonts/Arial.ttf", 10);
    // b->setBackground(ChartConstances::DEFAULT_LEGEND_BACKGROND_COLOR,
    //                  ChartConstances::DEFAULT_LEGEND_BACKGROND_COLOR);
    // b->setLineStyleKey();
    // b->setFontColor(ChartConstances::DEFAULT_LEGEND_FONT_COLOR);
    // b->setAlignment(ChartDir::TopLeft);
    c->getLegend()->setLineStyleKey();
    // Set the x and y axis stems to transparent and the label font to 10pt Arial
    // Set the y-axis tick length to 0 to disable the tick and put the labels closer to the axis.
    // Configure the x-axis tick length to 1 to put the labels closer to the axis.
    c->yAxis()->setLabelGap(ChartConstances::DEFAULT_TRACKING_GRAB_DISTANCE);
    c->xAxis()->setLabelGap(ChartConstances::DEFAULT_TRACKING_GRAB_DISTANCE);
    c->yAxis()->setTickLength(ChartConstances::DEFAULT_LABLE_STICK);
    c->xAxis()->setTickLength(ChartConstances::DEFAULT_LABLE_STICK);
    c->xAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->yAxis()->setWidth(ChartConstances::DEFAULT_AXIS_WIDTH);
    c->xAxis()->setColors(ChartConstances::DEFAULT_AXIS_COLOR);
    c->yAxis()->setColors(ChartConstances::DEFAULT_AXIS_COLOR);
    c->yAxis()->setTitle("", "./fonts/Arial.ttf", 10, ChartConstances::DEFAULT_YTITLE_COLOR);
    c->xAxis()->setTitle("", "./fonts/Arial.ttf", 10, ChartConstances::DEFAULT_XTITLE_COLOR);
    c->xAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_XLABLE_COLOR);
    c->yAxis()->setLabelStyle("./fonts/Arial.ttf", 8, ChartConstances::DEFAULT_YLABLE_COLOR);
    // Set axes width to 2 pixels
    c->xAxis()->setWidth(2);
    c->yAxis()->setWidth(2);
    // The default ChartDirector settings has a denser y-axis grid spacing and less-dense
    // x-axis grid spacing. In this demo, we want the tick spacing to be symmetrical.
    // We use around 50 pixels between major ticks and 25 pixels between minor ticks.
    c->xAxis()->setTickDensity(50);
    c->yAxis()->setTickDensity(50);

    viewer->setFullRange("y", mMinYValue, mMaxYValue);
    viewer->setFullRange("x", mMinXValue, mMaxXValue);
    viewer->setZoomInHeightLimit(0.000001);
    viewer->setZoomInWidthLimit(0.000001);
    viewer->syncLinearAxisWithViewPort("x", c->xAxis());
    viewer->syncLinearAxisWithViewPort("y", c->yAxis());

    // We need to update the track line too.
    //    if(currentIndex > 0)
    //        trackLineLabel(c);

    // Set the chart image to the QuickChartViewer
    drawLegend(c);
    delete viewer->getChart();
    viewer->setChart(c);
}

void InputChart::drawLegend(XYChart *c)
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

void InputChart::updateControls(QmlChartViewer *viewer)
{
    Q_UNUSED(viewer)
}

void InputChart::updateImageMap(QmlChartViewer *viewer)
{
    Q_UNUSED(viewer)
}

void InputChart::reFindMinMaxYValue()
{

}

void InputChart::updateChart()
{

}

void InputChart::onMouseMoveChart(QMouseEvent *event)
{

}

void InputChart::onViewPortChanged()
{
    // In addition to updating the chart, we may also need to update other controls that
    // changes based on the view port.
    updateControls(mpChartViewer);
    // Update the chart if necessary
    if (mpChartViewer->needUpdateChart())
    {
        drawChart(mpChartViewer);
    }
    if (mpChartViewer->needUpdateImageMap())
    {
        updateImageMap(mpChartViewer);
    }
}

void InputChart::onClickChart(QMouseEvent *event)
{

}

void InputChart::onDoubleClickChart(QMouseEvent *event)
{

}

void InputChart::updateAndDraw()
{
    replot();
}
