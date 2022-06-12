import QtQuick 2.9;  import QtQml 2.12

Rectangle {
    id: root
    color: "black"

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
                SCREEN_CTRL.popToRoot();
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
                SCREEN_CTRL.popScreen();
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
