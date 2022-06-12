import QtQuick 2.0

Item {
    signal clicked
    signal cancelled
    property color color: "white"
    property color closeColor: "#516C8D"
    property color currentColor: color

    id: root
    state: "menu"
    states: [State {
            name: "menu"
            PropertyChanges { target: root; currentColor: color }
        },
        State {
            name: "close"
            PropertyChanges {target: firstBar; y: root.height/2- secondBar.height/2;
            width: getNewWidth(); x: - (getNewWidth() - secondBar.width)/2; rotation: 45}

            PropertyChanges {target: secondBar; visible: false}

            PropertyChanges {target: thirdBar; y: root.height/2- secondBar.height/2;
            width: getNewWidth(); x: - (getNewWidth() - secondBar.width)/2; rotation: -45}

            PropertyChanges {target: root; currentColor: closeColor}
        }
    ]
    transitions: [
        Transition {
            NumberAnimation {properties: "x, y, width, rotation"; duration: 200}
        }
    ]
    Rectangle {
        id: firstBar
        width: parent.width
        height: (parent.height /3)*0.7
        x: secondBar.x
        y: secondBar.y - secondBar.height*1.4
        radius: 20
        color: root.currentColor
        transformOrigin: Item.Center
    }

    Rectangle {
        id: secondBar
        width: parent.width
        height: (parent.height /3)*0.7
        anchors.centerIn: parent
        radius: 20
        color: root.currentColor
    }
    Rectangle {
        id: thirdBar
        width: parent.width
        height: (parent.height /3)*0.7
        x: secondBar.x
        y: secondBar.y + secondBar.height*1.4
        radius: 20
        color: root.currentColor
        transformOrigin: Item.Center
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(root.state === "menu"){
                root.clicked()
                root.state = "close"
            }else {
                root.cancelled();
                root.state = "menu"
            }
        }
    }

    function switchToMenu(cardColor){
        root.color = cardColor
        root.state = "menu"
    }
    function getNewWidth(){
        return root.width*1.424 - secondBar.height
    }

}
