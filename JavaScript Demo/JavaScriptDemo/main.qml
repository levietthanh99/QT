import QtQuick 2.12
import QtQuick.Window 2.12
 import QtQml 2.12
import "DemoJavaScript.js" as Demo

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 30
        height: 30
        color: "red"
        x : 10
        y : 10
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Demo.createMyObject();
            }
        }
    }

    Rectangle {
        width: 30
        height: 30
        color: "yellow"
        x : 100
        y : 10
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.createQmlObject('import QtQuick 2.0; Rectangle { x: 200; y:200; width: 100; height: 50; color: "blue";
                                                    Text {
                                                            anchors.centerIn: parent;
                                                            text: "hello ku";
                                                         }
                                                    }',
                                                   root,
                                                   "")
            }
        }
    }






}
