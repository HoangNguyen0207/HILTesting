#pragma once

#include "chartdir.h"
#include <QString>
#include <QMap>

struct CurveDataSeries
{
        int id {0};
        std::string name {""};
        std::vector<double> xSeries;
        std::vector<double> ySeries;
        bool needToDraw {false};
        bool needToShow {false};
        int color {-1};
        double minXValue {0};
        double maxXValue {0};
        double minYValue {0};
        double maxYValue {0};
        bool isDashLine {false};
        int symbolSize {10};
        int lineWidth {1};
        Chart::SymbolType symbol{Chart::SymbolType::NoSymbol};
};

class ChartConstances
{
    public:
        static constexpr int DEFAULT_CHART_UPDATE_INTERVAL  = 500;   // Default chart update interval [ms]
        static constexpr int MINIMUM_CHART_UPDATE_INTERVAL  = 10;    // Default chart update interval [ms]
        static constexpr int DEFAULT_SAMPLE_SIZE            = 10000; // The number of samples per data series
        static constexpr int DEFAULT_FULL_RANGE             = 60;    // The initial full range is set to 60 seconds of data.
        static constexpr int DEFAULT_ZOOM_IN_LIMIT          = 1;     // The maximum zoom in is 10 seconds.
        static constexpr int DEFAULT_LINE_WIDTH             = 1;
        static constexpr int HIDE_LINE_WIDTH                = 0;
        static constexpr int DEFAULT_XLABLE_AREA            = 75;
        static constexpr int DEFAULT_YLABLE_AREA            = 100;
        static constexpr int DEFAULT_TITLE_AREA             = 20;
        static constexpr int DEFAULT_LICENSE_LABEL_MARGIN       = 20;
        static constexpr int DEFAULT_PLOTAREA_LEFT_MARGIN       = DEFAULT_YLABLE_AREA;
        static constexpr int DEFAULT_PLOTAREA_TOP_MARGIN        = DEFAULT_TITLE_AREA;
        static constexpr int DEFAULT_PLOTAREA_RIGHT_MARGIN      = 20;
        static constexpr int DEFAULT_PLOTAREA_BOTTOM_MARGIN     = DEFAULT_XLABLE_AREA;
        static constexpr int DEFAULT_XY_CHART_BACKGROUND        = 0x2d2d2d/*0x1e1e1e*/;
        static constexpr int DEFAULT_PLOTAREA_BACKGROUND        = 0x001a33/*0x000d1a*//*0x212121*/;
        static constexpr int DEFAULT_PLOTAREA_SECOND_BACKGROUND = 0x001a33/*0x000d1a*//*0x232323*/;
        static constexpr int DEFAULT_GRID_COLOR   = 0x2f2f2f;
        static constexpr int DEFAULT_H_GRID_COLOR   = 0x2f2f2f;
        static constexpr int DEFAULT_V_GRID_COLOR   = 0x2f2f2f;
        static constexpr int DEFAULT_XLABLE_COLOR = 0x000000/*0xf0f0f0*/;
        static constexpr int DEFAULT_YLABLE_COLOR = 0x000000/*0xf0f0f0*/;
        static constexpr int DEFAULT_XTITLE_COLOR = 0x000000/*0xf0f0f0*/;
        static constexpr int DEFAULT_YTITLE_COLOR = 0x000000/*0xf0f0f0*/;
        static constexpr int DEFAULT_LEGEND_FONT_COLOR = 0xf0f0f0;
        static constexpr int DEFAULT_LEGEND_BACKGROUND_COLOR = 0x2f2f2f;
        static constexpr int DEFAULT_PLOTAREA_EDGE_COLOR = 0x666666;
        // The mouse can drag the track line if it is within the GrabDistance to the line.
        static constexpr int DEFAULT_TRACKING_GRAB_DISTANCE = 8;
        static constexpr int DEFAULT_LABLE_STICK = 4;
        static constexpr int DEFAULT_AXIS_WIDTH = 2;
        static constexpr int DEFAULT_AXIS_COLOR = 0x444444;

};
