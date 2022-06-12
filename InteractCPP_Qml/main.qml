import QtQuick 2.12
import QtQuick.Window 2.12
import customcomponents 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            console.log("Value: " + f_color.value + f_color.color)
//            f_color.timer.start();
//            console.log("Timer object in 1 class: " + f_color.timer)
//            ABCXX.start();
//        }
//    }

//    Fcolor {
//        id: f_color
//    }

    Item {
        anchors.fill: parent

        Rectangle {
            id: rect
            objectName: "RectObj"
            anchors.centerIn: parent
            width: 300
            height: 100
            color: "red"
            property int rect_value: 123

            Text {
                id: txt
                anchors.centerIn: parent
                text: "This is text"
            }

            function changeColor(){
                rect.color = "blue"
            }

            Component.onCompleted: {
                console.log("onCompleted " + rect)
            }

        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            ABCXX.start();
        }
    }


}
