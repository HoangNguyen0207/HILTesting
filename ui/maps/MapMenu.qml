import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN


Menu {
    id: root
    modal: false
    padding: 0
    closePolicy: Popup.CloseOnReleaseOutside
    property alias zoomAllAction: zoomAllActionId
    property alias zoomHorizontalAction: zoomHorizontalActionId
    property alias zoomVerticalAction: zoomVerticalActionId
    property alias distanceAction: distanceActionId
    property alias imageAction: imageActionId
    property alias resetAction: resetActionId
    property alias whiteModeAction: whiteActionId
    property alias fmsShowAction: fmsShowActionId
    property alias tmsShowAction: tmsShowActionId

    Action
    {
        id: zoomAllActionId
        text: "Zoom all"
    }
    Action
    {
        id: zoomHorizontalActionId
        text: "Zoom horizontal"
    }
    Action
    {
        id: zoomVerticalActionId
        text: "Zoom vertical"
    }
    Action
    {
        id: distanceActionId
        text: "Distance"
    }
    Action
    {
        id: imageActionId
        text: "Image"
    }
    Action
    {
        id: resetActionId
        text: "Reset"
    }
    Action
    {
        id: whiteActionId
        text: "WhiteMode"
    }
    Menu
    {
        title: "Show"
        Action
        {
            id: fmsShowActionId
            text: "FMS"
        }
        Action
        {
            id: tmsShowActionId
            text: "TMS"
        }
    }

}
