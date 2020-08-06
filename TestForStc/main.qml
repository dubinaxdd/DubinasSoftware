import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtPositioning 5.4
import QtQuick.Layouts 1.3


Window {
    id: window
    width: 500
    height: 400
    visible: true
    title: qsTr("ТЗ для СТЦ")
    minimumHeight: 400
    //preferredHeight: 40
    minimumWidth: 420
    //preferredWidth: 40

    ColumnLayout {
        id: columnLayout1
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent

        Rectangle {
            id: rectangle2
            width: 200
            height: 82
            color: "#ffffff"
            Layout.minimumHeight: 100
            Layout.minimumWidth: 400
            Layout.preferredHeight: 100
            Layout.preferredWidth: 400
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.width: 1

            ScrollView {
                id: scrollView
                font.pointSize: 14
                anchors.fill: parent
                hoverEnabled: true

                TextArea {
                    id: textArea
                    color: "#000000"
                    text: "0"
                    anchors.fill: parent
                    enabled: true
                    antialiasing: false
                    renderType: Text.QtRendering
                    horizontalAlignment: Text.AlignLeft
                    textFormat: Text.AutoText
                    wrapMode: Text.WrapAnywhere
                    selectByMouse: true

                }
            }
        }

        RowLayout {
            id: rowLayout
            width: 472
            height: 277
            Layout.fillHeight: true
            Layout.fillWidth: true

            GridLayout {
                id: gridLayout
                width: 178
                height: 183
                Layout.fillHeight: true
                Layout.fillWidth: true
                columnSpacing: 1
                rowSpacing: 1
                rows: 4
                columns: 4

                Button {
                    id: button
                    text: qsTr("7")
                    font.pointSize: 14
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.minimumHeight: 40
                    Layout.minimumWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button1
                    text: qsTr("8")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button2
                    text: qsTr("9")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button3
                    text: qsTr("+")
                    font.pointSize: 14
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button4
                    text: qsTr("4")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button5
                    text: qsTr("5")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button6
                    text: qsTr("6")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button7
                    text: qsTr("-")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button8
                    text: qsTr("1")
                    font.pointSize: 14
                    Layout.minimumWidth: 40
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button10
                    text: qsTr("2")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button9
                    text: qsTr("3")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button11
                    text: qsTr("*")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button13
                    text: qsTr(".")
                    font.pointSize: 14
                    Layout.minimumWidth: 40
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button12
                    text: qsTr("0")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button15
                    text: qsTr("=")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    id: button14
                    text: qsTr("/")
                    font.pointSize: 14
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }


            }

            ColumnLayout {
                id: columnLayout
                width: 316
                height: 275
                Layout.fillHeight: true
                Layout.fillWidth: false

                Text {
                    id: element
                    text: qsTr("Очередь на вход: 0\nОчередь на выход: 0")
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    anchors.left: grid.right
                    font.pixelSize: 12
                }

                Label {
                    id: label
                    text: qsTr("Задержка")
                    font.pointSize: 13
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }

                SpinBox {
                    id: spinBox
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }

            }

        }
    }



























}



/*##^##
Designer {
    D{i:4;anchors_height:82;anchors_width:260;anchors_x:0;anchors_y:0}D{i:3;anchors_height:57;anchors_width:200;anchors_x:23;anchors_y:15}
D{i:2;anchors_height:82;anchors_width:200;anchors_x:28;anchors_y:20}D{i:24;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:5;anchors_height:277;anchors_width:472;anchors_x:28;anchors_y:256}D{i:1;anchors_height:100;anchors_width:100;anchors_x:309;anchors_y:25}
}
##^##*/
