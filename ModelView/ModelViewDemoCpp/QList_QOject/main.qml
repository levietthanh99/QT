import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        spacing: 5
        model: myModel
        anchors.fill: parent

        delegate: Rectangle{
            width: 400
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: 1
            border.color: "black"
            radius: 10
            color: "cyan"

            Text {
                id: name
                text: modelData.name + " - " +
                      modelData.favoriteColor +
                      " - " + modelData.age
                font.pixelSize: 25
                anchors.centerIn: parent
            }
        }
    }
}
