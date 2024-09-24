import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Dialog {
    id: dialogId
    width: Math.max(440,rowBtnId.implicitWidth + 16)
    height:isShowExtendedMessage ? 240 : 200
    title: "MessageDialog"
    modal: true
    closePolicy: Popup.NoAutoClose

    property alias yesButton: yesBtnId
    property alias noButton: noBtnId

    property alias iconSource: imgIconId.source
    property alias iconColor: imgIconId.color
    property alias titleColor: lblTitleId.color
    property alias message: txtMessageId.text
    property string extMessage: "Click \"Close\" để tiếp tục"
    property alias messageArea: txtMessageId
    property var extendData: "UNDEFINE"

    property bool isShowButtonOk: false
    property bool isShowButtonCancel: false
    property bool isShowButtonOpen: false
    property bool isShowButtonSave: false
    property bool isShowButtonSaveToAll: false
    property bool isShowButtonClose: false
    property bool isShowButtonDiscard: false
    property bool isShowButtonApply: false
    property bool isShowButtonReset: false
    property bool isShowButtonRestore: false
    property bool isShowButtonHelp: false
    property bool isShowButtonYesToAll: false
    property bool isShowButtonYes: false
    property bool isShowButtonNo: false
    property bool isShowButtonNoToAll: false
    property bool isShowButtonRetry: false
    property bool isShowButtonIgnore: false

    property bool isShowExtendedMessage: false

    signal clickedOk()
    signal clickedCancel()
    signal clickedOpen()
    signal clickedSave()
    signal clickedSaveToAll()
    signal clickedClose()
    signal clickedDiscard()
    signal clickedApply()
    signal clickedReset()
    signal clickedRestore()
    signal clickedHelp()
    signal clickedYesToAll()
    signal clickedYes()
    signal clickedNo()
    signal clickedNoToAll()
    signal clickedRetry()
    signal clickedIgnore()

    function addpendMes(msg)
    {
        txtMessageId.append(msg)
    }

    header: Rectangle
    {
        id: recHeaderId
        height: 35
        color: "transparent"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        IconImg
        {
            id: imgIconId
            anchors.left: parent.left
            anchors.leftMargin: 8
            width: 30
            height: 30
            source: "qrc:/ui/resources/icon/error_64px.png"
            color: "#54ca75"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label
        {
            id: lblTitleId
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            text: dialogId.title
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "lightgray"
            font.pixelSize: 20
            font.bold: true
        }
    }

    background: Rectangle{
        id: recBkgId
        color: SGT.Style.dialogBackgroundColor
        anchors.fill: parent
        radius: 10
        border.width: 1
        border.color: SGT.Style.dialogBorderColor
    }

    footer: Item
    {
        id: recFooterId
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 40
        Row
        {
            id: rowBtnId
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 8
            spacing: 8
            layoutDirection: Qt.LeftToRight
            MaterialButton
            {
                text: "Đồng ý"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                visible: dialogId.isShowButtonOk
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedOk();dialogId.close()}
            }
            MaterialButton
            {
                text: "Hủy bỏ"
                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
                visible: dialogId.isShowButtonCancel
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedCancel();dialogId.close()}
            }
            MaterialButton
            {
                text: "Mở"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                visible: dialogId.isShowButtonOpen
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedOpen()}
            }
            MaterialButton
            {
                text: "Lưu"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                visible: dialogId.isShowButtonSave
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedSave();dialogId.close()}
            }
            MaterialButton
            {
                text: "Lưu tất cả"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                visible: dialogId.isShowButtonSaveToAll
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedSaveToAll();dialogId.close()}
            }
            MaterialButton
            {
                text: "Close"
                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
                visible: dialogId.isShowButtonClose
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedClose();dialogId.close()}
            }
            MaterialButton
            {
                text: "Loại bỏ"
                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
                visible: dialogId.isShowButtonDiscard
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedDiscard();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.ApplyRole
                text: "Áp dụng"
                visible: dialogId.isShowButtonApply
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedApply();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.ResetRole
                text: "Đặt lại"
                visible: dialogId.isShowButtonReset
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedReset();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.ResetRole
                text: "Khôi Phục"
                visible: dialogId.isShowButtonRestore
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedRestore();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.HelpRole
                text: "Trợ giúp"
                visible: dialogId.isShowButtonHelp
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedHelp();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.YesRole
                text: "Đồng ý hết"
                visible: dialogId.isShowButtonYesToAll
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedYesToAll();dialogId.close()}
            }
            MaterialButton
            {
                id: yesBtnId
                DialogButtonBox.buttonRole: DialogButtonBox.YesRole
                text: "Yes"
                visible: dialogId.isShowButtonYes
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedYes();dialogId.close()}
            }
            MaterialButton
            {
                id: noBtnId
                DialogButtonBox.buttonRole: DialogButtonBox.NoRole
                text: "No"
                visible: dialogId.isShowButtonNo
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedNo();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.NoRole
                text: "Không hết"
                visible: dialogId.isShowButtonNoToAll
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedNoToAll();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                text: "Thử lại"
                visible: dialogId.isShowButtonRetry
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedRetry();dialogId.close()}
            }
            MaterialButton
            {
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                text: "Bỏ qua"
                visible: dialogId.isShowButtonIgnore
                implicitHeight: 30
                width: 80
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
                textHoverColor: "white"
                onClicked: {dialogId.clickedIgnore();dialogId.close()}
            }
        }
    }

    contentItem: Item
    {
        id: elementId
        anchors.bottom: recFooterId.top
        anchors.top: recHeaderId.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        ColumnLayout
        {
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 8
            spacing: 2

            Flickable
            {
                Layout.fillWidth: true
                Layout.fillHeight: true
                flickableDirection: Flickable.VerticalFlick
                clip: true
                TextArea.flickable: MaterialTextAreaFlat
                {
                    id: txtMessageId
                    padding: 6
                    backgroundColor: "transparent"
                    backgroundFocusColor: "transparent"
                    backgroundHoverColor: "transparent"
                    Material.foreground: "lightgray"
                    Material.accent: "lightgray"
                    font.pixelSize: 16
                    textFormat: Qt.RichText
                    color: "lightgray"
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    readOnly: true
                    anchors.fill: parent
                    borderColor: "transparent"
                }

                ScrollBar.vertical: ScrollBar {
                }

                ScrollBar.horizontal: ScrollBar {
                }
            }
        }
    }
}
