import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id:textBox
    width: 300
    height: 400
    Rectangle{
        anchors.fill: parent
        color: "orange"
        gradient: Gradient{
            GradientStop{ position : 0.0; color:"orange"}
            GradientStop{ position : 1.0; color:Qt.lighter("orange")}
        }

        border.color: Qt.darker(color)
        border.width: 1
    }
    ScrollView{
    id:scrollView
    anchors.fill: parent
//    contentItem.y: y

        TextArea{
            id:textArea
            anchors.fill: parent


        }
    }
    function appendText(abcd){
        textArea.append(abcd)
    }

}
