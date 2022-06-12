import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
 import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")






    ListView {
        id: ahihi
        anchors.fill: parent
        model: MediaModel
        delegate: Rectangle {
            id: wrapper
            width: 640
            height: 200
            border.width: 1
            border.color: "black"

            Column {
                anchors.fill: parent
                Text {
                    width: parent.width
                    text: MediaFileName + "     index: " +index
                    horizontalAlignment: Text.AlignHCenter
                    color: wrapper.ListView.isCurrentItem ? "red" : "black"
                }
                Image {
                    z: 1
                    width: parent.width; height: 100
                    source: MediaModel.iscurrentThumbnailNull?"qrc:/Image/thumail.png": ("file:///" + MediaModel.currentPathThubnail)
                    fillMode: Image.PreserveAspectFit
                    horizontalAlignment: Image.AlignHCenter
                }

                Text {
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    text: (MediaModel.currentSongTitle === "")?"Title: Unknow" : ("Title: " +MediaModel.currentSongTitle)
                }
                Text {
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    text:  (MediaModel.currentArtist === "")?"Artist: Unknow" : ("Artist: " + MediaModel.currentArtist)
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(MediaModel.pathFolder + "/" + MediaFileName)

                    MediaModel.playMedia(MediaModel.pathFolder, MeidaSongName)
                    console.log(ahihi.count)

                    wrapper.ListView.view.currentIndex = index



                }
            }
        }
    }


}
