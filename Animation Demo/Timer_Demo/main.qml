import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle { id: demoRect; width: 50; height: 50; color: "blue"}

    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: {
            if(demoRect.width < 500){
                demoRect.width += 10
            }else {
                demoRect.width = 50
            }
        }
    }
    Item {
        anchors.top: demoRect.bottom
        anchors.topMargin: 20
        Timer {
            interval: 500; running: true; repeat: true
            onTriggered: time.text = Date().toString()
        }

        Text { id: time ; font.pixelSize: 20}
    }
}
