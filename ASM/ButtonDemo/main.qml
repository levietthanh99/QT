import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import my.namespace 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect
        width: 100
        height: 100

        objectName: "myRect"
        color: "blue"
        anchors.centerIn: parent
    }

    Item {
        Component.onCompleted: console.log(MyNamespace.STYLE_RADIAL)
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {
            test.testFunc();
        }
    }
}
