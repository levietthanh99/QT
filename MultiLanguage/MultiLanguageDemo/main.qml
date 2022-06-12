import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQml 2.12
Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: myTranslation.WINDOW_TITLE_STRING_ID
    Text { 
        id: helloLabel
        height: 50
        anchors {
            top: parent.top
            left: parent.left
            right:parent.horizontalCenter
            margins: 10
        }
        text: myTranslation.LABEL_STRING_ID
    }
    ComboBox {
        id: comboBox
        anchors {
            top: parent.top
            left: parent.horizonalCenter
            right: parent.right
            margins: 10
        }
        model: ["lang_en", "lang_vn", "lang_ko"]
        onCurrentTextChanged: {
            myTranslation.setTranslation(comboBox.currentText)
        }
    }
    Text {
        id: contentText
        wrapMode: Text.Wrap
        anchors {
            top: helloLabel.top
            left: parent.left
            right: parent.right
            margins: 10
        }
        text: myTranslation.CONTENT_STRING_ID
    }

    Text {
        width: 200
        height: 200
        text: qsTr("text") + myTranslation.EMPTY_STRING_ID
        anchors.bottom: parent.bottom
    }
}









































