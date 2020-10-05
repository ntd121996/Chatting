import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Item {
    id:operating
    width: 800
    height: 500
    property bool enable: true
//    property alias connected: backend.connection
    Rectangle{
        id:rect
        anchors.fill:  parent
        color:"lightblue"
        radius: 5
        border.color: Qt.darker(color)
        border.width: 1
    }
    ColumnLayout{
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15
        Row{
            Layout.fillWidth: parent
            height: 50
            spacing: 100
            MyButton{
                id:start
                text:"Start"
                anchors.top: parent.top
                anchors.topMargin: 5
                enabled: operating.enable
                onButtonClicked: {
                    operating.enable = false
                    textBox.appendText(backend.onStartClicked())
                }
            }
            MyButton{
                id:close
                text:"Close"
                anchors.top: parent.top
                anchors.topMargin: 5
                enabled: !operating.enable
                onButtonClicked: {
                    operating.enable = true
                    textBox.appendText(backend.onCloseClicked())
                }
            }
        }

        TextBox{
            id:textBox

        }
        Row{
            Layout.fillWidth: parent
            spacing: 50
            MyTextInput{
                id: textSend
                KeyNavigation.tab:send
            }

            MyButton{
                id:send
                text:"Send"
                enabled: close.enabled
                onButtonClicked: {
                    backend.onSendClicked(textSend.text)
                    textSend.clear()
                }
            }

        }


    }
    Connections{
        target: backend
        onHaveNewConnection:{
            textBox.appendText(msg)
        }
        onHaveMessage:{
            textBox.appendText(msg)
        }
        onCloseConnection:{
            textBox.appendText(msg)
        }
        onSendSuccess:{
            textBox.appendText("Send Success")
        }


    }

}
