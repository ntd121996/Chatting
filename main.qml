import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.6

Window {
    visible: true
    width: 1200
    height: 600
    title: qsTr(" Multi-Screen")
    Image {
        id: background
        visible: true
        opacity: 0.8
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        clip: true
        source: "HudaAccessories.png"
    }

    StackView{
        id:stack
        anchors.fill: parent
        initialItem: loginScreen
    }
    LoginScreen{
        id:loginScreen
        visible: false
//        anchors.centerIn: stack
        anchors.horizontalCenter: stack.horizontalCenter
        anchors.top: stack.top
        anchors.topMargin: 20

        onLoginSuccess:{
            stack.push(operatingscreen)
        }
    }
    OperatingScreen{
        id:operatingscreen
        visible: false
        anchors.horizontalCenter: stack.horizontalCenter
        anchors.top: stack.top
        anchors.topMargin: 20



    }


}
