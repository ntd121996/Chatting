// MyButton.qml
import QtQuick 2.0
Item {
    id:button
    property alias text: label.text
    signal buttonClicked()
    width: 120
    height: 30
    Rectangle
    {
        id:rect
        border.color:"gray"
        border.width: 1
        anchors.fill: parent
        radius: 15
        gradient: Gradient{
            GradientStop{ position: 0.0; color: "lightsteelblue" }
            GradientStop{ position: 1.0; color: "lightgray" }
        }
    }
    Text {
        id: label
        text: text
        anchors.centerIn: parent
    }
    MouseArea{
        anchors.fill: parent
        onClicked:button.buttonClicked()

    }
}
