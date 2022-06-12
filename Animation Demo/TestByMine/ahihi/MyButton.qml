import QtQuick 2.0

Rectangle {
    id: root
    color: "yellow"
    width: 100
    height: 50
    opacity: mouseArea.pressed ? 0.5 : 1
    property alias btnName: label.text

    signal btnOnClicked()
    signal btnOnRelease()
    signal btnOnPress()

    Text {
        id: label
        color: "black"
        font.pointSize: 24
        clip: true
        wrapMode: Text.Wrap
        anchors.centerIn: parent
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            btnOnClicked()
        }
        onReleased: {
            btnOnRelease()
        }
        onPressed: {
            btnOnPress()
        }
    }
}
