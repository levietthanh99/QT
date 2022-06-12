import QtQuick 2.9
import AppEnums 1.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id: root
    Loader {
        id: status_bar
        width: parent.width
        height: 50
        source: "qrc:/qml/components/StatusBar.qml"
    }




    ListView {
        id: lv2
        z: -1
        anchors.top: status_bar.bottom
        anchors.topMargin: 15
        anchors.centerIn: parent

        width: parent.width
        height: 500

        model: ORDER_CTRL.listModel

        delegate: Rectangle {
            id: rect2
            width: parent.width
            height: 50
            border.color: "green"
            border.width: 2
            anchors.topMargin: 5

            Text {
                id: txt1
                width: 100
                height: 15
                anchors.top: parent.top
                font.pixelSize: 15
                text: modelData.name
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    rect2.color = "lightgray"
                }
                onExited: {
                    rect2.color = "white"
                }
            }


            Text {
                id: txt2
                anchors.left: txt1.right
                anchors.leftMargin: 10
                width: 150
                height: 15
                font.pixelSize: 15
                text: "Unit price: " + modelData.price

            }

            Text {
                id: txt3
                anchors.left: txt2.right
                anchors.leftMargin: 10
                width: 80
                height: 15
                font.pixelSize: 15
                text: "SL: " + modelData.itemOrdered
            }

            Text {
                anchors.left: txt3.right
                anchors.leftMargin: 10
                width: 150
                height: 15
                font.pixelSize: 15
                text: "Price: " + modelData.itemOrdered * modelData.price
            }


        }


    }

}
