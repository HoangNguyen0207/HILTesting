import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import "../singletons" as SGT

Control
{
    id: controlId
    width: 140
    height: 60

    property alias radius: panControlId.radius
    property color backgroundColor: SGT.Style.gray_10
    property alias name: labFieldId.text
    property alias value: txtValueId.text
    property alias unit: labUnitId.text
    property alias color: txtValueId.color
    property int hPadding: 5
    property int vPadding: 5

    background: Rectangle
    {
        id:panControlId
        anchors.fill: parent
        radius: 0
        color: controlId.backgroundColor
    }

    Item
    {
        id: controlMarginId
        anchors.top: parent.top
        anchors.topMargin: controlId.vPadding
        anchors.bottom: parent.bottom
        anchors.bottomMargin: controlId.vPadding
        anchors.left: parent.left
        anchors.leftMargin: controlId.hPadding
        anchors.right: parent.right
        anchors.rightMargin: controlId.hPadding
        Item
        {
            id: valueBoderId
            anchors.bottom: infoBoderId.top
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            TextField{
                id: txtValueId
                font.pixelSize: 18
                text: qsTr("0")
                anchors.bottomMargin: -3
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                color: "red"/*"#cac735"*/
                leftPadding: 0
                background: Rectangle
                {
                    color: controlId.backgroundColor
                    anchors.fill: parent
                }
            }
        }

        Item
        {
            id: infoBoderId
            height: 18
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            Label{
                id: labFieldId
                text: qsTr("Position")
                anchors.leftMargin: 0
                anchors.bottomMargin: 0
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignLeft
                font.weight: Font.DemiBold
                font.pixelSize: 14
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: "black"/*"#32e3f1"*/
            }
            Label{
                id: labUnitId
                width: paintedWidth + 5
                text: qsTr("\u00B0")
                anchors.left: labFieldId.right
                anchors.leftMargin: 5
                anchors.topMargin: 0
                anchors.bottomMargin: 0
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignBottom
                font.pixelSize: 12
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                color: SGT.Style.gray_60
            }
        }
    }

    onEnabledChanged: {
        if(controlId.enabled) controlId.state = ""
        else controlId.state = "disable"
    }
    states: [
        State {
            name: "disable"
            PropertyChanges {
                target: txtValueId
                color: "gray"
            }
            PropertyChanges {
                target: labFieldId
                color: "gray"
            }
            PropertyChanges {
                target: labUnitId
                color: "gray"
            }
        }
    ]
}
