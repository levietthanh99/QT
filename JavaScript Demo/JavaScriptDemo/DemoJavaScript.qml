import QtQuick 2.12
import QtQuick.Window 2.12
import "DemoJavaScript2.js" as Demo2

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect1
        width: 100; height: 100
        border.width: mouse1.pressed? 10:1
        color: "green"

        Text {
            anchors.centerIn: parent
            text: "%1\n%2".arg(root.height).arg(root.width);
        }
    }

    MouseArea {
        id: mouse1
        anchors.fill: parent
        onClicked: {
            Demo2.func();
            console.log(Demo2.arr1)
            console.log(Demo2.obj1)
            console.log("Click count: " + Demo2.clickCount)
//            setColor()
        }
    }

    function setColor(){
        rect1.color = "blue"
    }
}
