import QtQuick 2.0
import QtQuick.Controls 2.12

Control
{
    id: ledIndicatorId
    width: 140
    height: 30

    states: State
    {
        name: "Disable"
        PropertyChanges {
            target: ledIndicatorId
            color: "gray"
        }
    }

    property color activedColor: "orange"
    property bool indicatorRight: false
    property int indicatorSize: 30
    property int indicatorRadius: 0
    property string text: "Indicator"
    property color textColor: "black"
    property color color: "gray"
    property bool actived: false

    state: ledIndicatorId.enabled ? "" : "Disable"
    focusPolicy: Qt.NoFocus
    contentItem: Row
    {
        id: rowId
        layoutDirection: ledIndicatorId.indicatorRight ? Qt.RightToLeft : Qt.LeftToRight
        spacing: 6
        Rectangle
        {
            id: indicatorId
            anchors.verticalCenter: parent.verticalCenter
            height: ledIndicatorId.indicatorSize
            width: ledIndicatorId.indicatorSize
            radius: ledIndicatorId.indicatorRadius
            color: ledIndicatorId.actived ? ledIndicatorId.activedColor : ledIndicatorId.color
        }

        Label
        {
            id: labelId
            anchors.verticalCenter: parent.verticalCenter
            font: ledIndicatorId.font
            color: ledIndicatorId.textColor
            text: ledIndicatorId.text
        }
    }
}
