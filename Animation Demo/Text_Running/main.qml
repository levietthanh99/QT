import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.3
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Running Text")
    Rectangle {
        anchors.centerIn: parent

        id: rect
        width: 100
        height: 100
        property int aTime: 3000
        color: "green"
        clip: true

        TextRunning {
            id: t1
            text: "Xin chao cac ban"
            Component.onCompleted: {
                testAnimation.start()
            }
        }
        TextRunning {
            id: t2
            anchors.verticalCenter: rect.verticalCenter
            text: "Xin chao cac ban den voi lop hoc lap trinh qt"
        }
        TextRunning {
            id: t3
            anchors.bottom: rect.bottom
            text: "Xin chao cac ban den voi lop hoc lap trinh qt"
        }
    }
    SequentialAnimation {
        id: testAnimation
        running: true
        loops: Animation.Infinite
        NumberAnimation {target: t1; property: "x";
            from: 0; to: t1.des; duration: t1.dur}
        PauseAnimation {duration: t1.delay}
        NumberAnimation {target: t2; property: "x";
            from: 0; to: t2.des; duration: t2.dur}
        PauseAnimation {duration: t2.delay}
        NumberAnimation {target: t3; property: "x";
            from: 0; to: t3.des; duration: t3.dur}
        PauseAnimation {duration: t3.delay}
    }

}
