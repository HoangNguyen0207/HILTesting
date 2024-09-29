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
    width: 250
    height: 300
    modal: true
    padding: 0
    anchors.centerIn: parent
    closePolicy: Popup.NoAutoClose

    background: Rectangle
    {
        id: recBkgId
        color: SGT.Style.dialogBackgroundColor
        anchors.fill: parent
        radius: 0
        border.width: 1
        border.color: SGT.Style.dialogBorderColor
    }

    Label
    {
        id: dialogLblId
        text: "Laser tracker"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 40
        font.pixelSize: 18
        color: "white"
    }

    CMN.MaterialValueInputCompact
    {
        id: xInputId
        name: "Xpos"
        unit: "mm"
        anchors.top: dialogLblId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        height: 55
    }
    CMN.MaterialValueInputCompact
    {
        id: yInputId
        name: "Ypos"
        unit: "mm"
        anchors.top: xInputId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        height: 55
    }
    CMN.MaterialValueInputCompact
    {
        id: zInputId
        name: "Zpos"
        unit: "mm"
        anchors.top: yInputId.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        height: 55
    }

    Row
    {
        id: btnRow
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        height: 30
        CMN.MaterialButton
        {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: 100
            text: "Ok"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            onClicked:
            {
                var data = {
                    x: xInputId.value,
                    y: yInputId.value,
                    z: zInputId.value
                }

                ActionProvider.laserInputTriggered(data)
                root.close()
            }
        }
    }

}
