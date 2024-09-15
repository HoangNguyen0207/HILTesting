import QtQuick.Controls 2.12
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import "../singletons" as SGT

MenuBar {
    id: root

    delegate: MenuBarItem
    {
        id: menuBarItemId
        contentItem: Text
        {
            text: menuBarItemId.text
            font: menuBarItemId.font
            opacity: enabled ? 1.0 : 0.3
            color: menuBarItemId.highlighted ? "black" : "white"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        background: Rectangle
        {
            implicitWidth: 60
            implicitHeight: 30
            opacity: enabled ? 1 : 0.3
            color: menuBarItemId.highlighted ? "white" : "transparent"
        }
    }
    background: Rectangle
    {
        implicitWidth: 60
        implicitHeight: 30
        color: SGT.Style.backgroundColor

        Rectangle {
            color: "gray"
            width: parent.width
            height: 1
            anchors.bottom: parent.bottom
        }
    }
}
