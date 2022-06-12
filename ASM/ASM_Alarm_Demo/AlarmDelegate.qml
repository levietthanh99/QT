import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

ItemDelegate {
    id: root
    width: parent.width
    checkable: true
    property var dayOfWeeks: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

    contentItem: ColumnLayout {
        spacing: 0
        RowLayout{
            // time
            Text {
                id: txt_time
                text: hour + ":" + ((minute > 9)?minute: ("0"+minute)) + " AM"
                font.pointSize: 20
            }
            Item {
                Layout.fillWidth: true
            }
            Switch {
                checked: model.activated
                onClicked: model.activated = checked
                x : 350
            }
        }
        // date
        Text {
            id: txt_date
            text: month + "/" + day + "/" + year
            font.pointSize: 11
            visible: true

            Text {
                id: txt_note
                anchors.left: txt_date.right
                text: (label !== "")?(" . " + label):""
                visible: !root.checked
                font.pointSize: 11
            }
        }

        CheckBox {
            id: alarmRepeat
            text: "Repeat"
            font.pointSize: 11
            checked: repeat
            visible: root.checked
            onToggled: repeat = checked
        }
        // day of week
        ListView {
            id: dayRepeat
            visible: root.checked && repeat
            Layout.fillWidth: true
            height: 45
            orientation: ListView.Horizontal
            model: daysToRepeat

            delegate: RoundButton {
                font.pointSize: 11
                text: dayOfWeeks[dayOfWeek]
//                flat: true
                checked: repeat
                checkable: true
                onToggled: model.repeat = checked
            }
        }

        // note

        TextField {
            id: alarmNote
            placeholderText: "Enter description here"
            visible: root.checked
            text: label
            font.pointSize: 14
            onTextEdited: label = text

            Rectangle {
                anchors.fill: parent
                opacity: 0.5
                color: "red"
            }
        }
        // button delete
        Button {
            id: deleteAlarmButton
            text: "Delete"
            width: 80
            height: 40
            visible: root.checked
            onClicked: root.ListView.view.model.remove(root.ListView.view.currentIndex, 1)
        }
    }
}
