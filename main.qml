import Qt.labs.platform 1.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import "ui/components" as CMN
import "ui/singletons" as SGT
import "ui/modules" as MDL
import "ui/maps" as MAP
import "ui/dialogs" as DLG
import Flux 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1400
    height: 800
    x: Screen.desktopAvailableWidth/2 - mainWindow.width/2
    y: Screen.desktopAvailableHeight/2 - mainWindow.height/2
    title: qsTr("HILTesting")
    flags: Qt.FramelessWindowHint

    menuBar: CMN.MaterialMenuBar {
        Menu {
            title: "General"
            Action
            {
                text: "Connection"
                onTriggered:
                {
                    connectionDialogId.open()
                }
            }

            Action
            {
                text: "Exit"
                onTriggered:
                {
                    Qt.quit()
                }
            }
        }
    }

    Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: SGT.Style.gray_20

        MDL.ControlModule
        {
            id: controlId
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.bottom: recFooterId.top
            width: 350
        }

        Rectangle
        {
            id: viewRecId
            anchors.top: parent.top
            anchors.left: controlId.right
            anchors.right: parent.right
            anchors.bottom: recFooterId.top
            color: "transparent"
            Item
            {
                id: deviceMonitorItemId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 10
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                height: 260
                MDL.FMSMonitor
                {
                    id: fmsMonitorId
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    width: parent.width/10 * 6
                }
                MDL.TMSMonitor
                {
                    id: tmsMonitorId
                    anchors.top: parent.top
                    anchors.left: fmsMonitorId.right
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    anchors.leftMargin: 5
                }
            }
            StackLayout
            {
                id: stackMapId
                anchors.top: deviceMonitorItemId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 10
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                currentIndex: MainStore.plotMapMode
                MAP.ProcessMap
                {
                    id: processMapId
                    anchors.fill: parent
                }
                MAP.BodeMap
                {
                    id: bodeMapId
                    anchors.fill: parent
                }
            }
        }

        Rectangle
        {
            id: recFooterId
            color: SGT.Style.backgroundColorLightDark
            height: 45
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            MDL.StatusBar
            {
                id: statusBarId
                anchors.fill: parent
                anchors.topMargin: 10
                anchors.bottomMargin: 10
                anchors.leftMargin: 0
            }
        }
    }

    DLG.ConnectionDialog
    {
        id: connectionDialogId
    }

    DLG.LaserTrackerDialog
    {
        id: laserDialogId
        visible: MainStore.laserTrackerDialogShowFlag
    }
}
