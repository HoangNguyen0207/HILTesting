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
    width: 220
    height: 40

    property color backgroundColor: "#1a1a1a"
    property int radius: 0
    property alias name: labField.text
    property alias value: textField.text
    property alias unit: labUnit.text
    property color hightLineColor: "transparent"
    property color hightLineHoverColor: "transparent"
    property string defaultValue: qsTr("0")
    property color colorname: "black"
    property color colorunit: "black"

    Label
    {
        id: labField
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: parent.width * 1.8/5
        text: "RANGE:"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
        font.bold: false
        color: root.colorname
    }

    TextField
    {
        id: textField
        width: parent.width * 2.2/5
        font.pixelSize: 16
        color: "white"
        text: "0"
        anchors.top: parent.top
        anchors.left: labField.right
        anchors.bottom: parent.bottom
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        topPadding: 0
        bottomPadding: 0
        leftPadding: 10
        background: Rectangle
        {
            id: textBkgId
            anchors.fill: parent
            color: root.backgroundColor
        }
    }

    Label
    {
        id: labUnit
        anchors.top: parent.top
        anchors.left: textField.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: "m"
        font.pixelSize: 14
        font.bold: false
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        color: root.colorunit
        leftPadding: 5
    }

    Rectangle
    {
        id: hightlight
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 1
        color: root.hightLineColor
    }

    states: [
        State {
            name: "disable"
            PropertyChanges {
                target: textField
                color: "gray"
            }
            PropertyChanges {
                target: labField
                color: "gray"
            }
            PropertyChanges {
                target: labUnit
                color: "gray"
            }
        },
        State {
            name: "Hovering"
            PropertyChanges {
                target: hightlight
                color: root.hightLineHoverColor
                height: 1
            }
        },
        State {
            name: "Focused"
            PropertyChanges {
                target: hightlight
                color: root.hightLineColor
                height: 1
            }
        }
    ]

    onEnabledChanged: {
        if(root.enabled) root.state = ""
        else root.state = "disable"
    }

    onFocusChanged: {
        if(root.focus)
        {
            root.state = "Focused";
        }
        else
        {
            root.state = ""
        }
    }

    onHoveredChanged: {
        if(root.hovered) root.state = "Hovering"
        else{
            if(root.focus)
            {
                root.state = "Focused";
            }
            else
            {
                root.state = ""
            }
        }
    }
}
