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
    height: 95
    modal: false
    padding: 0
    closePolicy: Popup.CloseOnReleaseOutside

    property alias zoomAllBtn: zoomAllId
    property alias zoomHorizontalBtn: zoomHorizontalId
    property alias zoomVerticalBtn: zoomVerticalId

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
        height: parent.height/3 - 1
        font.bold: false
        horizontalAlignment: Text.AlignLeft
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
        height: parent.height/3 - 1
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }
    CMN.MaterialButton
    {
        id: zoomVerticalId
        anchors.top: zoomHorizontalId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        anchors.bottomMargin: 1
        text: "Zoom vertical"
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }
}
