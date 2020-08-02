import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0


Window {
    id: window
    visible: true
    width: 400
    height: 320
    title: qsTr("ТЗ для СТЦ")

    Grid {
        id: grid
        width: 164
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 9
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: rectangle2.bottom
        anchors.topMargin: 28
        spacing: 1
        rows: 4
        columns: 4
        transformOrigin: Item.Center

        Button {
            id: button
            width: 40
            text: qsTr("7")
        }

        Button {
            id: button1
            width: 40
            text: qsTr("8")
        }

        Button {
            id: button2
            width: 40
            text: qsTr("9")
        }

        Button {
            id: button3
            width: 40
            text: qsTr("+")
        }

        Button {
            id: button4
            width: 40
            text: qsTr("4")
        }

        Button {
            id: button5
            width: 40
            text: qsTr("5")
        }

        Button {
            id: button6
            width: 40
            text: qsTr("6")
        }

        Button {
            id: button7
            width: 40
            text: qsTr("-")
        }

        Button {
            id: button8
            width: 40
            text: qsTr("1")
        }

        Button {
            id: button9
            width: 40
            text: qsTr("2")
        }

        Button {
            id: button10
            width: 40
            text: qsTr("3")
        }

        Button {
            id: button11
            width: 40
            text: qsTr("*")
        }



        Button {
            id: button17
            width: 40
            text: qsTr(".")
        }

        Button {
            id: button14
            width: 40
            text: qsTr("0")
        }


        Button {
            id: button16
            width: 40
            text: qsTr("=")
        }

        Button {
            id: button15
            width: 40
            text: qsTr("/")
        }


    }

    Rectangle {
        id: rectangle2
        height: 82
        color: "#ffffff"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 24
        border.width: 1

        ScrollView {
            id: scrollView
            hoverEnabled: true
            anchors.fill: parent

            TextArea {
                id: textArea
                x: 0
                y: 0
                width: 260
                height: 82
                color: "#000000"
                text: qsTr("0")
                enabled: true
                antialiasing: false
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                renderType: Text.QtRendering
                horizontalAlignment: Text.AlignLeft
                textFormat: Text.AutoText
                wrapMode: Text.WrapAnywhere
                selectByMouse: true

            }
        }
    }

    Label {
        id: label
        x: 200
        text: qsTr("Задержка")
        anchors.right: parent.right
        anchors.rightMargin: 151
        anchors.top: element.bottom
        anchors.topMargin: 6
    }

    SpinBox {
        id: spinBox
        height: 25
        anchors.left: grid.right
        anchors.leftMargin: 16
        anchors.right: parent.right
        anchors.rightMargin: 37
        anchors.top: label.bottom
        anchors.topMargin: 12
    }

    Text {
        id: element
        x: 200
        width: 180
        height: 104
        text: qsTr("Очередь на вход: 0\nОчередь на выход: 0")
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: rectangle2.bottom
        anchors.topMargin: 28
        font.pixelSize: 12
    }
}



/*##^##
Designer {
    D{i:2;anchors_width:40}D{i:1;anchors_height:177;anchors_x:0;anchors_y:234}D{i:20;anchors_height:82;anchors_width:260;anchors_x:0;anchors_y:0}
D{i:19;anchors_height:57;anchors_width:200;anchors_x:30;anchors_y:13}D{i:18;anchors_width:200;anchors_x:35;anchors_y:19}
D{i:21;anchors_y:244}D{i:22;anchors_height:25;anchors_width:163;anchors_x:200;anchors_y:269}
D{i:23;anchors_y:134}
}
##^##*/
