import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../components" as CMN
import "../singletons" as SGT
import Chart 1.0

Item {
    id: root

    property color backgroundColor: SGT.Style.gray_10
    property alias map: mapId

    Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: root.backgroundColor
        TrajectoryMap
        {
            id: mapId
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            Rectangle
            {
                id: hideLicenseRecId
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 20
                color: "white"
            }
            MouseArea
            {
                id: mouseMapId
                anchors.fill: parent
                acceptedButtons: Qt.RightButton
                onClicked:
                {
                    if(mouse.button === Qt.RightButton)
                    {
                        mapMenuId.x = mouseX
                        mapMenuId.y = mouseY
                        mapMenuId.open()
                    }
                }
            }
        }
    }

    DistancePopup
    {
        id: distancePopupId
        x: mapId.x + mapId.width - distancePopupId.width - 14
        y: mapId.y + 15
        deltaXValue: "delta X = " + mapId.deltaX.toFixed(3)
        deltaYValue: "delta Y = " + mapId.deltaY.toFixed(3)
    }

    MapMenu
    {
        id: mapMenuId
        zoomAllAction.onTriggered:
        {
            mapId.setZoomDirection(Chart.HorizontalVertical)
        }
        zoomHorizontalAction.onTriggered:
        {
            mapId.setZoomDirection(Chart.Horizontal)
        }
        zoomVerticalAction.onTriggered:
        {
            mapId.setZoomDirection(Chart.Vertical)
        }
        distanceAction.onTriggered:
        {
            mapId.onDistanceCalcModeTriggered()
            if(!distancePopupId.visible)
            {
                distancePopupId.open()
            }else
            {
                distancePopupId.close()
            }
        }
        imageAction.onTriggered:
        {
            mapId.onCreateImageTriggered("save")
        }
        resetAction.onTriggered:
        {
            mapId.onResetMapTriggered()
        }
        fmsShowAction.onTriggered:
        {
            mapId.onFmsTxShowFlagChanged()
            mapId.onFmsTyShowFlagChanged()
            mapId.onFmsTzShowFlagChanged()
            mapId.onFmsRxShowFlagChanged()
            mapId.onFmsRyShowFlagChanged()
            mapId.onFmsRzShowFlagChanged()
        }
        tmsShowAction.onTriggered:
        {
            mapId.onTmsTxShowFlagChanged()
            mapId.onTmsTyShowFlagChanged()
            mapId.onTmsRxShowFlagChanged()
            mapId.onTmsRyShowFlagChanged()
        }
    }
}
