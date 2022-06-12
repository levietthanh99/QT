import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: 600
    height: 300
    visible: true
    title: "Animator Demo"

    Item {
        id: root
        anchors.fill: parent

        property int progress: 0

        Rectangle {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop {
                    position: 0.00
                    color: "#000000"
                }
            }

            Repeater {
                anchors.fill: parent
                model: 25
                Item {
                    id: star
                    width: 10
                    height: 10

                    x: Math.random() * root.width
                    y: Math.random() * root.height

                    readonly property real maxOpacity: Math.max(0.5,Math.random())
                    property real lifeTime: 0

                    // Note: maybe this can be improved

                    NumberAnimation {
                        target: star
                        properties: "lifeTime"
                        duration: Math.random() * 5000
                        loops: Animation.Infinite
                        easing.type: Easing.InOutBounce
                        to: 1
                        from: 0
                        running: true
                    }
                    Rectangle {
                        anchors.fill: parent
                        radius: width * 0.5
                        opacity: lifeTime * maxOpacity
                        scale: 1.5 * opacity
                    }
                }
            }
        }
        Text {
            text: "Progress " + root.progress + "%"
            font.bold: true
            font.pointSize: 30
            color: "white"
            opacity: root.progress > 0 && root.progress < 100
            style: Text.Outline
            styleColor: "red"
            anchors.centerIn: parent
//            Behavior on opacity {NumberAnimation {duration: 450; easing.type: Easing.OutQuart}}
            OpacityAnimator {duration: 450; easing.type: Easing.OutQuart}
        }
        Image {
            id: rocket
            source: "qrc:/rocket.png"
            x: 20; y : 200
            smooth: true

            MouseArea {
                anchors.fill: parent
                onClicked: roketAnimation.running = true
            }

            ParallelAnimation {
                id: roketAnimation
                XAnimator {
                    target: rocket
//                    property: "x"
                    from: 20; to: 500
                    easing.type: Easing.OutQuad
                    duration: 1250
                }

                NumberAnimation {
                    target: root
                    property: "progress"
                    from: 0; to: 100
                    duration: 1250
                }

                SequentialAnimation {
                    YAnimator {
                        target: rocket
//                        property: "y"
                        from: 200; to: -100
                        easing.type: Easing.OutQuad
                        duration: 250
                    }
                    YAnimator {
                        target: rocket
//                        property: "y"
                        from: -100; to: 200
                        easing.type: Easing.OutBounce
                        duration: 1000
                    }
                }

                SequentialAnimation {
                    RotationAnimator {
                        target: rocket
//                        property: "rotation"
                        from: 0; to: 360
                        direction: RotationAnimation.Clockwise
                        duration: 1000
                    }
                    RotationAnimator {
                        target: rocket
//                        property: "rotation"
                        from: 360; to: 380
                        direction: RotationAnimation.Clockwise
                        duration: 250
                    }
                }
            }
        }
    }

}
