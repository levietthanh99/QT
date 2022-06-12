import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

import QtQml 2.12

Row {
    spacing: 10
    id: root
    property alias value: slider.value
    property alias maximumValue: slider.maximumValue
    property alias sliderWidth: slider.width
    property alias sliderHeight: slider.height

    signal sliderOnPressed()

    Text {
        width: 30
        id: time_left
        text: secondsToTime(slider.value)
    }

    Slider {
        id: slider
        stepSize: 1000
        width: root.width - 100
        onPressedChanged: {
            if(!pressed)
                sliderOnPressed()
        }

        Binding {
            target: slider
            property: "value"
            when: !slider.pressed
        }
    }

    Text {
        width: 30
        id: time_right
        text: secondsToTime(slider.value)
    }

    function secondsToTime(s) {
        //pading 0 in times if < 10
        function pad(n,z) {
            z = z || 2;
            return ('00' + n).slice(-z);
        }

        var ms = s % 1000;
        s = (s - ms) / 1000;
        var secs = s % 60;
        s = (s - secs) / 60;
        var mins = s % 60;
        var hrs = (s - mins) / 60;
        if(hrs > 0){
            return pad(hrs) + ':' + pad(mins) + ":" + pad(secs)
        }else{
            return pad(mins) + ":" + pad(secs)
        }
    }
}
