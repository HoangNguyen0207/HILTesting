import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.12
import "../singletons" as SGT
Control {
    id: root
    width: 200
    height: 30
    text: "Connect"
    leftPadding: 5
    property color backgroundColor: "#0052cc"
    property alias border: recBkgId.border
    property alias iconImg: iconId.source
    property alias iconSize: iconId.size
    property alias text: labelId.text
    property alias textSize: labelId.font.pixelSize

    background: Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: root.backgroundColor
        border.width: 0
        border.color: "white"
        radius: 0
    }

    contentItem: RowLayout
    {
        id: row
        anchors.verticalCenter: parent.verticalCenter
        layoutDirection: Qt.LeftToRight
        spacing: 5

        IconImg
        {
            id: iconId
            Layout.alignment: Qt.AlignCenter
        }

        Label
        {
            id: labelId
            Layout.alignment: Qt.AlignCenter
            text: root.text
            Layout.fillWidth: true
            color: "white"
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 14
        }
    }
}
