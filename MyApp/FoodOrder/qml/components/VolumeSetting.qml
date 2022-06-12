import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

RowLayout {
    spacing: 8
    Rectangle {
        id: decrease
        Layout.preferredWidth: 30
        Layout.preferredHeight: 30
        border.color: "#62B3F5"; border.width: 1; radius: 15;

        Text {anchors.centerIn: parent; text: "-"; font.pixelSize: 30; color: "#62B3F5"}

        MouseArea {
            anchors.fill: parent
            onClicked: slider.value -= 1;
        }
    }

    Slider {
        id: slider
        maximumValue: 10; minimumValue: 0
        value: SCREEN_CTRL.currentVolume
        stepSize: 1
        onValueChanged: {
            SCREEN_CTRL.setCurrentVolume(slider.value);
            SCREEN_CTRL.requestChangeVolume();
        }
        style: SliderStyle {
            groove:
                Rectangle {
                implicitWidth: 250; implicitHeight: 15
                anchors.verticalCenter: parent.verticalCenter
                border.width: 1; border.color: "#62B3F5"
                Rectangle {
                    color: "#62B3F5"
                    height: parent.height
                    width: parent.width * control.value / control.maximumValue
                }
            }


            handle: Rectangle {
                anchors.centerIn: parent
                border.color: "#62B3F5"
                border.width: 1
                implicitWidth: 30
                implicitHeight: 30
                radius: 15
                Text {
                    anchors.centerIn: parent
                    text: slider.value
                }
            }
        }
    }

    Rectangle {
        id: increase
        Layout.preferredWidth: 30
        Layout.preferredHeight: 30

        border.color: "#62B3F5"; border.width: 1; radius: 15;

        Text {anchors.centerIn: parent; text: "-"; font.pixelSize: 30; color: "#62B3F5"}

        MouseArea {
            anchors.fill: parent
            onClicked: {
                slider.value += 1;
            }
        }
    }
    Item {
        Layout.fillWidth: true
    }
}
