import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import "../singletons" as SGT

ComboBox
{
    id: cbxId
    currentIndex: 0
    rightPadding: 0
    hoverEnabled: true
    font.pixelSize: SGT.Style.normalFontPixelSize
    font.bold: true
    Material.background: SGT.Style.buttonBackgroundColor
    state: cbxId.enabled ? "" : "Disable"
    editable: false
    property int radius: 0
    property int hightLineWidth: 1
    property int hightLineHoverWidth: 2
    property color hightLineColor: "transparent"
    property color hightLineHoverColor: "transparent"
    property color hoverColor: Qt.lighter(cbxId.Material.backgroundColor,1.1)
    property alias txtHorizontalAlign: txtContentId.horizontalAlignment
    property alias txtVerticalAlign: txtContentId.verticalAlignment

    background: Rectangle
    {
        id: recId
        anchors.fill: parent
        radius: cbxId.radius
        color: cbxId.hovered ? hoverColor : cbxId.Material.backgroundColor
        Rectangle
        {
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            height: cbxId.hovered ? cbxId.hightLineHoverWidth : cbxId.hightLineWidth
            color: cbxId.hovered || cbxId.focus ? cbxId.hightLineHoverColor : cbxId.hightLineColor
        }
    }

    contentItem: Text
    {
        id: txtContentId
        text: cbxId.displayText
        anchors.right: parent.right
        anchors.rightMargin: cbxId.rightPadding
        anchors.left: parent.left
        anchors.leftMargin: cbxId.leftPadding
        anchors.bottom: parent.bottom
        anchors.bottomMargin: cbxId.bottomPadding
        anchors.top: parent.top
        anchors.topMargin: cbxId.topPadding
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font: cbxId.font
        color: cbxId.pressed ? "white" : "white"
        wrapMode: Text.Wrap
    }

    popup: Popup
    {
        width: cbxId.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView
        {
            implicitHeight: contentHeight
            model: cbxId.popup.visible ? cbxId.delegateModel : ""
            ScrollIndicator
            {
                id: verticalIndiatorId
                orientation: Qt.Vertical
            }
        }

        background: Rectangle
        {
            color: Qt.lighter(cbxId.Material.backgroundColor,1.5)
            radius: cbxId.radius
        }
    }

    delegate: ItemDelegate
    {
        width: cbxId.width
        anchors.leftMargin: 0
        contentItem: Text {
            text: modelData
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: cbxId.Material.foreground
            font: cbxId.font
        }
        highlighted: cbxId.highlightedIndex === index
    }

    indicator: Canvas
    {
        id: canvasId
        width: 12
        height: 8
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.verticalCenter: parent.background.verticalCenter
        contextType: "2d"

//        Connections
//        {
//            target: cbxId
//            onPressedChanged: canvasId.requestPaint()
//        }

        onPaint:
        {
            context.reset();
            context.moveTo(0,0);
            context.lineTo(width,0);
            context.lineTo(width/2, height);
            context.closePath();
            context.fillStyle = cbxId.pressed ? "black" : "black";
            context.fill();
        }
    }

    states:State
    {
        name: "Disable"
        PropertyChanges {
            target: txtContentId
            color: Qt.lighter("gray",1.2)
        }
        PropertyChanges {
            target: recId
            color: Qt.lighter("gray",0.6)
        }
    }
}


























