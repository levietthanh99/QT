import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "#f0ffff"

    Rectangle {
        id: rect_left
        width: parent.width/2; height:  30; z: 1; color: "#deb887"
        border.color: "black"; border.width: 3; radius: 10
        Text {
            id: txt1;
            text: "Sender"; color: "yellow"; font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }
        TextField {
            id: msg
            anchors.left: parent.left; anchors.leftMargin: 10;
            placeholderText: "Enter messeage"; font.pixelSize: 20;y: 35
        }
        Button {
            anchors.left: msg.right; anchors.leftMargin: 10
            anchors.verticalCenter: msg.verticalCenter
            width: 60; text: "send"; font.pointSize: 15
            onClicked: {
                if(msg.text !== ""){
                    myControl.addTextToList(msg.text); msg.text = ""
                }
            }
        }
    }
    Rectangle {
        id: rect_right
        width: parent.width/2 - 5; height:  30; x : parent.width/2 + 5
        color: "#deb887"; border.color: "black"; border.width: 3; radius: 10
        Text {
            id: txt4
            text: "Receiver"
            color: "yellow"
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    ListView {
        id: listView; spacing: 10
        width: parent.width/2; height:  parent.height
        x : parent.width/2; y : 35
        model: myModel
        delegate: Rectangle{
            id: rect11; color: "orange"; anchors.margins: 10; radius: 10
            border.width: 3; border.color: "black";
            width: listView.width; height: 70
            Text {
                id: text1
                text: modelData; anchors.fill: rect11; anchors.margins: 10
                horizontalAlignment: Text.AlignHCenter; font.pixelSize: 20
                maximumLineCount: 2; wrapMode: Text.Wrap; elide: Text.ElideRight
            }
        }
    }
}
