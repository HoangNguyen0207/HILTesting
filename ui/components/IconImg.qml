import QtQuick 2.0
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

Image {
    id: iconId
    property alias color: overlayId.color
    property int size: 22
    property real scalingFactor: 1
    sourceSize.height: size*scalingFactor
    sourceSize.width: size*scalingFactor
    ColorOverlay
    {
        id: overlayId
        color: "white"
        anchors.fill: parent
        source: iconId
    }
}
