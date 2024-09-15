import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import "../singletons" as SGT
import "../components" as CMN

Item {
    id: root
    height: 300
    width: 300

    property string axisTitle: ""
    property color axisTitleColor: "black"
    property int valueInputHeight: 55

    Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        border.width: 1
        border.color: SGT.Style.gray_40
        Label
        {
            id: axisLblId
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 35
            text: "Gimbal Monitor"
            font.bold: true
            font.pixelSize: SGT.Style.normalFontPixelSize
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            color: root.axisTitleColor
            leftPadding: 10
            background: Rectangle
            {
                anchors.fill: parent
                color: "transparent"
                Rectangle
                {
                    color: "gray"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    height: 2
                }
            }
        }
        CMN.MaterialValueDisplayCompact
        {
            id: aziMonitorId
            anchors.top: axisLblId.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 5
            anchors.topMargin: 5
            anchors.rightMargin: 5
            height: (parent.height - 35)/2 - 5
            name: "Azi"
            unit: "deg"
            value: "0"
            hPadding: 5
        }
        CMN.MaterialValueDisplayCompact
        {
            id: elvMonitorId
            anchors.top: aziMonitorId.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 5
            anchors.topMargin: 5
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            name: "Elv"
            unit: "deg"
            value: "0"
            hPadding: 5
        }
    }
}
