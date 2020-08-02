import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0


Window {
    id: window
    visible: true
    width: 300
    height: 400
    title: qsTr("Hello World")

    Grid {
        id: grid
        height: 177
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: rectangle2.bottom
        anchors.topMargin: 20
        spacing: 1
        rows: 4
        columns: 4
        transformOrigin: Item.Bottom

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
            id: button14
            width: 40
            text: qsTr("0")
        }

        Rectangle {
            id: rectangle
            x: 40
            y: 40
            width: 40
            height: 40
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle1
            x: 40
            y: 40
            width: 40
            height: 40
            color: "#ffffff"
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
                text: qsTr("Text Area")
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                renderType: Text.QtRendering
                horizontalAlignment: Text.AlignLeft
                textFormat: Text.AutoText
                wrapMode: Text.WrapAnywhere
                transformOrigin: Item.To

            }
        }
    }

    TextEdit {
        id: textEdit
        x: 41
        y: 315
        width: 223
        height: 73
        text: qsTr("asd")
        textFormat: Text.PlainText
        wrapMode: Text.WrapAnywhere
        font.pixelSize: 12
    }
}



/*##^##
Designer {
    D{i:1;anchors_height:177;anchors_x:0;anchors_y:234}D{i:20;anchors_height:82;anchors_width:260;anchors_x:0;anchors_y:0}
D{i:19;anchors_height:57;anchors_width:200;anchors_x:30;anchors_y:13}D{i:18;anchors_width:200;anchors_x:35;anchors_y:19}
}
##^##*/
