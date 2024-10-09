pragma Singleton
import QtQuick 2.0
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.12

QtObject
{
    readonly property color defineColor: "#0052cc"
    readonly property color accentColor: "#54CA75"
    readonly property color accentColorDarker: Qt.lighter("#54CA75",0.8)
    readonly property color accentColorLighter: Qt.lighter("#54CA75",1.2)
    readonly property color indicatorColor: "#54CA75"
    readonly property color hightlineColor: "orange"
    readonly property color textColorGray: "#808080"
    readonly property color textColor: "#d3d3d3"
    readonly property color textColorBlack: "black"
    readonly property color hightTextColor: "#ffffff"
    readonly property color redColor: "#da1425"
    readonly property color redColorDarker: Qt.lighter("#da1425",0.8)
    readonly property color yellowColor: "#FFC500"
    readonly property color yellowColorDarker: Qt.lighter("#FFC500",0.8)
    readonly property color disableColor: "#808080"
    readonly property color backgroundColorDark: "#1a1a1a"
    readonly property color backgroundColorLightDark: "#2d2d2d"
    readonly property color backgroundColor: "#3d3d3d"
    readonly property color backgroundColorLight: "#4d4d4d"
    readonly property color dialogBackgroundColor: "#001a33"
    readonly property color dialogBorderColor: "#666666"
    readonly property color dialogBorderColorLight: "white"
    readonly property color dialogBorderColorBlack: "black"
    readonly property color footerBackground: "#001a33"
    readonly property color headerBackground: "#001a33"
    readonly property color checkedButton: "#0052cc"
    readonly property color uncheckedButton: "#003566"
    readonly property color connectedStatusColor: "#005ce6"
    readonly property color disconnectedStatusColor: "gray"
    readonly property color buttonBackgroundColor: "#004280"
    readonly property color deviceEnableColor: "#FFC500"
    readonly property color deviceControlOnColor: "#0052cc"
    readonly property color deviceHomingDoneColor: "#00CC00"

    readonly property color gray_10: "#E6E6E5"
    readonly property color gray_15: "#DAD9D8"
    readonly property color gray_20: "#CECDCA"
    readonly property color gray_25: "#C1C0BD"
    readonly property color gray_30: "#B5B4B0"
    readonly property color gray_35: "#A8A7A3"
    readonly property color gray_40: "#9C9B96"
    readonly property color gray_45: "#908E89"
    readonly property color gray_50: "#83817C"
    readonly property color gray_55: "#76746F"
    readonly property color gray_60: "#696863"
    readonly property color gray_65: "#5C5B57"
    readonly property color gray_70: "#4F4E4A"
    readonly property color gray_725: "#484744"
    readonly property color gray_75: "#42413E"
    readonly property color gray_775: "#3B3A38"
    readonly property color gray_80: "#353431"
    readonly property color gray_825: "#2E2D2B"
    readonly property color gray_85: "#272725"
    readonly property color gray_875: "#21201F"
    readonly property color gray_90: "#1A1A19"
    readonly property color gray_95: "#0D0D0C"

    readonly property int smallFontPixelSize: 14
    readonly property int normalFontPixelSize: 16
    readonly property int largeFontPixelSize: 20

    readonly property string channel0Off: "Channel 0 - Off"
    readonly property string channel0Delay: "Channel 0 - Delay"
    readonly property string channel0FalseTarget: "Channel 0 - FalseTarget"
    readonly property string channel0Jamming: "Channel 0 - Jamming"
    readonly property string channel0RGPIO: "Channel 0 - RGPIO"
    readonly property string channel0VGPIO: "Channel 0 - VGPIO"

    readonly property string channel1Off: "Channel 1 - Off"
    readonly property string channel1Delay: "Channel 1 - Delay"
    readonly property string channel1FalseTarget: "Channel 1 - FalseTarget"
    readonly property string channel1Jamming: "Channel 1 - Jamming"
    readonly property string channel1RGPIO: "Channel 1 - RGPIO"
    readonly property string channel1VGPIO: "Channel 1 - VGPIO"

    readonly property int screenWidth: Screen.desktopAvailableWidth
    readonly property int screenHeight: Screen.desktopAvailableHeight

    readonly property FontLoader fontRegular: FontLoader {
        name: "Play Bold"
        source: "qrc:/ui/resources/font/Arial.ttf"
    }

    readonly property FontLoader fontBold: FontLoader {
        name: "Play Regular"
        source: "qrc:/ui/resources/font/Arial_Bold.ttf"
    }

    readonly property FontLoader fontItalic: FontLoader {
        name: "Play Regular"
        source: "qrc:/ui/resources/font/Arial_Italic.ttf"
    }

    readonly property FontLoader fontBoldItalic: FontLoader {
        name: "Play Regular"
        source: "qrc:/ui/resources/font/Arial_Bold_Italic.ttf"
    }
}
