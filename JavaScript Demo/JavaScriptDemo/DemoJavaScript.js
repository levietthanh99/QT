
var flag = true // a Boolean
var x = 1., y = 2 // number can be integers and reals
var s1 = 'abc'  // a string

function doTest() {
    //Test 1
    console.log(typeof 1.)

    console.log(1.3333333)
    console.log(1.3333333.toFixed(2))

    //Test 2
    function f(x) {var A = 3; return A * x *x }
    console.log(f(2))
}
function f(x) { return x + 1 }

var myComponent
var myRect
function createMyObject(){
    myComponent = Qt.createComponent("myRectangle.qml");
    myRect = myComponent.createObject(root, {x: 100, y: 100})
    if (myRect === null) {
            // Error Handling
            console.log("Error creating object");
        }
}
