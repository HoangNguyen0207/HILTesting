import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Item {
    id: root
    width: 180
    height: 120

    property string lat1: "105.1234567"
    property string lon1: "105.1234567"
    property string lat2: "105.1234567"
    property string lon2: "105.1234567"
    property string dis: "105.1234567"

    Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: SGT.Style.backgroundColorLight

        ColumnLayout
        {
            spacing: 0
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 6
            anchors.rightMargin: 6
            anchors.topMargin: 6
            anchors.bottomMargin: 6
            GridLayout
            {
                rows: 2
                columns: 2
                Label
                {
                    text: "Lat1:"
                    font.pixelSize: 16
                    color: "Lightgrey"
                }
                Label
                {
                    text: lat1
                    font.pixelSize: 16
                    color: "Lightgrey"
                    Layout.fillWidth: true
                }

                Label
                {
                    text: "Lon1:"
                    font.pixelSize: 16
                    color: "Lightgrey"
                }
                Label
                {
                    text: lon1
                    font.pixelSize: 16
                    color: "Lightgrey"
                    Layout.fillWidth: true
                }
            }

            Rectangle
            {
                color: "grey"
                Layout.fillWidth: true
                Layout.preferredHeight: 1
            }

            GridLayout
            {
                rows: 2
                columns: 2
                Label
                {
                    text: "Lat2:"
                    font.pixelSize: 16
                    color: "Lightgrey"
                }
                Label
                {
                    text: lat2
                    font.pixelSize: 16
                    color: "Lightgrey"
                    Layout.fillWidth: true
                }

                Label
                {
                    text: "Lon2:"
                    font.pixelSize: 16
                    color: "Lightgrey"
                }
                Label
                {
                    text: lon2
                    font.pixelSize: 16
                    color: "Lightgrey"
                    Layout.fillWidth: true
                }
            }

            Rectangle
            {
                color: "grey"
                Layout.fillWidth: true
                Layout.preferredHeight: 1
            }

            GridLayout
            {
                columns: 2
                rows: 1
                Label
                {
                    text: "Dis:"
                    color: "#54ca75"
                    font.pixelSize: 16
                }
                Label
                {
                    text: dis
                    Layout.fillWidth: true
                    font.pixelSize: 16
                    color: "#54ca75"
                }
            }
        }
    }
}
