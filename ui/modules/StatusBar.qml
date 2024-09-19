import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import "../singletons" as SGT
import "../components" as CMN
import Flux 1.0

Item {
    id: root
    height: 300
    width: 300

    Row
    {
        id: sttRowId
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 160

        Label
        {
            id: fmsLblId
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            text: "FMS"
            width: 75
            font.bold: true
            font.pixelSize: SGT.Style.normalFontPixelSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: SGT.Style.hightTextColor
            background: Rectangle
            {
                anchors.fill: parent
                color: SGT.Style.disconnectedStatusColor
                radius: 3
            }
        }

        Label
        {
            id: tmsLblId
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: fmsLblId.right
            anchors.leftMargin: 5
            text: "TMS"
            width: 75
            font.bold: true
            font.pixelSize: SGT.Style.normalFontPixelSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: SGT.Style.hightTextColor
            background: Rectangle
            {
                anchors.fill: parent
                color: SGT.Style.disconnectedStatusColor
                radius: 3
            }
        }
    }
}
