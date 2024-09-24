import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import "../singletons" as SGT

CheckBox {
    id: checkBoxId
    width: 70
    height: 30
    font.pixelSize: 16
    font.bold: false
    text: "Checkbox"
    Material.background: "#339966"
    hoverEnabled: true
    focusPolicy: Qt.StrongFocus
    leftPadding: 0
    property color hightlineColor: "#4D4D4D"
    property int hightlineHeight: 1
    property color hightlineColorHovered: "gray"
    property int hightlineHeightHovered: 1
    property int radius: 0
    property bool hightlineVisible: true
    property color hoverColor: Qt.lighter(checkBoxId.Material.backgroundColor,1.1)
    state: checkBoxId.enabled ? "" : "Disable"

    background: Rectangle
    {
        anchors.fill: checkBoxId
        radius: checkBoxId.radius
        color: checkBoxId.hovered ? hoverColor : checkBoxId.Material.backgroundColor
    }

    contentItem: Text
    {
        id: txtContentId
        text: parent.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.left: indicator.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        font: parent.font
        color: checkBoxId.enabled || checkBoxId.pressed ? SGT.Style.textColor : "gray"
        wrapMode: Text.Wrap
    }

    Rectangle
    {
        id: recHightLineId
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        height: checkBoxId.hovered ? checkBoxId.hightlineHeightHovered : checkBoxId.hightlineHeight
        color: checkBoxId.hovered || checkBoxId.focus ? checkBoxId.hightlineColorHovered : checkBoxId.hightlineColor
        visible: checkBoxId.hightlineVisible
    }

    states: State
    {
        name: "Disable"
        PropertyChanges {
            target: object

        }
        PropertyChanges {
            target: object

        }
    }
}
