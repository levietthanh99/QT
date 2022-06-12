import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text: "Data: " + APP_MODEL.data
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            APP_CTR.changeData(mouseX);
        }
    }
}
