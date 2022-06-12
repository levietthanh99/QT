import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
 import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    MouseArea {
        anchors.fill: parent
        onClicked: {
//            console.log(MediaModel.pathFolder + "/" + MediaFileName)
            MediaModel.playMedia("C:/Users/thanh/Music/dptk.mp3")
        }
    }

//    ListView {
//        anchors.fill: parent
//        model: MediaModel
//        delegate: Rectangle {
//            width: 640
//            height: 80

//            border.width: 1
//            border.color: "black"

//            Text {
//                anchors.fill: parent
//                text: MediaFileName + "***" + MeidaSongTitle
//            }

//            MouseArea {
//                anchors.fill: parent
//                onClicked: {
//                    console.log(MediaModel.pathFolder + "/" + MediaFileName)
//                    MediaModel.playMedia(MediaModel.pathFolder + "/" + MediaFileName)
//                }
//            }
//        }
//    }


}
