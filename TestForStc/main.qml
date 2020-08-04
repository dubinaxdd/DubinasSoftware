import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtPositioning 5.4
import QtQuick.Layouts 1.3


Window {
    id: window
    visible: true
    title: qsTr("ТЗ для СТЦ")

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
            x: 30
            y: 13
            width: 200
            height: 57
            anchors.verticalCenter: parent.verticalCenter
            anchors.top: parent.top
            hoverEnabled: true

            TextArea {
                id: textArea
                x: 0
                y: 0
                width: 260
                height: 82
                color: "#000000"
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

    GridLayout {
        id: gridLayout
        x: 39
        y: 212
        width: 178
        height: 183
        columnSpacing: 1
        rowSpacing: 1
        rows: 4
        columns: 4

        Button {
            id: button
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button1
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button2
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button3
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button4
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button5
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button6
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button7
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button8
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button10
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button9
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button11
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button13
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button12
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button15
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button14
            text: qsTr("Button")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }


    }

    Text {
        id: element
        x: 214
        y: 158
        width: 180
        height: 104
        text: qsTr("Очередь на вход: 0\nОчередь на выход: 0")
        Layout.fillHeight: true
        Layout.fillWidth: true
        anchors.left: grid.right
        font.pixelSize: 12

        ColumnLayout {
            id: columnLayout
            x: 35
            y: 104
            width: 100
            height: 100
        }
    }

    Label {
        id: label
        x: 225
        y: 196
        width: 190
        height: 20
        text: qsTr("Label")
        Layout.fillHeight: true
        Layout.fillWidth: true
    }

    GridLayout {
        id: gridLayout1
        x: 255
        y: 355
        width: 100
        height: 100
    }




















}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3;anchors_height:82;anchors_width:260;anchors_x:0;anchors_y:0}
D{i:2;anchors_height:57;anchors_width:200;anchors_x:30;anchors_y:13}D{i:1;anchors_width:200;anchors_x:35;anchors_y:19}
D{i:21;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
}
##^##*/
