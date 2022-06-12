import QtQuick 2.9
import AppEnums 1.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id: root
    Loader {
        id: status_bar
        width: parent.width
        height: 50
        source: "qrc:/qml/components/StatusBar.qml"
    }

    SwipeView {
        id: my_swipview
        currentIndex: 0
        width: parent.width
        height: parent.height - 50
        anchors.top: status_bar.bottom

        RowLayout {
            id: firstPage
            Rectangle {
                id: r1
                Layout.fillWidth: true
                Layout.preferredHeight: my_swipview.height - 50
                Layout.margins: 20
                color: "#dcdcdc"
                border.color: "blue"
                border.width: 1

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10
                    Text {
                        text: TRANSLATE_MODEL.STR_MUSIC_TITLE
                        font.bold: true
                        font.pixelSize: 25
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    Image {
                        Layout.fillHeight: true
                        Layout.preferredWidth: 130
                        fillMode: Image.PreserveAspectFit
                        source: (SCREEN_CTRL.isCurrentCoverArtNull)?"qrc:/images/musicIcon.png":
                                                                     ("file://" + SCREEN_CTRL.currentPathCoverArt)
                        Layout.alignment : Qt.AlignHCenter | Qt.AlignVCenter
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                SCREEN_CTRL.requestDisplayMusic()
                                SCREEN_CTRL.setModeDisplay(false)
                            }
                        }
                    }

                    Text {
                        text: (SCREEN_CTRL.currentTitle === "")? TRANSLATE_MODEL.STR_TITLE + " : " + TRANSLATE_MODEL.STR_UNKNOWN
                                                               :(TRANSLATE_MODEL.STR_TITLE + " : " + SCREEN_CTRL.currentTitle)
                        font.pixelSize: 20
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    Text {
                        text: (SCREEN_CTRL.currentArtist === "")? TRANSLATE_MODEL.STR_ARTIST + " : " + TRANSLATE_MODEL.STR_UNKNOWN
                                                               :(TRANSLATE_MODEL.STR_ARTIST + " : " + SCREEN_CTRL.currentArtist)

                        font.pixelSize: 20
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }
                }

            }


            Rectangle {
                id: r2
                Layout.fillWidth: true
                Layout.preferredHeight: my_swipview.height - 50
                Layout.margins: 20
                color: "#dcdcdc"
                border.color: "blue"
                border.width: 1

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Text {
                        text: TRANSLATE_MODEL.STR_VIDEO_TITLE
                        font.bold: true
                        font.pixelSize: 25
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    Image {
                        id: videoIcon
                        Layout.fillHeight: true
                        Layout.preferredWidth: 130
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/images/videoIcon.png"
                        Layout.alignment : Qt.AlignHCenter | Qt.AlignVCenter

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                SCREEN_CTRL.requestDisplayVideo()
                                SCREEN_CTRL.setModeDisplay(false)
                            }
                        }
                    }


                    Text {
                        id: videoName
                        text: (SCREEN_CTRL.currentVideoName === "")?
                                  TRANSLATE_MODEL.STR_UNKNOWN : SCREEN_CTRL.currentVideoName;
                        font.pixelSize: 20
                        Layout.alignment: Qt.AlignHCenter
                    }


                }

            }
        }

        RowLayout {
            id: secondPage
            Rectangle {
                Layout.preferredWidth: my_swipview.width/2 - 40
                Layout.preferredHeight: my_swipview.height - 50
                color: "#dcdcdc"
                border.color: "blue"
                border.width: 1
                Layout.margins: 20

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 5
                    Text {
                        text: TRANSLATE_MODEL.STR_SETTINGS
                        font.bold: true
                        font.pixelSize: 25
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Layout.topMargin: 20
                    }

                    Image {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 100
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/images/setting_icon.png"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Layout.bottomMargin: 40
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_HOME_SETTUP)
                    }
                }
            }
        }
    }

    PageIndicator {
        id: indicator
        count: my_swipview.count
        currentIndex: my_swipview.currentIndex

        anchors.bottom: my_swipview.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: Rectangle {
            width: 30
            height: 8
            color: "blue"
            opacity: index === indicator.currentIndex ? 0.6: 0.2
        }
    }
}
