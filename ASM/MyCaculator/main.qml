import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    id: root
    width: 350
    height: 400
    visible: true
    title: "My Caculator"
    property bool isSetPara1: false
    property bool isSetPara2: false
    property bool isSetResult: false

    Rectangle {
        id: screen
        width: parent.width - 10
        anchors.horizontalCenter: parent.horizontalCenter
        height: 100
        color: "#dcdcdc"
        radius: 10
        border.color: "#9400d3"
        border.width: 1

        Text {
            id: smallDisplay
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 10
            font.pointSize: 15
            text: myControl.isUnaryOperator()? (myControl.myOperator + "(" + myControl.para1 + ")"):
                                               (myControl.para1 + myControl.myOperator)

            visible: isSetPara1
        }

        Text {
            id: bigDisplay
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            text: "0"
            font.bold: true
            font.pointSize: 25
        }
    }

    GridLayout {
        columns: 4
        anchors.horizontalCenter: screen.horizontalCenter
        anchors.top: screen.bottom
        anchors.topMargin: 20

        MyButton {
            btnLabel: "%"
            onBtnClicked: {
                myControl.setPara1(Number(bigDisplay.text))
                isSetPara1 = true
                myControl.setOperator("%")
                myControl.myCacluate()
                isSetResult = true
                bigDisplay.text = myControl.result
                isSetPara2 = false
            }
        }

        MyButton {
            btnLabel: "√"
            onBtnEntered: {
                myColor = "gray"
            }
            onBtnExited: {
                myColor = "#dcdcdc"
            }
            onBtnClicked: {
                myControl.setPara1(Number(bigDisplay.text))
                isSetPara1 = true
                myControl.setOperator("sqrt")
                myControl.myCacluate()
                isSetResult = true
                bigDisplay.text = myControl.result
                isSetPara2 = false
            }
        }

        MyButton {
            btnLabel: "x^2"
            onBtnClicked: {
                myControl.setPara1(Number(bigDisplay.text))
                isSetPara1 = true
                myControl.setOperator("sqr")
                myControl.myCacluate()
                isSetResult = true
                bigDisplay.text = myControl.result
                isSetPara2 = false
            }
        }
        MyButton {
            btnLabel: "1/x"
            onBtnClicked: {
                myControl.setPara1(Number(bigDisplay.text))
                isSetPara1 = true
                myControl.setOperator("1/")
                myControl.myCacluate()
                isSetResult = true
                bigDisplay.text = myControl.result
                isSetPara2 = false
            }
        }

        MyButton {
            btnLabel: "CE"
            onBtnClicked: {
                bigDisplay.text = "0"
                isSetPara2 = false
                isSetResult = false
            }

        }
        MyButton {
            btnLabel: "C"
            onBtnClicked: {
                bigDisplay.text = "0"
                isSetPara1 = false
                isSetPara2 = false
                isSetResult = false
            }
        }
        MyButton {
            Image {
                Layout.preferredWidth: 25
                Layout.preferredHeight: 25
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                source: "backspace.png"
            }

            onBtnClicked: {
                if(bigDisplay.text !== "0"){
                    if(bigDisplay.text.length > 1){
                        bigDisplay.text = bigDisplay.text.substring(0, bigDisplay.text.length - 1);
                    }else{
                        bigDisplay.text = "0"
                    }
                }
            }
        }
        MyButton {
            btnLabel: ":"
            onBtnClicked: {
                if(!isSetPara1){
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara1(Number(bigDisplay.text))
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }else{
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara2(Number(bigDisplay.text))
                    myControl.myCacluate()
                    myControl.setPara1(myControl.result)
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }
            }
        }
        MyButton {
            id: btn7
            btnLabel: "7"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            id: btn8
            btnLabel: "8"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            id: btn9
            btnLabel: "9"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            btnLabel: "x"
            onBtnClicked: {
                if(!isSetPara1){
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara1(Number(bigDisplay.text))
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }else{
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara2(Number(bigDisplay.text))
                    myControl.myCacluate()
                    myControl.setPara1(myControl.result)
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }
            }
        }
        MyButton {
            btnLabel: "4"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }

        MyButton {
            btnLabel: "5"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            btnLabel: "6"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            btnLabel: "-"
            onBtnClicked: {
                if(!isSetPara1)
                {
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara1(Number(bigDisplay.text))
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }else{
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara2(Number(bigDisplay.text))
                    myControl.myCacluate()
                    myControl.setPara1(myControl.result)
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }
            }
        }
        MyButton {
            id: btn1
            btnLabel: "1"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            id: btn2
            btnLabel: "2"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            id: btn3
            btnLabel: "3"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            btnLabel: "+"
            onBtnClicked: {
                if(!isSetPara1){
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara1(Number(bigDisplay.text))
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }else{
                    isSetResult = false
                    isSetPara2 = false
                    myControl.setPara2(Number(bigDisplay.text))
                    myControl.myCacluate()
                    myControl.setPara1(myControl.result)
                    isSetPara1 = true
                    myControl.setOperator(btnLabel)
                    bigDisplay.text = "0"
                }
            }
        }
        MyButton {
            btnLabel: "+/-"
            onBtnClicked: {
                if(bigDisplay.text[0] !== "-"){
                    bigDisplay.text = "-" + bigDisplay.text
                }else{
                    bigDisplay.text = bigDisplay.text.slice( 1 );
                }
            }
        }
        MyButton {
            id: btn0
            btnLabel: "0"
            myLabelBold: true
            onBtnClicked: {
                if(isSetResult){
                    isSetResult = false
                    isSetPara1 = false
                    isSetPara2 = false
                    bigDisplay.text = btnLabel
                }else{
                    if(bigDisplay.text === "0"){
                        bigDisplay.text = btnLabel
                    }else{
                        bigDisplay.text += btnLabel
                    }
                }
            }
        }
        MyButton {
            btnLabel: "."
            onBtnClicked: {
                // if string in bigDisplay not contain '.' --> add '.' in string
                if(bigDisplay.text.includes(".") === false){
                    bigDisplay.text += ".";
                }

            }
        }
        MyButton {
            id: btnResult
            btnLabel: "="
            onBtnClicked: {
                if(smallDisplay.visible){
                    myControl.setPara2(Number(bigDisplay.text))
                    isSetPara2 = true
                    myControl.myCacluate()
                    isSetResult = true
                    isSetPara1 = false
                    bigDisplay.text = myControl.result
                }
            }

        }
    }
}
