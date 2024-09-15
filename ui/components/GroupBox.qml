import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Rectangle
{
    id: root
    border.width: 1
    color: Qt.lighter(SGT.Style.backgroundColorDark, 1.4)
    property string title: "GroupBox"
    property int header: 30
    property alias recHeader: headerId
    property int titleSize: SGT.Style.normalFontPixelSize
    property color titleColor: SGT.Style.yellowColor
    property alias recHeaderColor: headerId.color

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
        border.width: 1
        color: SGT.Style.backgroundColorLight

        Rectangle
        {
            id: hightlightId
            height: 1
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 1
            anchors.rightMargin: 1
        }

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
        }
    }
}
