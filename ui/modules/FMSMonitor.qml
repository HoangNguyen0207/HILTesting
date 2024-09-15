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
            text: "FMS Monitor"
            font.bold: true
            font.pixelSize: SGT.Style.normalFontPixelSize
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            color: SGT.Style.textColorBlack
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
        Column
        {
            id: transitionColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/2 - 2
            CMN.MaterialValueDisplayCompact
            {
                id: txMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Tx"
                unit: "m"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tyMonitorId
                anchors.top: txMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Ty"
                unit: "m"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tzMonitorId
                anchors.top: tyMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Tz"
                unit: "m"
                value: "0"
                hPadding: 5
            }
        }

        Column
        {
            id: rotationColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: transitionColId.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            CMN.MaterialValueDisplayCompact
            {
                id: rxMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Rx"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: ryMonitorId
                anchors.top: rxMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Ry"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: rzMonitorId
                anchors.top: ryMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Rz"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
        }

    }
}
