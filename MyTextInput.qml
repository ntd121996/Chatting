// MyTextInput.qml
import QtQuick 2.5
import QtQuick.Layouts 1.3

FocusScope{
    property alias text: input.text
    property alias echoMode: input.echoMode
    property alias input: input
    property int changeCount: 0

    id:textInput
    height:25
    width: 100
    Rectangle{
        anchors.fill: parent
        border.width: 1
        color:"lightsteelblue"
        border.color: Qt.lighter(color)
    }
    TextInput{
        id:input
        focus: true
        anchors.fill: parent
        cursorVisible: true
        anchors.topMargin: 2
        wrapMode: TextInput.Wrap
    }
    function clear(){
        input.text = ""
    }
}
