import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
            id: container; width: 200; height: 200; color: "grey"
            Rectangle {id: childRect; width: 50; height: 50; color: "red"}
            states : [
                State {
                    name: "reAnchors"
                    AnchorChanges {
                        target: childRect
                        anchors.right: container.right
                    }
                },
                State {
                    name: "reAnchors1"
                    AnchorChanges {
                        target: childRect
                        anchors.bottom: container.bottom
                    }
                },
                State {
                    name: "reAnchors2"
                    AnchorChanges {
                        target: childRect
                        anchors.left: container.left
                    }
                },
                State {
                    name: "reAnchors3"
                    AnchorChanges {
                        target: childRect
                        anchors.top: container.top
                    }
                }
            ]

            transitions: Transition { AnchorAnimation { duration: 2000}}

            Rectangle {id: mouse1; width: 50; height: 50; color: "green"; radius: 25;
                anchors.right: container.right
                MouseArea {
                    anchors.fill: parent
                    onClicked: container.state = "reAnchors"
                }
            }
            Rectangle {id: mouse2; width: 50; height: 50; color: "green"; radius: 25
                anchors.bottom: container.bottom
                anchors.right: container.right
                MouseArea {
                    anchors.fill: parent
                    onClicked: container.state = "reAnchors1"
                }
            }
            Rectangle {id: mouse3; width: 50; height: 50; color: "green"; radius: 25;
                anchors.bottom: container.bottom
                anchors.left: container.left
                MouseArea {
                    anchors.fill: parent
                    onClicked: container.state = "reAnchors2"
                }
            }
            Rectangle {id: mouse4; width: 50; height: 50; color: "green"; radius: 25
                anchors.top: container.top
                anchors.left: container.left
                MouseArea {
                    anchors.fill: parent
                    onClicked: container.state = "reAnchors3"
                }
            }


        }
}
