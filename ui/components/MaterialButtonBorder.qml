import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Button
{
    id: root
    width: 200
    height: 40
    text: "Connect"
    state: root.getState()

    property alias radius: recBkgId.radius
    property color backgroundColor: "#1a1a1a"
    property alias iconImg: iconId.source
    property alias iconSize: iconId.size
    property alias border: recBkgId.border
    property color hoverColor: SGT.Style.checkedButton
    property alias horizontalTextAlign: labelId.horizontalAlignment

    function getState()
    {
        if(root.enabled)
        {
            if(root.hovered)
            {
                return "Hovered"
            }else if(root.pressed)
            {
                return "Pressed"
            }
            return ""
        }

        return "Disable"
    }

    function getbackgroundColor(){

        if(root.pressed) return Qt.lighter(root.hoverColor,0.2)
        else if(root.hovered) return Qt.lighter(root.hoverColor,1)
        else return root.backgroundColor
    }

    background: Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: root.getbackgroundColor()
        border.width: 1
        border.color: "#666666"
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
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
            font: root.font
            color: root.pressed ? "gray" : "white"
            wrapMode: root.wrapText ? Text.Wrap : Text.NoWrap
        }
    }

    states:[
        State
        {
            name: "Disable"
            PropertyChanges {
                target: labelId
                color: Qt.lighter("gray",1.2)
            }
            PropertyChanges {
                target: recBkgId
                color: Qt.lighter("gray",1)
            }
        },
        State {
            name: "Hovered"
            PropertyChanges {
                target: recBkgId
                color: root.hoverColor
            }
        }
    ]
}

