import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN

Popup {
    id: root
    width: 140
    height: 80
    modal: false
    padding: 0
    closePolicy: Popup.NoAutoClose

    property alias deltaXValue: deltaXId.text
    property alias deltaYValue: deltaYId.text

    background: Rectangle
    {
        id: recBkgId
        color: SGT.Style.backgroundColorLight
        anchors.fill: parent
        radius: 0
    }

    Label
    {
        id: deltaXId
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height / 2
        text: "delta X = 100.000"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font.pixelSize: 14
        leftPadding: 10
    }
    Label
    {
        id: deltaYId
        anchors.top: deltaXId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: "delta Y = 100.000"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font.pixelSize: 14
        leftPadding: 10
    }
}
