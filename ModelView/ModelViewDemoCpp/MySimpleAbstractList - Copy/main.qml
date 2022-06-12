import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
 import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        spacing: 10
        width: 200
        height: 300

        clip: true

        model: myModel
        delegate: Rectangle {
            color: "green"
            width: parent.width
            height: 30
            Text{
                        text: name + "   " + size;
                    }
        }

        ScrollBar.vertical: ScrollBar{
            policy: ScrollBar.AsNeeded
//            anchors.left: parent.left
        }



    }

    TextField {
        id: name_id
        y : 200
        placeholderText: qsTr("Enter name")
    }



    TextField {
        id: size_id
        y : 300
        placeholderText: qsTr("Enter size")
    }

    Button {
        y: 400
        text: "addList"
        onClicked: {
            myModel.addAnimal1(name_id.text, size_id.text)
        }
    }

    Connections {
        target: asdf
        onRequestUpdate: {
            listView.positionViewAtEnd()
        }
    }
}
