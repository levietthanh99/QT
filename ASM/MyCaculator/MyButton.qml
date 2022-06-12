import QtQuick 2.0
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    color: "#dcdcdc"
    border.width: 1
    border.color: "#9400d3"
    Layout.preferredWidth: 70
    Layout.preferredHeight: 40

    signal btnClicked()
    signal btnEntered()
    signal btnExited()
    property alias btnLabel: txt.text
    property alias myColor: root.color
    property alias myLabelBold: txt.font.bold

    Text {
        id: txt
        anchors.centerIn: parent
        font.pixelSize: 20
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled : true
        onClicked: {
            btnClicked()
        }
        onEntered: {
            btnEntered()
            myColor = "gray"
        }
        onExited: {
            btnExited()
            myColor = "#dcdcdc"
        }
    }
}
