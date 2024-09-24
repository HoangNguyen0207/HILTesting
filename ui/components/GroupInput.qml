import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Rectangle
{
    id: root
    color: "transparent"
    border.color: "transparent"
    border.width: 1
    radius: 0
    property int header: 30
    property string title: "GroupBox"
    property alias recHeader: headerId
    property int titleSize: SGT.Style.normalFontPixelSize
    property color titleColor: SGT.Style.textColor
    property color lineColor: SGT.Style.dialogBorderColor
    Rectangle
    {
        id: headerId
        height: root.header
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        radius: 0
        color: SGT.Style.dialogBackgroundColor
        border.width: 0
        border.color: "#666666"
        Label
        {
            text: root.title
            anchors.fill: parent
            font.bold: true
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            leftPadding: 5
            font.pixelSize: root.titleSize
            color: root.titleColor
            Rectangle
            {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                height: 1
                color: root.lineColor
            }
        }
    }
}
