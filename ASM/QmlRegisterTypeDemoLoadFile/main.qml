import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12
import Custom.Library 1.0

Window {
    width: 640; height: 480; visible: true
    title: qsTr("Hello World"); color: "#f0ffff"
    property bool checkPathFile: true
    MyData {id: myData }
    Rectangle {
        id: rect_left
        width: parent.width/2; height:  30; z: 1; color: "#deb887"
        border.color: "black"; border.width: 3; radius: 10
        Text {
            id: txt1; text: "Sender"; color: "yellow"; font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }
        TextField {
            id: msg; anchors.left: parent.left; anchors.leftMargin: 10
            placeholderText: "Enter path file"; font.pixelSize: 10; y: 35
        }
        Button {
            anchors.left: msg.right; anchors.leftMargin: 10
            anchors.verticalCenter: msg.verticalCenter
            width: 60; text: "send";font.pointSize: 15
            onClicked: {
                if(msg.text !== ""){
                    myData.myPathFile = msg.text
                    checkPathFile = myData.loadFile();
                    console.log(checkPathFile);
                }
            }
        }
    }
    Rectangle {
        id: rect_right; width: parent.width/2 - 5; height:  30
        x : parent.width/2 + 5;  z : 1; color: "#deb887"
        border.color: "black"; border.width: 3; radius: 10
        Text {
            id: txt4; text: "Receiver"; color: "yellow"; font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Rectangle{
        id: rectLoadFileError; color: "orange"
        anchors.top: rect_right.bottom; anchors.topMargin: 5
        anchors.right: parent.right; width: parent.width/2 - 5; height: 70
        visible: !checkPathFile
        Text {
            id: txtLoadFileError
            text: "Path file not found!"
            anchors.fill: rectLoadFileError; anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20; visible: !checkPathFile
        }
    }

    ListView {
        id: listView; spacing: 2
        width: parent.width/2 - 5; height:  parent.height
        anchors.top: rect_right.bottom; anchors.topMargin: 5
        anchors.right: parent.right; visible: checkPathFile
        model: myData.myList
        delegate: Rectangle{
            id: rect11; color: "orange"; anchors.margins: 3; radius: 10
            border.width: 1; border.color: "black"; width: listView.width
            height: 40
            Text {
                text: modelData
                anchors.fill: rect11; anchors.margins: 10
                font.pixelSize: 15; maximumLineCount: 2
                wrapMode: Text.Wrap; elide: Text.ElideRight
            }
        }
    }
}
