import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    // Muốn hiển thị 1 list view ta cần 1 model
    //  model chứa data để hiển thị, và view cách để hiển thị data
    // Trong list view thì nó chỉ tạo 1 số lượng item đủ để hiển thị ra view container
    //và 1 lượng item được tạo và lưu trong buffer, khi vuốt kéo view thì nó sẽ tạo mới các view mới và hủy đi các view quá cũ


    function itemName(idx){
        switch (idx){
        case 1: return "Nguyen Van A"
        case 2: return "Le Van B"
        default: return "No Name"
        }
    }

    property var nameArr: ["Nguyen Van A", "Le Van B", "Le Thi C"]

    // list view with model là 1 số integer
    ListView {
        anchors.fill: parent

        model: nameArr // cũng ok
        //model: 100 // ở đây model là số ( nghĩa là list này có 100 phần tử)
        delegate: Rectangle{
            width: 100
            height: 50
            color: index % 2 === 0 ? "gray": "white"
            Text {
                id: name
                anchors.centerIn: parent
                text: modelData // ok nếu model: nameArr
                //text: itemName(index)
            }
            Component.onCompleted: {
                console.log("Create: " + index)
            }
            Component.onDestruction: {
                console.log("Destroy: " + index)
            }
        }
        // orientation default ListView.Vertical
//        orientation: ListView.Horizontal
    }



    // list view with ListModel
    ListModel {
        id: listModel

        ListElement {
            masosv: "12345"
            fullname: "le viet thanh"
            tuoi: "24"
        }

        ListElement {
            masosv: "12321"
            fullname: "le thi thuy"
            tuoi: "29"
        }

        ListElement {
            masosv: "11111"
            fullname: "tran minh nguyet"
            tuoi: "25"
        }
    }

    ListView {
        anchors.fill: parent
        model: listModel
        delegate: Rectangle{
            x : 150
            width: 200
            height: 50
            color: index % 2 === 0 ? "gray": "white"
            Text {
                id: txt
                anchors.centerIn: parent
                text: masosv + ", " + fullname + ", " + tuoi
            }
            Component.onCompleted: {
                console.log("Create: " + index)
            }
            Component.onDestruction: {
                console.log("Destroy: " + index)
            }
        }
        // orientation default ListView.Vertical
//        orientation: ListView.Horizontal
    }



}
