import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        model: Wrapper.myListPerson
        anchors.fill: parent
        delegate: Rectangle{
            width: parent.width
            height: 90
            border.width: 1
            border.color: "cyan"
            radius: 10
            color: "gray"

            RowLayout {
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text: modelData.name
                    Layout.fillWidth: true
                    onEditingFinished: {
                        Wrapper.setNames(index,text)
                    }
                }

                SpinBox{
                    editable: true
                    value: modelData.age
                    Layout.fillWidth: true
                    onValueChanged: {
                        if(value === model.age){

                        }else{
                            Wrapper.setAge(index,value);
                        }
                    }
                }
                Rectangle{
                    width: 50
                    height: 50
                    color: modelData.favoriteColor
                }
            }
        }
    }

    Button{
        id: mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text: "Add person"
        onClicked: {
            Wrapper.addPerson()
        }
    }
}
