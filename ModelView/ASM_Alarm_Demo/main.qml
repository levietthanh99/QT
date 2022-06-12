import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12
import QtQml 2.12

ApplicationWindow {
    id: window
    width: 400
    height: 500
    visible: true
    property var dayOfWeeks: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

    ListView {
        id: alarmListView
        anchors.fill: parent
        model: AlarmModel {}
        delegate: AlarmDelegate {}
    }




}


