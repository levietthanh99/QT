import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        id: window
        anchors.centerIn: parent
        width: 120; height: 120
        color: "black"

        Rectangle {id: myRect; width: 50; height: 50; color: "red"}

        states: State {
                name: "reAnchored"
                AnchorChanges {
                    target: myRect
                    anchors.right: window.right
                    anchors.bottom: window.bottom
                }
                PropertyChanges {
                    target: myRect
                    anchors.rightMargin: 10
                    anchors.bottomMargin: 10
                }
            }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: window.state = "reAnchored"
    }
}
