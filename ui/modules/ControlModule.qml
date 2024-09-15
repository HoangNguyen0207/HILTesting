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
    Rectangle
    {
        id: recBkgId
        anchors.fill: parent
        color: "transparent"

        CMN.MaterialCombobox
        {
            id: processCbxId
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 15
            anchors.leftMargin: 15
            height: 40
            leftPadding: 5
            model: ListModel
            {
                ListElement {text: "Process_1_1_1"}
                ListElement {text: "Process_1_1_2"}
                ListElement {text: "Process_1_1_11"}
                ListElement {text: "Process_1_2_1"}
                ListElement {text: "Process_1_2_2"}
                ListElement {text: "Process_1_2_3"}
                ListElement {text: "Process_1_2_4"}
                ListElement {text: "Process_1_2_5"}
                ListElement {text: "Process_1_2_6_7"}
                ListElement {text: "Process_1_2_8"}
                ListElement {text: "Process_1_2_9"}
                ListElement {text: "Process_1_2_10"}
                ListElement {text: "Process_1_2_11"}
                ListElement {text: "Process_2_1_10"}
                ListElement {text: "Process_2_1_11"}
                ListElement {text: "Process_2_2_1"}
                ListElement {text: "Process_2_2_2"}
                ListElement {text: "Process_2_2_3"}
                ListElement {text: "Process_2_2_4"}
                ListElement {text: "Process_2_2_5"}
                ListElement {text: "Process_2_2_9"}
                ListElement {text: "Process_2_2_10"}
                ListElement {text: "Process_2_2_13_1"}
                ListElement {text: "Process_2_2_13_2"}
            }
            onCurrentIndexChanged:
            {
                ActionProvider.loadProcessFile(processCbxId.currentIndex)
            }
            Component.onCompleted:
            {
                ActionProvider.loadProcessFile(processCbxId.currentIndex)
            }
        }
        CMN.PathOpenBrowser
        {
            id: filePathId
            anchors.top: processCbxId.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.leftMargin: 15
            height: 40
        }
    }
}
