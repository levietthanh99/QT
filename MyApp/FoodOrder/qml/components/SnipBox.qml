import QtQuick 2.0

Item {
    property int value: 0
    signal btnIncrease();
    signal btnDecrease();

    width: 70
    height: 20
    Rectangle {
        id: r1
        width: parent.height
        height: parent.height
        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "-"
            font.pixelSize: parent.height
        }
        MouseArea {
            id: dec
            anchors.fill: parent
            onClicked: {
                btnDecrease();
            }
        }
    }

    Text {
        id: t1
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: value.toString()
        font.pixelSize: parent.height
    }

    Rectangle {
        id: r2
        width: parent.height
        height: parent.height
        anchors.right: parent.right
        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "+"
            font.pixelSize: parent.height
            MouseArea {
                id: inc
                anchors.fill: parent
                onClicked: {
                    btnIncrease();
                }
            }
        }
    }



}
