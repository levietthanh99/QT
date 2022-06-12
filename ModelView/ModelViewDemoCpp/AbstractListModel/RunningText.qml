import QtQuick 2.0
import QtQml 2.12

Text {
    id: rText
    text: ""
    color: "black"
    font.pixelSize: 14
    property int dur: 0
    property alias aliasDur: rText.dur
    property int des: 0
    property int delay: 0

    Text {
        id: childT
        text: parent.text
        anchors.left: parent.right
        anchors.leftMargin: 100
        font.pixelSize: parent.font.pixelSize
        color: rText.color
    }

    Component.onCompleted: {
        if(rText.contentWidth > 300){
            rText.dur = (rText.contentWidth + 120) * 20
            childT.visible = true
            rText.des = - rText.contentWidth - 50
            rText.delay = 1000
        }else {
            rText.dur = 0
            childT.visible = false
            rText.des = 0
            rText.delay = 0
        }
    }
}
