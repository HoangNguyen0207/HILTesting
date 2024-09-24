import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0

TextField {
    id: textFieldId
    width: 150
    height: 50
    padding: 0
    font.pixelSize: 17
    color: "white"
    rightPadding: 5
    leftPadding: 5
    property color backgroundHoverColor: "transparent"
    property color backgroundFocusColor: "transparent"
    property color backgroundColor: "transparent"
    property color borderHoverColor: "#005ce6"
    property color borderFocusColor: "#005ce6"
    property color borderColor: "#666666"
    property alias border: recBkgId.border

    background: Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: textFieldId.focus ? textFieldId.backgroundFocusColor : (textFieldId.hovered ? textFieldId.backgroundHoverColor : textFieldId.backgroundColor)
        border.color: textFieldId.focus ? textFieldId.borderFocusColor : (textFieldId.hovered ? textFieldId.borderHoverColor : textFieldId.borderColor)
        border.width: 1
        radius: 0
    }
}

