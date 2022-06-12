import QtQuick 2.12
import QtQuick.Window 2.12
//import my.namespace 1.0
 import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Loader {
        id: mLoader
        sourceComponent : ahihi

        onLoaded: {
            console.log("loader success")
        }
    }

    Component {
        id: ahihi
        Rectangle {
            width: 50
            height: 50
            color: "blue"
            x: 300
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
//            mLoader.sourceComponent = ahihi
            mLoader.source = "file:///F:/Onedirve_j2/OneDrive - www.microsoft365.me/QT/BasicQml/ButtonDemo/MyItem.qml"

        }

    }



}
