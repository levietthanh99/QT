import QtQuick 2.0; import QtQml 2.12

Rectangle {
    property int index: 0
    property size menuButtonSize
    property int menuButtonLeftMargin
    property int menuButtonTopMargin

    property bool current
    property color oppositeColor
    property string title

    id: root
    state: "closed"
    states: [
        State {name: "closed"},
        State {
            name: "menu"
            PropertyChanges { target: root; x: getMenuPos(root.index).x;
                y: getMenuPos(root.index).y}
            PropertyChanges {target: mouseArea; visible: true}
            PropertyChanges { target: cardTitle;
                anchors.leftMargin: root.menuButtonSize.width * 0.5;
                anchors.topMargin: root.menuButtonSize.height * 0.3;}
            PropertyChanges {target: root; radius: 10}
        },
        State {
            name: "hidden"
            PropertyChanges {target: root; visible: false}
            PropertyChanges {target: mouseArea; visible: false}
        }
    ]
    transitions: [
        Transition {
            from: "*"
            to: "*"

            NumberAnimation {target: root; properties: "x, y, radius";
                duration: 500; easing.type: Easing.OutQuint}
            NumberAnimation {target: cardTitle;
                properties: "anchors.leftMargin, anchors.topMargin";
                duration: 500; easing.type: Easing.OutQuint}
        }
    ]

    Text {
        id: cardTitle
        text: root.title.toUpperCase()
        anchors {
            top: parent.top
            left: parent.left
            topMargin: root.menuButtonSize.height * 0.5
            leftMargin: 75 + root.menuButtonLeftMargin
        }
        font {
            pointSize: 18
            bold: true
        }
        color: root.oppositeColor
    }

    MouseArea {
        id: mouseArea
        visible: false
        anchors.fill: parent
        onClicked: {
            root.parent.cardSelected(root)
        }
    }

    Connections {
        target: root.parent
        onCardSelected: {
            if(card.index === root.index){
                root.state = "closed"
                root.current = true;
            }

            root.state = root.state === "menu"? "hidden" : "closed";
            root.current = root.state === "closed";
        }
        onMenuOpened: {
            root.state = "menu"
        }
        onMenuCancelled: {
            root.state = root.current ? "closed": "hidden";
        }
    }

    function getMenuPos(indexVar){
        var heightMenuBtn = root.menuButtonSize.height
        var widthMenuBtn = root.menuButtonSize.width
        var xForFistItem = widthMenuBtn + root.menuButtonLeftMargin
        var yForFirstItem = heightMenuBtn + root.menuButtonTopMargin
        var deltaX = cardTitle.x
        var deltaY = cardTitle.y + cardTitle.height
        if(indexVar === 0)
        {
            return Qt.point(xForFistItem, yForFirstItem)
        }else {
            return Qt.point(xForFistItem + indexVar*deltaX,
                            yForFirstItem + indexVar*deltaY)
        }
    }
}
