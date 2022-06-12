import QtQuick 2.0
import QtQml 2.5
Text {
    id: rText
    text: ""
    color: "black"
    font.pixelSize: 20
    property int dur: 0
    property int des: 0
    property int delay: 0

    Text {
        id: copyText
        text: rText.text
        anchors.left: rText.right
        anchors.leftMargin: 50
        font.pixelSize: rText.font.pixelSize
    }
    Component.onCompleted: {
        // long text
        if(rText.contentWidth > 200){
            rText.dur = (rText.contentWidth + 120)*5
            copyText.visible = true
            rText.des = -rText.contentWidth - 50
            rText.delay = 1000
        }else { // short text
            rText.dur = 0
            copyText.visible = false
            rText.des = 0
            rText.delay = 0
        }
    }
}
