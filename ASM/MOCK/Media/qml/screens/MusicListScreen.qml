import QtQuick 2.9
import "../components"
import AppEnums 1.0

Item {
    id: root
    StatusBar {
        id: status_bar
        width: parent.width
        height: 50
    }

    Text {
        anchors.centerIn: parent
        text: TRANSLATE_MODEL.STR_LIST_EMPTY
        visible: MPLAYER_MODEL.currentMediaName === ""
    }

    ListView {
        id: listView
        anchors.top: status_bar.bottom
        width: parent.width
        height: 300
        spacing: 0

        model: MLIST_MODEL.listSong

        delegate: ScrollingText {
            id: wrapper
            text: modelData
            height: 50
            width: parent.width
            fontBold: (MPLAYER_MODEL.currentMediaName === modelData)
            colorText: (MPLAYER_MODEL.currentMediaName === modelData)?"red": "black"
            visibleIcon: (MPLAYER_MODEL.currentMediaName === modelData)

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width*3
                height: 1
                color: "#87cefa"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if(MPLAYER_MODEL.currentMediaName !== modelData){
                        MPLAYER_MODEL.setCurrentStatus(0) // set current status is stopped
                        MPLAYER_MODEL.setCurrentMediaName(modelData)
                        MPLAYER_CTRL.requestPlay()
                        anim.stop()
                        listView.currentItem.x = 0
                        listView.currentIndex = index
                        wrapper.currentItemChange();
                        anim.start()
                    }
                }
            }
        }

        PropertyAnimation {
            id: anim; target: listView.currentItem; property: "x";
            from: 0; to: (listView.count === 0)?0:listView.currentItem.des;
            duration:(listView.count === 0)?0:listView.currentItem.dur;
            loops: Animation.Infinite
        }
    }


}
