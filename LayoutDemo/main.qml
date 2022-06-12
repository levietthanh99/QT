import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Window {
    id: root
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout {
        spacing: 5
        id: columnLayout
        width: root.width
        RowLayout {
            id: rowLayout
            spacing: 0
            width: columnLayout.width
            Rectangle {
                id: rect1
                Layout.fillWidth: true
                Layout.margins: 10
                height: 50
                color: "orange"

                Text {
                    id: txt1
                    text: "Sender"
                    anchors.centerIn: parent
                    font.pointSize: 25
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.margins: 10
                height: 50
                color: "orange"

                Text {
                    id: txt2
                    text: "Receiver"
                    anchors.centerIn: parent
                    font.pointSize: 25
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignLeft |  Qt.AlignTop
            GroupBox {
                id: rowBox
                Layout.preferredWidth: root.width / 2
                Layout.alignment: Qt.AlignLeft |  Qt.AlignTop
                Layout.margins: 10
                RowLayout {
                    id: rowLayout1
                    anchors.fill: parent
                    TextField {
                        id: txt5
                        placeholderText: "This wants to grow horizontally"
                        Layout.fillWidth: true
                        font.pointSize: 20
                    }
                    Button {
                        text: "send"
                        onClicked: {
                            list_model.append({"msg": txt5.text})
                        }
                    }
                }
            }

            ListModel {
                id: list_model

            }

            ListView {
                spacing: 10
                id: listView
                width: root.width / 2
                height: root.height
                model: list_model
                delegate: Rectangle{
                    id: rect11
                    color: "orange"
                    width: listView.width
                    Layout.margins: 10
                    height: 50
                    Text {
                        id: text1
                        text: msg
                        anchors.fill: rect11
                        anchors.margins: 10
                        font.pixelSize: 20
                        maximumLineCount: 2
                        wrapMode: Text.Wrap
                        elide: Text.ElideRight
                    }
                }
            }
        }
    }


}
