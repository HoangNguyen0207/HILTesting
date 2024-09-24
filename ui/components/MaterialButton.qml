import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.12
import "../singletons" as SGT
Button {
    id: btnId
    flat: true
    text: "Button"
    bottomPadding: 0
    topPadding: 0
    font.capitalization: Font.MixedCase
    Material.background: SGT.Style.buttonBackgroundColor
    font.pixelSize: 16
    font.bold: true

    property alias radius: recBkgId.radius
    property alias border: recBkgId.border
    property color disableBackgrounColor: "gray"
    property alias iconImg: iconId.source
    property alias iconImgSize: iconId.size
    property bool iconRight: false
    property alias iconScalingFactor: iconId.scalingFactor
    property color iconHoverColor: "white"
    property color textHoverColor: "lightgray"
    property color textColor: "white"
    property color iconForceGround: "white"
    property alias horizontalAlignment: labelId.horizontalAlignment
    property alias verticalAlignment: labelId.verticalAlignment
    property bool wrapText: false

    function getbackgroundColor(){
        if(!btnId.enabled) return btnId.disableBackgrounColor
        else if(btnId.pressed) return Qt.lighter(btnId.Material.backgroundColor,0.8)
        else if(btnId.hovered) return Qt.lighter(btnId.Material.backgroundColor,1.5)
        else return btnId.Material.backgroundColor
    }

    state: btnId.enabled ? "" : "Disable"
    focusPolicy: Qt.StrongFocus
    leftPadding: 5
    rightPadding: 5

    background: Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: btnId.getbackgroundColor()
    }

    contentItem: RowLayout
    {
        id: row
        anchors.verticalCenter: parent.verticalCenter
        layoutDirection: iconRight ? Qt.RightToLeft : Qt.LeftToRight
        spacing: 5

        IconImg
        {
            id: iconId
            color: btnId.hovered ? iconHoverColor : iconForceGround
            Layout.alignment: Qt.AlignCenter
        }

        Label
        {
            id: labelId
            Layout.alignment: Qt.AlignCenter
            text: btnId.text
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
            font: btnId.font
            color: btnId.pressed ? "gray" : btnId.textColor
            wrapMode: btnId.wrapText ? Text.Wrap : Text.NoWrap
        }
    }

    states:State
    {
        name: "Disable"
        PropertyChanges {
            target: labelId
            color: Qt.lighter("gray",1.2)
        }
        PropertyChanges {
            target: recBkgId
            color: Qt.lighter("gray",0.6)
        }
    }
}



























