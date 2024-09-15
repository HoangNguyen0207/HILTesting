import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2
import "../singletons" as SGT
import "." as CMN

Control {
    id: targetConfig
    height: 30
    width: 100
    property alias title: lblTitle.text
    property alias unit: lblUnit.text
    property alias value: txtPath.text
    property alias text_value: txtPath

    contentItem: Item {
        id: contentData
        anchors.fill: parent

        Label{
            id: lblTitle
            width: parent.width/3
            text: qsTr("Distance")
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            leftPadding: targetConfig.leftPadding
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            color: targetConfig.enabled ? SGT.Style.textColor : SGT.Style.disableColor
            background: Rectangle{
                color: "transparent"
                anchors.fill: parent
            }
        }

        CMN.MaterialTextField{
            id: txtPath
            width: parent.width/2.5
            anchors.left: lblTitle.right
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            backgroundColor: SGT.Style.backgroundColor
            backgroundFocusColor: SGT.Style.backgroundColorDark
            backgroundHoverColor: SGT.Style.backgroundColorDark
            placeholderText: "0"
            Material.foreground: SGT.Style.forceColorGrayLight
            Material.accent: SGT.Style.forceColorGrayLight
            font.pixelSize: SGT.Style.normalFontPixelSize
            validator: DoubleValidator{
                bottom: 0.0
                top: 100000.0
            }
        }

        Label{
            id: lblUnit
            text: qsTr("m")
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: txtPath.right
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            leftPadding: 5
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            color: targetConfig.enabled ? SGT.Style.textColor : SGT.Style.disableColor
            background: Rectangle{
                color: SGT.Style.backgroundColorDark
                anchors.fill: parent
            }
        }

    }
}
