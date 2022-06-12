import QtQuick 2.0

Rectangle {
    id: root
    property int dur : 0
    property int des: 0
    property int delay: 0

    property alias text: rText.text
    property alias fontBold: rText.font.bold
    property alias colorText: rText.color
    property alias visibleIcon: playingIcon.visible

    Image {
        id: playingIcon
        width: 35; height: 35
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/playerIcon.png"
    }

    Text {
        id: rText
        text: ""
        color: "black"
        font.pixelSize: 20
        width: parent.width

        anchors.left: playingIcon.visible? playingIcon.right: parent.left
        anchors.verticalCenter: parent.verticalCenter

        Image {
            id: playingIconChild
            width: 35; height: 35
            anchors.left: rText.right
            anchors.leftMargin: 100
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/playerIcon.png"
        }

        Text {
            id: childT
            text: parent.text
            anchors.left: playingIconChild.right
            font.pixelSize: parent.font.pixelSize
            font.bold: parent.font.bold
            color: rText.color

        }
    }
    function currentItemChange() {
        if(rText.contentWidth > parent.width){
            root.dur = (rText.contentWidth + 120) * 10
            childT.visible = true
            playingIconChild.visible = true;
            root.des = -rText.contentWidth - 135
            root.delay = 1000
        }else {
            root.dur = 0
            childT.visible = false
            playingIconChild.visible = false;
            root.des = 0
            root.delay = 0
        }
    }
}
