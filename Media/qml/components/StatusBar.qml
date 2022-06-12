import QtQuick 2.9;
import AppEnums 1.0
 import QtQml 2.12;

Rectangle {
    id: root
    color: "black"
    visible: !MPLAYER_CTRL.isFullScreenVideo

    Image {
        id: btn_home; height: 20; width: 20
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 10
        }
        source: "qrc:/images/homeBtn"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                SCREEN_CTRL.setModeDisplay(false);
                SCREEN_CTRL.requestBackToHome();
                MPLAYER_CTRL.requestSendMetaData();
            }
        }
    }

    Image {
        id: btn_back;height: 20; width: 20
        anchors {
            verticalCenter: parent.verticalCenter
            left: btn_home.right
            leftMargin: 20
        }
        source: "qrc:/images/backBtn"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(SCREEN_CTRL.countScreenInStack() === 1){
                    SCREEN_CTRL.setModeDisplay(false);
                    SCREEN_CTRL.requestBackToHome();
                    MPLAYER_CTRL.requestSendMetaData();
                }else {
                    SCREEN_CTRL.popScreen()
                }
            }
        }
    }

    Rectangle {
        visible: (SCREEN_MODEL.currentScreen === "qrc:/qml/screens/MusicPlayerScreen.qml")?true:false
        id: btn_list
        width: 36
        height: 36
        color: "white"
        border {
            width: 1
            color: "blue"
        }

        anchors {
            verticalCenter: parent.verticalCenter
            left: btn_back.right
            leftMargin: 20
        }
        Text {
            anchors.centerIn: parent
            text : "list"
            font.bold: true
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MUSIC_LIST)
            }
        }
    }

    Image {
        visible: (SCREEN_MODEL.currentScreen === "qrc:/qml/screens/VideoPlayerScreen.qml")?true:false
        id: btn_full_screen ;
        height: 36;
        width: 36

        anchors {
            verticalCenter: parent.verticalCenter
            left: btn_home.right
            leftMargin: 20
        }
        source: "qrc:/images/fullScreenIcon.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                MPLAYER_CTRL.setIsFullScreenVideo(true)
            }
        }
    }

    Text {
        id: time
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -70
        text: myTime.timeString
        color: "white"
        font {
            pixelSize: 25
            bold: true
        }
    }
    Text {
        id: date
        anchors.left: time.right
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        text: myDate.dateString
        color: "white"
        font.pixelSize: 15
    }

    QtObject {
        id: myTime
        property var locale: Qt.locale();
        property date currentTime: new Date();
        property string timeString;

        Component.onCompleted: {
            timeString = currentTime.toLocaleTimeString(locale, Locale.ShortFormat);
        }
    }
    QtObject {
        id: myDate
        property var locale: Qt.locale();
        property date currentTime: new Date();
        property string dateString;

        Component.onCompleted: {
            dateString = currentTime.toLocaleDateString();
        }
    }
}
