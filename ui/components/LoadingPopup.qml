import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.0
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN
Popup
{
    id: simulationPopupId
    width: 300
    height: 180
    modal: true
    focus: true
    closePolicy: Popup.CloseOnReleaseOutsideParent
    padding: 0
    background: Rectangle
    {
        anchors.fill: parent
        color: "#3d3d3d"
    }

    enum LoadingState
    {
        Loading,
        Failed,
        Success
    }

    property bool isShowMessage: false
    property string failedMessage: "Thất bại."
    property string loadingMessage: "Đang nạp ..."
    property string successMessage: "Hoàn thành."
    property int loadingState: CMN.LoadingPopup.LoadingState.Failed

    onLoadingStateChanged:
    {
        switch(simulationPopupId.loadingState)
        {
        case CMN.LoadingPopup.LoadingState.Loading:
            btnCloseId.visible = false
            txtMsgId.text = loadingMessage
            busyIndicatorId.visible = true
            break;
        case CMN.LoadingPopup.LoadingState.Failed:
            btnCloseId.visible = true
            txtMsgId.text = failedMessage
            busyIndicatorId.visible = false
            imgIndicatorId.source = "qrc:/ui/resources/icon/cancel_96px.png"
            imgIndicatorId.color = "#e81123"
            break;
        case CMN.LoadingPopup.LoadingState.Success:
            btnCloseId.visible = true
            txtMsgId.text = successMessage
            busyIndicatorId.visible = false
            imgIndicatorId.source = "qrc:/ui/resources/icon/checked_96px.png"
            imgIndicatorId.color = "#54ca35"
            break;
        }
    }

    Item
    {
        id: indicatorItemId
        width: 50
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: isShowMessage ? undefined : parent.verticalCenter
        anchors.top: isShowMessage ? parent.top : undefined
        anchors.topMargin: 10
        BusyIndicator
        {
            id: busyIndicatorId
            anchors.fill: parent
            Material.accent: "#54ca35"
        }
        IconImg
        {
            id: imgIndicatorId
            anchors.fill: parent
            visible: !busyIndicatorId.visible
            scalingFactor: 1.5
        }
    }

    Text
    {
        id: txtMsgId
        color: "lightgray"
        text: loadingMessage
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        horizontalAlignment: Text.AlignHCenter
        anchors.top: indicatorItemId.bottom
        font.pixelSize: 16
        font.bold: true
    }

    Flickable
    {
        id: flickId
        visible: simulationPopupId.isShowMessage
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: rowBtnId.top
        anchors.bottomMargin: 5
        anchors.top: txtMsgId.bottom
        anchors.topMargin: 5
        flickableDirection: Flickable.VerticalFlick
        TextArea.flickable: MaterialTextAreaFlat
        {
            id: textAreaId
            backgroundColor: "#4d4d4d"
            backgroundFocusColor: "#4d4d4d"
            backgroundHoverColor: "#4d4d4d"
            readOnly: true
            placeholderText: ""
            font.pixelSize: SGT.Style.normalFontPixelSize
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            anchors.fill: parent
            text: "khong the khoi tao DTMS, thuc hien khoi tao lai. khong the khoi tao DTMS, thuc hien khoi tao lai. khong the khoi tao DTMS, thuc hien khoi tao lai"
            color: "lightgray"
            padding: 6
        }

        ScrollBar.vertical: ScrollBar
        {
        }

        ScrollBar.horizontal: ScrollBar
        {
        }
    }

    Row
    {
        id: rowBtnId
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 8
        spacing: 8
        layoutDirection: Qt.LeftToRight
        MaterialButton
        {
            id: btnCloseId
            text: "Close"
            implicitHeight: 30
            width: 80
            visible: false
            horizontalAlignment: Text.AlignHCenter
            Material.foreground: "lightgray"
            Material.background: "#4d4d4d"
            font.pixelSize: 16
            Material.accent: Qt.lighter("#54CA75",1)
            textHoverColor: "white"
            onClicked: {
                simulationPopupId.close()
                simulationPopupId.loadingState = LoadingState.Loading
            }
        }
    }
}
