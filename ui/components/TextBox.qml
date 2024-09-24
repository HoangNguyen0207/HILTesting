import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Item {
    id: textBoxId

    property color borderColor: "black"
    property color borderHoverColor: "blue"
    property color borderFocusColor: "blue"
    property color backgroundColor: "white"
    property color backgroundHoverColor: "white"
    property color backgroundFocusColor: "white"
    property double borderWidth: 1
    property double borderRadius: 2
    property alias text: input.text
    property alias forceGroundColor: input.color
    property alias selectionColor: input.selectionColor
    property alias fontPointSize: input.font.pointSize
    property alias fontPixelSize: input.font.pixelSize
    property alias fontFamily: input.font.family
    property alias fontBold: input.font.bold
    property alias maximumLength: input.maximumLength
    property alias horizontalAlignment: input.horizontalAlignment
    property alias readOnly: input.readOnly
    property alias validator: input.validator
    property alias textFocus: input.focus
    property alias holderText: input.placeholderText
    property alias holderTextColor: input.placeholderTextColor
    //width: 180; height: 50

    Rectangle
    {
        id: recTxtId
        anchors.fill: parent
        border.width: textBoxId.borderWidth
        border.color: textBoxId.borderColor
        radius: textBoxId.borderRadius
        color: textBoxId.backgroundColor
    }

    TextField
    {
        id: input
        anchors.fill: parent
        anchors.rightMargin: 0
        verticalAlignment: Text.AlignVCenter
        selectByMouse: true
        color: "orange"
        font.bold: true

    }
}
