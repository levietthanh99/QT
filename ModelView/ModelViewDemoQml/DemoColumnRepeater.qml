import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Column with model is array
    property var arrModel: ["one", "two", "three", "four", "five", "six"]
    Column {
        spacing: 5
        Rectangle { width: 200; height: 20; color: "red"
            Text {
                anchors.centerIn: parent
                text: "Column with model is Array"
            }
        }
        Repeater {
            model: arrModel
            Rectangle { width: 200; height: 20; radius: 10; color: "green";
                Text {
                    anchors.centerIn: parent
                    text: "Item: " + arrModel[index]
                }
            }
        }
        Rectangle { width: 200; height: 20; color: "blue" }
    }

    //Column with ListModel
    Column {
        spacing: 5
        x: 250
        Rectangle { width: 200; height: 20; color: "red"
            Text {
                anchors.centerIn: parent
                text: "Column with model is List Model"
            }
        }
        Repeater {
            model: myListModel
            Rectangle { width: 200; height: 20; radius: 10; color: "green";
                Text {
                    anchors.centerIn: parent
                    text: model.name + "   " + model.age + "tuoi"
                }
            }
        }
        Rectangle { width: 200; height: 40; color: "red"
            Text {
                anchors.centerIn: parent
                anchors.fill: parent
                text: "Column with model is List Model in a different file .qml"
                wrapMode: Text.Wrap
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Repeater {
            model: Model1 {}
            Rectangle { width: 200; height: 20; radius: 10; color: "green";
                Text {
                    anchors.centerIn: parent
                    text: model.name + "   " + model.age + "tuoi"
                }
            }
        }


        Rectangle { width: 200; height: 20; color: "blue" }
    }

    ListModel {
        id: myListModel
        ListElement {name: "thanh"; age: 24}
        ListElement {name: "minh"; age: 14}
        ListElement {name: "bach"; age: 22}
        ListElement {name: "vinh"; age: 26}
    }
}









