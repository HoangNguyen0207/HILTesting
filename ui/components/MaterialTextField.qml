import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0


TextField {
    id: textfield
    width: 319
    height: 35
    padding: 0
    bottomPadding: 0
    topPadding: 0
    placeholderText: "TextField"
    font.pixelSize: 13
    property color backgroundHoverColor: Material.backgroundColor
    property color backgroundFocusColor: Material.backgroundColor
    property color backgroundColor: Material.backgroundColor
    property color borderHoverColor: Material.backgroundColor
    property color borderFocusColor: Material.backgroundColor
    property color borderColor: Material.backgroundColor
    property alias border: recbkg.border
    Material.elevation: 0
    color: Material.foreground
    rightPadding: 5
    leftPadding: 5

    function getBackgrounColor(){
        if(textfield.focus){
            return textfield.backgroundFocusColor
        }
        else{
            if(textfield.hovered){
                return textfield.backgroundHoverColor
            }
            else{
                return textfield.backgroundColor
            }
        }
    }

    function getBoderColor(){
        if(textfield.focus){
            return textfield.borderFocusColor
        }
        else{
            if(textfield.hovered){
                return textfield.borderHoverColor
            }
            else{
                return textfield.borderColor
            }
        }
    }

    background: Rectangle{
        anchors.fill: parent
        Rectangle{
            anchors.fill: parent
            color: "black"
            border.color: "transparent"
            layer.enabled: textfield.enabled && textfield.Material.elevation > 0
            layer.effect: ElevationEffect {
                elevation: textfield.Material.elevation
            }
            border.width: 0
        }
        Rectangle{
            id: recbkg
            color: getBackgrounColor()
            border.color: getBoderColor()
            anchors.fill: parent
            border.width: 0
        }
    }

    Keys.onEscapePressed: {
        focus = !focus
        event.accepted = true
    }
}



