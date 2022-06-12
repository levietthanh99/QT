import QtQuick 2.9
import "../components"
import AppEnums 1.0

Item {
    id: root
    StatusBar {
        id: status_bar
        width: parent.width
        height: 50
    }

    Rectangle {
        id: metaData
        width: 300
        height: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -100
        anchors.verticalCenterOffset: -50
        clip: true

        Text {
            id: title
            height: 50
            anchors.top: parent.top
            text: (MPLAYER_MODEL.currentTitle === "")?
                      (TRANSLATE_MODEL.STR_TITLE + " : " + TRANSLATE_MODEL.STR_UNKNOWN):
                      TRANSLATE_MODEL.STR_TITLE + " : " + MPLAYER_MODEL.currentTitle
            font.pixelSize: 22
            elide: Text.ElideRight
        }
        Text {
            id: albumName
            height: 40
            anchors.verticalCenter: parent.verticalCenter
            text: (MPLAYER_MODEL.currentAlbumName === "")?
                      (TRANSLATE_MODEL.STR_ALBUM + " : " + TRANSLATE_MODEL.STR_UNKNOWN):
                      TRANSLATE_MODEL.STR_ALBUM + " : " + MPLAYER_MODEL.currentAlbumName
            font.pixelSize: 18
            elide: Text.ElideRight
        }
        Text {
            id: artist
            height: 40
            anchors.bottom: parent.bottom
            text: (MPLAYER_MODEL.currentArtist === "")?
                      (TRANSLATE_MODEL.STR_ARTIST + " : " + TRANSLATE_MODEL.STR_UNKNOWN):
                      TRANSLATE_MODEL.STR_ARTIST + " : " + MPLAYER_MODEL.currentArtist
            font.pixelSize: 18
            elide: Text.ElideRight
        }
    }

    Image {
        id: coverArt
        width: 220
        height: 220
        anchors.top: status_bar.bottom
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 30
        source: (MPLAYER_MODEL.isCurrentCoverArtNull)?"qrc:/images/musicIcon.png":
                                                       ("file://" + MPLAYER_MODEL.currentPathCoverArt)

    }

    Row {
        id: buttonPlayer
        spacing: 40
        anchors.bottom: progressBar.top
        anchors.bottomMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 60
        Rectangle {
            width: 80
            height: 50
            color: "#87cefa"
            Image {
                id: btn_previous
                width: 40
                height: 40
                anchors.centerIn: parent
                source: "qrc:/images/previousIcon.png"
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    MPLAYER_CTRL.requestPrevious();
                }
            }
        }
        Rectangle {
            width: 80
            height: 50
            color: "#87cefa"
            Image {
                id: btn_play_pause
                width: 40
                height: 40
                anchors.centerIn: parent
                source: (MPLAYER_MODEL.currentStatus === 1)?
                            "qrc:/images/pauseIcon.png":"qrc:/images/playIcon.png"
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    MPLAYER_CTRL.requestPlay();
                }
            }
        }
        Rectangle {
            width: 80
            height: 50
            color: "#87cefa"
            Image {
                id: btn_next
                width: 40
                height: 40
                anchors.centerIn: parent
                source: "qrc:/images/nextIcon.png"
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    MPLAYER_CTRL.requestNext();
                }
            }
        }
    }


    ProgressBar {
        id: progressBar
        width: 600
        height: 40
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        maximumValue: MPLAYER.duration
        value: MPLAYER.position
        onSliderOnPressed: {
            MPLAYER.setPosition(value)
        }
    }

}
