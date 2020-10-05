import QtQuick 2.3
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Item {
    id:login
    width: 350
    height: 300

    signal loginSuccess()
    Rectangle{
        id:rect
        anchors.fill: parent
        border.color: "slategray"
        border.width: 2
        gradient: Gradient{
            GradientStop{ position:0.0; color:"lightsteelblue"}
            GradientStop{ position:1.0; color:"slategray"}
        }
        GroupBox {
            title: ""
            anchors.fill: parent
            width: parent.width
//            height: parent.height/3
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.topMargin:1
            ColumnLayout{
                anchors.fill: parent
                spacing: 20
                RowLayout{
                    Text {
                        id: user
                        text: qsTr("Ten Dang Nhap:")
                    }
                    MyTextInput{
                        id:idInput
                        text:"duynt"
                        KeyNavigation.tab:passwordInput
                    }
                }
                RowLayout{
                    spacing: 45
                    Text {
                        id: password
                        text: qsTr("Mat Khau:")
                    }
                    MyTextInput{
                        id:passwordInput
                        text:"1"
                        KeyNavigation.tab:idInput
                        echoMode: TextInput.Password
                    }
                }
                MyButton{
                    id:loginButton
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                    text: "Log in"
                    onButtonClicked: {
                        if( validate (idInput.text, passwordInput.text))
                        {
                            loginSuccess()
                        }
                    }
                }
            }
        }
    }

    Keys.onEnterPressed: {
        loginButton.buttonClicked()

    }
    function validate (id, pass){
        if( id !== "duynt" || pass !== "1"){
            return false
        }
        else{
            return true
        }

    }


}



//        anchors.fill: parent
//        ColumnLayout{
//            anchors.fill: parent
//            Text {
//                id: id
//                width: 10
//                height: 15
//                anchors.centerIn: parent
////                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//                Layout.margins: -20
////                elide: Text.ElideMiddle
//                text: qsTr("Ten Dang Nhap:")
//            }
//            TextInput{
//                id:idinput
//                width: 15
//                height: 15
////                text:"Textinput"
//                wrapMode: Text.NoWrap
//                Layout.alignment: Qt.AlignHCenter
////                cursorVisible:true
//                Keys.onEnterPressed: {
//                    console.log(idinput.text)
//                    console.log(passinput.text)
//                }

////                activeFocusOnPress:true

//            }
//            Text {
//                id: pass
//                text: qsTr("Mat Khau:")
//            }
//            TextInput
//            {
//                id:passinput
////                text:"Text"

////                cursorVisible:true
//                echoMode:TextInput.Password
//                horizontalAlignment:TextInput.AlignHCenter
//                activeFocusOnPress:true
//            }

//            MyButton{
//                id:loginButton
//                text:"Login"
//                onButtonClicked:
//                {
//                    console.log(idinput.text)
//                    console.log(passinput.text)
////                    loginSuccess()
//                }


//            }
//                        }
//    }
//}
