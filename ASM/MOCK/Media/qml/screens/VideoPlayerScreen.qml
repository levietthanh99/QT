import QtQuick 2.9
import "../components"
import AppEnums 1.0
import QtMultimedia 5.5
import QtQuick.Layouts 1.6

Item {
    id: root
    ColumnLayout {
        anchors.fill: parent
        StatusBar {
            id: status_bar
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 50
        }
        VideoOutput {
            id: video_output
            Layout.preferredWidth: parent.width
            Layout.fillHeight: true
            source: MPLAYER_CTRL
            visible: true
        }

    }

    Row {
        id: buttonPlayer
        spacing: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 50
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
                    console.log("Do nothing")
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
                    MPLAYER_CTRL.requestPlayVideo();
                    MPLAYER_CTRL.setIsFullScreenVideo(false)
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
                    console.log("Do nothing")
                }
            }
        }
    }


    ProgressBar {
        visible: !MPLAYER_CTRL.isFullScreenVideo
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

    Text {
        id: fileName
        text: MPLAYER_MODEL.videoName
        color: "red"
        font.pixelSize: 22
        anchors.bottom: progressBar.top
        anchors.bottomMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 30
        visible: !MPLAYER_CTRL.isFullScreenVideo
    }
}
