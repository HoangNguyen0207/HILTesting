import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.0
import "../components" as CMN
import "../singletons" as SGT

TextField{
    id: textField
    width: 140
    height: 60
    font.pixelSize: 19
    color: "white"/*"#cac735"*/
    text: defaultValue
    rightPadding: 0
    leftPadding: 0
    bottomPadding: 22
    topPadding: 0

    property color backgroundColor: SGT.Style.gray_10
    property int radius: 0
    property alias name: labField.text
    property alias value: textField.text
    property alias unit: labUnit.text
    property color hightLineColor: "transparent"
    property color hightLineHoverColor: "transparent"
    property string defaultValue: qsTr("0")
    property color colorname: "black"
    property color colorunit: SGT.Style.gray_60
    property int sizeTextName: 16
    property int sizeTextUnit: 12
    selectByMouse: true
//    validator: RegExpValidator{
//        regExp: /^(?:[1-9][0-9]{1,2}|[0-9])(?:\.[0-9]{1,3})?/
//    }
    background: Rectangle{
        id: rectangle
        color: textField.backgroundColor
        radius: textField.radius
        anchors.fill: parent

        Label{
            id: labField
            text: qsTr("Position")
            anchors.left: parent.left
            anchors.leftMargin: textField.leftPadding
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            height: textField.sizeTextName
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 15
            color: textField.colorname
        }
        Label{
            id: labUnit
            width: paintedWidth + 5
            height: textField.sizeTextUnit
            text: qsTr("\u00B0")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            anchors.left: labField.right
            anchors.leftMargin: 5
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 11
            color: textField.colorunit
        }

        Rectangle{
            id: hightLine
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            height: 1
            color: textField.hightLineColor
        }
        Rectangle{
            id: valueBackground
            anchors.right: parent.right
            anchors.rightMargin: textField.rightPadding
            anchors.left: parent.left
            anchors.leftMargin: textField.leftPadding
            anchors.top: parent.top
            anchors.topMargin: textField.topPadding
            anchors.bottom: parent.bottom
            anchors.bottomMargin: textField.bottomPadding
            color: "transparent"
        }
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
        }
//        State {
//            name: "Hovering"
//            PropertyChanges {
//                target: valueBackground
//                color: "#111111"
//            }
//            PropertyChanges {
//                target: hightLine
//                color: "white"
//                height: 2
//            }
//        }
//        State {
//            name: "Focused"
//            PropertyChanges {
//                target: valueBackground
//                color: "#000000"
//            }
//            PropertyChanges {
//                target: hightLine
//                color: "white"
//                height: 2
//            }
//        }
    ]

    onEnabledChanged: {
        if(textField.enabled) textField.state = ""
        else textField.state = "disable"
    }

    onFocusChanged: {
        if(textField.focus)
        {
            textField.state = "Focused";
        }
        else
        {
            textField.state = ""
        }
        if(!textField.focus)
        {
            if(isNaN(textField.text))
            {
                textField.text = textField.defaultValue
            }
            accepted();
        }
    }
    onHoveredChanged: {
        if(textField.hovered) textField.state = "Hovering"
        else{
            if(textField.focus)
            {
                textField.state = "Focused";
            }
            else
            {
                textField.state = ""
            }
        }
    }

    Keys.onEscapePressed: {
        textField.focus = !textField.focus
        event.accepted = true
    }

    Keys.onReturnPressed: {
        textField.focus = !textField.focus
        event.accepted = true
    }

    Keys.onEnterPressed: {
        textField.focus = !textField.focus
        event.accepted = true
    }
}
