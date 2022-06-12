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


    Rectangle {
        width: 200
        height: 50
        anchors.centerIn: parent
        color: "green"
        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Load Menu"
            font.pixelSize: 20
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_ORDER)
            }
        }
    }
}
