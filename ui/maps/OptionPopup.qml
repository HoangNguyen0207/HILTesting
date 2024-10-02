import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN

Popup {
    id: root
    width: 160
    height: 185
    modal: false
    padding: 0
    closePolicy: Popup.CloseOnReleaseOutside

    property alias zoomAllBtn: zoomAllId
    property alias zoomHorizontalBtn: zoomHorizontalId
    property alias zoomVerticalBtn: zoomVerticalId
    property alias distanceBtn: distanceId
    property alias imageBtn: imageId
    property alias resetBtn: resetId
    property alias fmsShowBtn: fmsId
    property alias tmsShowBtn: tmsId
    property int optionNumber: 8

    background: Rectangle
    {
        id: recBkgId
        color: SGT.Style.gray_20
        anchors.fill: parent
        radius: 0
    }
    CMN.MaterialButton
    {
        id: zoomAllId
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "Zoom all"
        height: parent.height/root.optionNumber - 1
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: zoomHorizontalId
        anchors.top: zoomAllId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "Zoom horizontal"
        height: parent.height/root.optionNumber - 1
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: zoomVerticalId
        anchors.top: zoomHorizontalId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "Zoom vertical"
        height: parent.height/root.optionNumber - 1
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: distanceId
        anchors.top: zoomVerticalId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        height: parent.height/root.optionNumber - 1
        text: "Distance"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: imageId
        anchors.top: distanceId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height/root.optionNumber - 1
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "Image"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: resetId
        anchors.top: imageId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height/root.optionNumber - 1
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "Reset"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: fmsId
        anchors.top: resetId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height/root.optionNumber - 1
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        text: "FMS"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }
    CMN.MaterialButton
    {
        id: tmsId
        anchors.top: fmsId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        anchors.bottomMargin: 1
        text: "TMS"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        Material.background: SGT.Style.gray_20
        textColor: "black"
    }

}
