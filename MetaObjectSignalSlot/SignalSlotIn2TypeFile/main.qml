import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import myCustom 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyClass {
        id: myClass
    }
    MouseArea {
        anchors.fill: parent
        onClicked: myClass.initTest()
    }

    Connections {
        target: myClass
        ignoreUnknownSignals: true
        onSignaltest: {
            console.log("OnSignaltest");
        }
    }
}
