import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
Window {
    width: 300
    height: 600
    visible: true
    title: "Tryndamere Player"
    Rectangle {
        width: 300
        height: parent.height
        anchors.centerIn: parent
        clip: true
        ListView {
            id: listSong
            anchors.fill: parent
            anchors.left: parent.left

            spacing: 4
            model: SongModel
            focus: true
            property string songPath: ""
            property int indexTemp: 0
            delegate: RunningText {
                id: rTxt1
                text: name

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        listSong.currentItem.color = "black"
                        anim.stop()
                        listSong.currentItem.x = 0
                        listSong.currentIndex = index
                        listSong.songPath = ""
                        listSong.songPath = path + name
                        listSong.indexTemp = index
//                        console.log(listSong.currentIndex);
//                        console.log(index);
                        console.log("onlick: " + listSong.indexTemp);
                    }
                }
            }
            onSongPathChanged: {
                console.log("paht:")
                console.log(listSong.songPath)
                console.log(listSong.indexTemp)
                listSong.currentItem.color = "red"
                anim.start();
            }
            PropertyAnimation{
                id: anim
                target:listSong.currentItem
                property: "x"
                from: 0
                to: listSong.currentItem.des
                duration: listSong.currentItem.dur
                loops: Animation.Infinite
            }
            Component.onCompleted:{
                 listSong.currentItem.color = "red"
            }
        }
    }
}
