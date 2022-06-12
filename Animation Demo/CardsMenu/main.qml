import QtQuick 2.12
import QtQuick.Window 2.12
////Local imports
//import "./qml"

Window {
    width: 720
    height: 1000
    visible: true
    title: qsTr("Hello World")
    color: "#DDDDDD"

    MenuStack {
        anchors.fill: parent
    }


}
