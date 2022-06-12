import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 200
    height: 200
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text: "shared memory read"
        font.pixelSize: 20
    }
    MouseArea {
        anchors.fill: parent
        onClicked: HMI_CTRL.readShareMemory()
    }
}
