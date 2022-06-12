import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


//    Rectangle {
//        anchors.fill: parent
//        color: "cyan"
//    }


//    Grid {
//        rows: 3
//        rowSpacing: 10
//        columnSpacing: 10
//        anchors.fill: parent
//        BlockLoader {
//            width: 100
//            height: 100
//        }
//        SharinganLoader {
//            width: 100
//            height: 100
//        }
//        ClockSpinner {
//            width: 100
//            height: 100
//        }

//        FishSpinner {
//            width: 100
//            height: 100
//        }

//        PulseLoader {
//            width: 100
//            height: 100
//        }
//        RectangleLoader {
//            width: 100
//            height: 100
//        }
//    }

    Rectangle {
        id: rect
        width: 100
        height: width * 2
        color: "blue"

        focus: true
        Keys.onSpacePressed: {
            height = Qt.binding(function() { return width * 3 })
        }

        Button {
            anchors.left: parent.right
            anchors.leftMargin: 30
            onClicked: rect.width = 20
        }
    }


}
