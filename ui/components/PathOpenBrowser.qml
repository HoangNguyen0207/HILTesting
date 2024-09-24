import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2
import "../singletons" as SGT

Control {
    id: root
    width: 400
    height: 30

    property string fileFilter: "All files(*)"
    property alias path: txtPathId.text

    signal openFile()

    contentItem: Item
    {
        id: contentId
        anchors.fill: parent
//        Label
//        {
//            id: lblTitleId
//            text: ""
//            anchors.top: parent.top
//            anchors.left: parent.left
//            anchors.bottom: parent.bottom
//            rightPadding: 5
//            leftPadding: 5
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignLeft
//            font.pixelSize: SGT.Style.normalFontPixelSize
//            font.bold: true
//            color: root.enabled ? SGT.Style.accentColor : SGT.Style.disableColor
//            background: Rectangle
//            {
//                anchors.fill: parent
//                color: SGT.Style.backgroundColorDark
//            }
//        }

        MaterialTextFieldFlat
        {
            id: txtPathId
            width: height
            anchors.right: btnOpenId.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            placeholderText: "File path"
            readOnly: true
            font.pixelSize: SGT.Style.normalFontPixelSize
            Material.foreground: SGT.Style.forceColorGrayLight
            backgroundColor: SGT.Style.backgroundColor
            backgroundFocusColor: SGT.Style.backgroundColor
            backgroundHoverColor: SGT.Style.backgroundColor
            font.bold: true
            border.width: 0
        }

        MaterialButton
        {
            id: btnOpenId
            text: ""
            iconImg: "qrc:/ui/resources/icon/import-64.png"
            iconScalingFactor: 1.1
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            enabled: false
            onClicked:
            {
                fileDialogId.open()
            }
        }
    }

    FileDialog
    {
        id: fileDialogId
        selectMultiple: false
        width: 640
        height: 480
        visible: false
        title: ""

        nameFilters: root.fileFilter
        onAccepted:
        {
            root.openFile()
            txtPathId.text = fileDialogId.fileUrl.toString()
        }
    }
}

