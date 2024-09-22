import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN
import Flux 1.0

Item {
    id: root
    width: 500
    height: 500

    property int buttonHeight: 35
    property alias enableButton: enableBtnId
    property alias disableButton: disableBtnId
    property alias controlOnButton: controlOnBtnId
    property alias controlOffButton: controlOffBtnId
    property alias resetButton: resetBtnId
    property alias homingButton: homingBtnId

    Rectangle
    {
        id: recBkgId
        color: "transparent"
        anchors.fill: parent
        Column
        {
            id: btnColId
            anchors.fill: parent
            CMN.MaterialButton
            {
                id: enableBtnId
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.buttonHeight
                text: "Enable"
                horizontalAlignment: Text.AlignHCenter
            }
            CMN.MaterialButton
            {
                id: disableBtnId
                anchors.top: enableBtnId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 10
                height: root.buttonHeight
                text: "Disable"
                horizontalAlignment: Text.AlignHCenter
            }
            CMN.MaterialButton
            {
                id: controlOnBtnId
                anchors.top: disableBtnId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 10
                height: root.buttonHeight
                text: "ControlOn"
                horizontalAlignment: Text.AlignHCenter
            }
            CMN.MaterialButton
            {
                id: controlOffBtnId
                anchors.top: controlOnBtnId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 10
                height: root.buttonHeight
                text: "ControlOff"
                horizontalAlignment: Text.AlignHCenter
            }
            CMN.MaterialButton
            {
                id: resetBtnId
                anchors.top: controlOffBtnId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.buttonHeight
                anchors.topMargin: 10
                text: "Reset"
                horizontalAlignment: Text.AlignHCenter
            }

            CMN.MaterialButton
            {
                id: homingBtnId
                anchors.top: resetBtnId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.buttonHeight
                anchors.topMargin: 10
                text: "Homing"
                horizontalAlignment: Text.AlignHCenter
            }

        }
    }
}
