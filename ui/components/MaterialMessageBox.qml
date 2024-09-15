import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

ApplicationWindow
{
    id: mainWindowId
    width: 360
    height: 180
    title: "Lỗi"
    flags: Qt.FramelessWindowHint
    visible: false

    property alias text: txtMessageId.text
    readonly property color indicatorColor: "#54CA75"
    readonly property color hightlineColor: "orange"
    readonly property color textColor: "lightgray"
    readonly property color hightTextColor: "white"
    readonly property color redColor: "#d61425"
    readonly property color disableColor: "gray"
    property int previousX
    property int previousY

    signal accepted()
    signal rejected()

    enum MessageIcon
    {
        Warning,
        Info,
        Error,
        Question
    }

    enum MessageButton
    {
        Yes,
        No
    }

    Rectangle
    {
        id: rectangleId
        color: "#333333"
        anchors.top: recHeaderId.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        MaterialButton
        {
            id: customFlatButtonId
            x: 257
            y: 110
            width: 85
            height: 30
            text: "Thoát"
            textHoverColor: "#ffffff"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            Material.background: "#4d4d4d"
            Material.foreground: "lightgray"
            Material.accent: "#54ca75"
            onClicked:
            {
                mainWindowId.rejected()
                mainWindowId.close()
            }
        }

        MaterialTextAreaFlat
        {
            id: txtMessageId
            height: 87
            borderHoverColor: "#000000"
            wrapMode: Text.Wrap
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            readOnly: true
            backgroundColor: "#4d4d4d"
            Material.background: "#4d4d4d"
            color: "lightgray"
            text: "Đã tồn tại một tiến trình của RF HWIL"
            font.pixelSize: 16
            topPadding: 6
        }

    }

    Rectangle
    {
        id: recHeaderId
        height: 30
        color: "#1e1e1e"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        IconImg
        {
            anchors.left: parent.left
            anchors.leftMargin: 6
            width: 24
            height: 24
            source: "qrc:/ui/resources/icon/error_64px.png"
            color: "#d61425"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label
        {
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            text: mainWindowId.title
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "lightgray"
            font.pixelSize: 16
            font.bold: true
        }

        Button
        {
            id: btnCloseId
            width: 40
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.top: parent.top
            flat: true
            text: "\u2715"
            font.weight: Font.Light
            Material.background: "#d61425"
            font.pixelSize: 23
            background: Rectangle
            {
                anchors.fill: parent
                color: parent.hovered ? Material.backgroundColor : "transparent"
            }

            onClicked:
            {
                mainWindowId.rejected()
                mainWindowId.close()
            }

        }

        MouseArea
        {
            anchors.left: parent.left
            anchors.right: btnCloseId.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            onPressed:
            {
                previousX = mouseX
                previousY = mouseY
            }

            onMouseXChanged:
            {
                var dx = mouseX - previousX
                mainWindowId.setX(mainWindowId.x + dx)
            }

            onMouseYChanged:
            {
                var dy = mouseY - previousY
                mainWindowId.setY(mainWindowId.y + dy)
            }
        }
    }
}
