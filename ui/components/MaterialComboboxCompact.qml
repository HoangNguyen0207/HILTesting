import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12

ComboBox{
    id: cbx
    height: 60
    rightPadding: 0
    width: 140
    hoverEnabled: true
    font.pixelSize: 16
    Material.background: "#1a1a1a"
    state: enabled ? "" : "Disable"

    property int radius: 0
    property int hightLineWidth: 1
    property int hightLineHoverWidth: 2
    property color hightLineColor: "#4d4d4d"
    property color hightLineHoverColor: "#005ce6"
    property color borderColor: "#666666"

    states: [
        State {
            name: "Disable"
            PropertyChanges{
                target: txtContent
                color: "gray"
            }
        }
    ]

    background: Rectangle {
        id: rectangle
        anchors.fill: parent
        radius: cbx.radius
        color: cbx.Material.background
        border.width: 1
        border.color: cbx.hovered ? cbx.hightLineHoverColor : cbx.borderColor
    }

    contentItem: Text {
        id: txtContent
        text: cbx.displayText
        anchors.right: parent.right
        anchors.rightMargin: cbx.rightPadding
        anchors.left: parent.left
        anchors.leftMargin: cbx.leftPadding
        anchors.bottom: parent.bottom
        anchors.bottomMargin: cbx.bottomPadding
        anchors.top: parent.top
        anchors.topMargin: cbx.topPadding
        horizontalAlignment: Text.AlignLeft
        font: cbx.font
        color: cbx.pressed ? "gray" : cbx.Material.foreground
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    popup: Popup{

        width: cbx.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView {
            clip: false
            implicitHeight: contentHeight
            model: cbx.popup.visible ? cbx.delegateModel : null
            currentIndex: cbx.highlightedIndex
        }

        background: Rectangle {
            id : recBkgId
            color: Qt.lighter(cbx.Material.backgroundColor,1.6)
            radius: cbx.radius
        }
    }

    delegate: ItemDelegate {
        width: cbx.width
        contentItem: Text {
            text: modelData
            horizontalAlignment: Text.AlignLeft
            color: cbx.Material.foreground
            font: cbx.font
            verticalAlignment: Text.AlignVCenter
        }
        highlighted: cbx.highlightedIndex === index
    }
}
