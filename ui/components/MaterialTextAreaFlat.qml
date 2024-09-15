import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12

TextArea
{
    id: textAreaId
    width: 150
    height: 50
    padding: 0
    placeholderText: "TextArea"
    font.pixelSize: 13
    color: "black"
    wrapMode: Text.Wrap
    property color backgroundHoverColor: "white"
    property color backgroundFocusColor: "white"
    property color backgroundColor: "white"
    property color borderHoverColor: "black"
    property color borderFocusColor: "black"
    property color borderColor: "black"
    property alias boder: recBkgId.border

    background: Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: textAreaId.focus ? textAreaId.backgroundFocusColor : (textAreaId.hovered ? textAreaId.backgroundHoverColor : textAreaId.backgroundColor)
        border.color: textAreaId.focus ? textAreaId.borderFocusColor : (textAreaId.hovered ? textAreaId.borderHoverColor : textAreaId.borderColor)
        border.width: 1
    }
}
