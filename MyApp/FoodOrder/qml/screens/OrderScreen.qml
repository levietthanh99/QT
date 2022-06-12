import QtQuick 2.9
import AppEnums 1.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.5
 import QtQml 2.12
import "../components"

Item {
    id: root
    Loader {
        id: status_bar
        width: parent.width
        height: 50
        source: "qrc:/qml/components/StatusBar.qml"
    }

    property bool isOrder: false

    ListView {
        id: lv
        z: -1
        anchors.top: status_bar.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 40

        width: 180
        height: 500

        model: FOOD_MENU_MODEL

        delegate: Rectangle {
            id: rect
            width: parent.width
            height: 100
            border.color: "green"
            border.width: 2
            anchors.topMargin: 5

            Text {
                id: txt
                width: parent.width
                height: 15
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 15
                text: name_
            }


            Image {
                anchors.top : txt.bottom
                anchors.topMargin: 5
                anchors.horizontalCenter: parent.horizontalCenter
                width: 70; height: 70
                fillMode: Image.PreserveAspectFit
                source: pathImage_ //"qrc:/images/musicIcon.png"
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    rect.color = "lightgray"
                }
                onExited: {
                    rect.color = "white"
                }
            }

            SnipBox {
                z: 1
                anchors.right: parent.right
                anchors.bottom: parent.bottom

                value: itemOrder_

                onBtnDecrease: {
                    if(value > 0){
                        value -= 1
                        FOOD_MENU_MODEL.updateData(false,index,value)
                    }
                }
                onBtnIncrease: {
                    if(inventory_ > 0){
                        value += 1
                        FOOD_MENU_MODEL.updateData(true,index,value)
                    }
                }
            }


            Rectangle {
                width: 60
                height: 15
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
                anchors.left: parent.left
                anchors.leftMargin: 3
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    height: 15
                    font.pixelSize: 20
                    text: inventory_
                }
            }

            Component.onCompleted:  {
                console.log("index: " + index)
            }

        }


    }

    Rectangle {
        id: txt_add_to_cart
        width: 60
        height: 70
        anchors.left: lv.right
        anchors.leftMargin: 10
        anchors.top: lv.top
        color: "green"

        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
            text: "add to cart"
            wrapMode: Text.Wrap
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(FOOD_MENU_MODEL.isTakeOrder()){
                    lv2.visible = true
                }else {
                    lv2.visible = false
                }
                ORDER_CTRL.upDateList();
                ORDER_CTRL.printList();
                console.log(lv2.visible);
            }
        }

    }

    ListView {
        id: lv2
        z: -1
        anchors.top: status_bar.bottom
        anchors.topMargin: 15
        anchors.left: txt_add_to_cart.right
        anchors.leftMargin: 10
        visible: false

        width: 180
        height: 500

        model: ORDER_CTRL.listModel

        delegate: Rectangle {
            id: rect2
            width: parent.width
            height: 100
            border.color: "green"
            border.width: 2
            anchors.topMargin: 5

            Text {
                id: txt2
                width: parent.width
                height: 15
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 15
                text: modelData.name
            }


            Image {
                anchors.top : txt2.bottom
                anchors.topMargin: 5
                anchors.horizontalCenter: parent.horizontalCenter
                width: 70; height: 70
                fillMode: Image.PreserveAspectFit
                source: modelData.pathImage //"qrc:/images/musicIcon.png"
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


            Rectangle {
                width: 60
                height: 15
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
                anchors.left: parent.left
                anchors.leftMargin: 3
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    height: 15
                    font.pixelSize: 20
                    text: "SL: " + modelData.itemOrdered
                }
            }

            Rectangle {
                width: 90
                height: 15
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
                anchors.right: parent.right
                anchors.rightMargin: 3
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    height: 15
                    font.pixelSize: 20
                    text: "Price: " + modelData.price
                }
            }

            Component.onCompleted:  {
                console.log("list order index: " + index)
            }

        }


    }

    Rectangle {
        id: txtTakeOrder
        width: parent.width
        height: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        color: "green"

        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
            text: "Take Order"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_PAYMENT)
            }
        }

    }

}
