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
    width: 600

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
            id: txMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/6 - 5
            CMN.MaterialValueDisplayCompact
            {
                id: txPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Tx Pos"
                unit: "m"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: txVelMonitorId
                anchors.top: txPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Tx Vel"
                unit: "m/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: txAccMonitorId
                anchors.top: txVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Tx Acc"
                unit: "m/s2"
                value: "0"
                hPadding: 5
            }
        }
        Column
        {
            id: tyMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: txMonitorColId.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/6 - 5
            CMN.MaterialValueDisplayCompact
            {
                id: tyPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Ty Pos"
                unit: "m"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tyVelMonitorId
                anchors.top: tyPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Ty Vel"
                unit: "m/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tyAccMonitorId
                anchors.top: tyVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Ty Acc"
                unit: "m/s2"
                value: "0"
                hPadding: 5
            }
        }
        Column
        {
            id: tzMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: tyMonitorColId.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/6 - 5
            CMN.MaterialValueDisplayCompact
            {
                id: tzPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Tz Pos"
                unit: "m"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tzVelMonitorId
                anchors.top: tzPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Tz Vel"
                unit: "m/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: tzAccMonitorId
                anchors.top: tzVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Tz Acc"
                unit: "m/s2"
                value: "0"
                hPadding: 5
            }
        }
        Column
        {
            id: rxMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: tzMonitorColId.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/6 - 5
            CMN.MaterialValueDisplayCompact
            {
                id: rxPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Rx Pos"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: rxVelMonitorId
                anchors.top: rxPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Rx Vel"
                unit: "deg/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: rxAccMonitorId
                anchors.top: rxVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Rx Acc"
                unit: "deg/s2"
                value: "0"
                hPadding: 5
            }
        }
        Column
        {
            id: ryMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: rxMonitorColId.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            width: parent.width/6 - 5
            CMN.MaterialValueDisplayCompact
            {
                id: ryPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Ry Pos"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: ryVelMonitorId
                anchors.top: ryPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Ry Vel"
                unit: "deg/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: ryAccMonitorId
                anchors.top: ryVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Ry Acc"
                unit: "deg/s2"
                value: "0"
                hPadding: 5
            }
        }
        Column
        {
            id: rzMonitorColId
            anchors.top: axisLblId.bottom
            anchors.topMargin: 5
            anchors.left: ryMonitorColId.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            CMN.MaterialValueDisplayCompact
            {
                id: rzPosMonitorId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height/3 - 3
                name: "Rz Pos"
                unit: "deg"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: rzVelMonitorId
                anchors.top: rzPosMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                height: parent.height/3 - 3
                name: "Rz Vel"
                unit: "deg/s"
                value: "0"
                hPadding: 5
            }
            CMN.MaterialValueDisplayCompact
            {
                id: rzAccMonitorId
                anchors.top: rzVelMonitorId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.topMargin: 5
                name: "Rz Acc"
                unit: "deg/s2"
                value: "0"
                hPadding: 5
            }
        }
    }
}
