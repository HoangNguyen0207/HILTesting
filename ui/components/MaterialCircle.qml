import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.12
import "../singletons" as SGT

Rectangle
{
    id: root
    property real radiusCircle: 100
    property color colorCircle: "red"
    width: root.radiusCircle
    height: root.radiusCircle
    radius: 180
    color: root.colorCircle
}
