import QtQuick 2.12
import QtQuick.Window 2.12
//import my.namespace 1.0
 import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rec_center
        color: "green"
        width: 250
        height: 150
        border.color: "black"
        border.width: 5
        radius: 20
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenterOffset: -50
            verticalCenter: parent.verticalCenter
        }

    }

    MyButton {
        id: btn1
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 50
            horizontalCenterOffset: -100
        }
        btnName: "Btn 1"
        onBtnOnClicked: {
            console.log(btnName + " OnClicked")
            rec_center.scale /= 1.5
            rec_center.rotation -= 20
            rec_center.anchors.horizontalCenterOffset -= 100
        }
        onBtnOnRelease: {
            console.log(btnName + " OnRelease")
        }

        onBtnOnPress: {
            console.log(btnName + "On press")
        }

        onBtnOnEntered: {
            btn1.color = "cyan"
        }

        onBtnOnExited: {
            btn1.color = "green"
        }
    }

    MyButton {
        id: btn2
        color: "blue"
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 50
            horizontalCenterOffset: 100
        }
        btnName: "Btn 2"

        onBtnOnEntered: {
            btn2.color = "cyan"
        }

        onBtnOnExited: {
            btn2.color = "blue"
        }

        onBtnOnClicked: {
            console.log(btnName + " OnClicked")
            rec_center.scale *= 1.5
            rec_center.rotation += 20
            rec_center.anchors.horizontalCenterOffset += 100
        }
        onBtnOnRelease: {
            console.log(btnName + " OnRelease")
        }

        onBtnOnPress: {
            console.log(btnName + "On press")
        }
    }


}
