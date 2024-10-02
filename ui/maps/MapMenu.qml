import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import "../singletons" as SGT
import "../components" as CMN


Popup {
    id: root
    width: 160
    height: 185
    modal: false
    padding: 0
    closePolicy: Popup.CloseOnReleaseOutside



    background: Rectangle
    {
        id: recBkgId
        color: SGT.Style.gray_20
        anchors.fill: parent
        radius: 0
    }

    Menu
    {

    }


}
