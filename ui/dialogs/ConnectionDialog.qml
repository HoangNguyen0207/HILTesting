import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN
import Flux 1.0

Popup {
    id: root
    width: 350
    height: 400
    modal: true
    padding: 0
    anchors.centerIn: parent
    closePolicy: Popup.NoAutoClose

    property int deviceId: 0

    background: Rectangle
    {
        id: recBkgId
        color: SGT.Style.dialogBackgroundColor
        anchors.fill: parent
        radius: 0
        border.width: 1
        border.color: SGT.Style.dialogBorderColor
    }

    CMN.MaterialButton
    {
        id: closeBtnId
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 1
        anchors.rightMargin: 1
        height: 25
        width: 26
        text: ""
        iconImg: "qrc:/ui/resources/icon/delete_64px.png"
        iconImgSize: 18
        Material.background: SGT.Style.redColor
        onClicked:
        {
            root.close()
        }
    }

    ButtonGroup
    {
        buttons: recDeviceListId.children
    }

    Rectangle
    {
        id: recDeviceListId
        anchors.top: closeBtnId.bottom
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 15
        anchors.rightMargin: 15
        anchors.bottomMargin: 15
        width: 150
        color: "transparent"
        border.color: SGT.Style.dialogBorderColor
        border.width: 1
        CMN.MaterialButton
        {
            id: fmsBtnId
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            text: "FMS"
            height: 35
            font.bold: false
            checkable: true
            checked: true
            Material.background: checked ? SGT.Style.checkedButton : SGT.Style.uncheckedButton
            horizontalAlignment: Text.AlignHCenter
            onCheckedChanged:
            {
                if(checked)
                {
                    root.deviceId = 0
                }
            }
        }

        CMN.MaterialButton
        {
            id: tmsBtnId
            anchors.top: fmsBtnId.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            text: "TMS"
            height: 35
            font.bold: false
            checkable: true
            Material.background: checked ? SGT.Style.checkedButton : SGT.Style.uncheckedButton
            horizontalAlignment: Text.AlignHCenter
            onCheckedChanged:
            {
                if(checked)
                {
                    root.deviceId = 1
                }
            }
        }
    }

    Rectangle
    {
        id: recChannelParamId
        anchors.top: closeBtnId.bottom
        anchors.left: recDeviceListId.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 15
        anchors.bottomMargin: 15
        color: "transparent"
        border.color: SGT.Style.dialogBorderColor
        border.width: 1
        StackLayout
        {
            id: deviceParamStackId
            anchors.fill: parent
            anchors.margins: 10
            currentIndex: root.deviceId
            ConnectionItem
            {
                id: fmsConnectId
                anchors.fill: parent
            }
            ConnectionItem
            {
                id: tmsConnectId
                anchors.fill: parent
            }
        }
    }
}
