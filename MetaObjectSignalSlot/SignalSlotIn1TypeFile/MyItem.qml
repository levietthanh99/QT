import QtQuick 2.0

Rectangle {
    width: 100
    height: 100
    color: "red"
    signal clChange()

    onClChange: {
        console.log("myItem: Hello")
    }

    function myFunc(){
        clChange();
    }
}

