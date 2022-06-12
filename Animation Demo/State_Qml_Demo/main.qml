import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        id: centerRect
        anchors.centerIn: parent
        width: 100; height: 100
        color: "black"

        states: [
            State {
                name: "red"
                PropertyChanges { target: centerRect; color: "red" }
            },
            State {
                name: "blue"
                PropertyChanges { target: centerRect; color: "blue" }
            },
            State {
                name: "yellow"
                PropertyChanges { target: centerRect; color: "yellow" }
            },
            State {
                name: "green"
                PropertyChanges { target: centerRect; color: "green" }
            }
        ]
    }
    property var stateArr: ["", "red", "blue", "yellow", "green"]

    ListView {
        spacing: 10
        width: parent.width
        height: 60
        x: 200
        anchors.topMargin: 50
        model: 5
        orientation: ListView.Horizontal

        delegate: Rectangle{
            width: 40
            height: 40
            color: stateArr[index]
            Text {
                text: index
                color: "white"
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    centerRect.state = stateArr[index]
                }
            }
        }
    }


}
