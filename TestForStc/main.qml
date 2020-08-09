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
    title: qsTr("Калькулятор")
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
            spacing: 5
            Layout.fillHeight: true
            Layout.fillWidth: true



            RowLayout {
                id: rowLayout1
                width: 100
                height: 100
                spacing: 1

                GridLayout {
                    id: gridLayout
                    width: 178
                    height: 183
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    columnSpacing: 1
                    rowSpacing: 1
                    rows: 2
                    columns: 1

                    GridLayout {
                        id: gridLayout4
                        width: 100
                        height: 100
                        columnSpacing: 1
                        rowSpacing: 1
                        rows: 4
                        columns: 2

                        Button {
                            id: button_C
                            text: qsTr("C")
                            autoRepeat: false
                            flat: false
                            highlighted: false
                            autoExclusive: false
                            font.pointSize: 14
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }


                        }

                        Button {
                            id: button_CE
                            text: qsTr("CE")
                            font.pointSize: 14
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_7
                            text: qsTr("7")
                            hoverEnabled: true
                            font.pointSize: 14
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.minimumHeight: 40
                            Layout.minimumWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_8
                            text: qsTr("8")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_4
                            text: qsTr("4")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_5
                            text: qsTr("5")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_1
                            text: qsTr("1")
                            font.pointSize: 14
                            Layout.minimumWidth: 40
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_2
                            text: qsTr("2")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }
                    }

                    GridLayout {
                        id: gridLayout3
                        width: 100
                        height: 100
                        columnSpacing: 1
                        rowSpacing: 1

                        Button {
                            id: button_Dot
                            text: qsTr(".")
                            font.pointSize: 14
                            Layout.minimumWidth: 40
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_0
                            width: 75
                            height: 37
                            text: qsTr("0")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }
                    }
                }

                GridLayout {
                    id: gridLayout2
                    width: 100
                    height: 100
                    columnSpacing: 1
                    rowSpacing: 1
                    rows: 2
                    columns: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    GridLayout {
                        id: gridLayout1
                        width: 100
                        height: 100
                        Layout.minimumHeight: 0
                        Layout.minimumWidth: 0
                        Layout.preferredHeight: -1
                        Layout.preferredWidth: -1
                        columnSpacing: 1
                        rowSpacing: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        rows: 4
                        columns: 2

                        Button {
                            id: button_Backspace
                            text: qsTr("←")
                            font.pointSize: 14
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_Plus
                            text: qsTr("+")
                            font.pointSize: 14
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_9
                            text: qsTr("9")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_Minus
                            text: qsTr("-")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_6
                            text: qsTr("6")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_Multiplication
                            text: qsTr("*")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_3
                            text: qsTr("3")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }

                        Button {
                            id: button_Division
                            text: qsTr("/")
                            font.pointSize: 14
                            Layout.minimumHeight: 40
                            Layout.preferredHeight: 40
                            Layout.minimumWidth: 40
                            Layout.preferredWidth: 40
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            MouseArea {
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {parent.highlighted = true}
                                onExited: {parent.highlighted = false}
                                onPressed:{parent.scale = 0.9}
                                onReleased:{parent.scale = 1}
                            }
                        }
                    }

                    Button {
                        id: button_Equaly
                        width: 88
                        height: 40
                        text: qsTr("=")
                        font.pointSize: 14
                        Layout.minimumHeight: 40
                        Layout.preferredHeight: 40
                        Layout.minimumWidth: 81
                        Layout.preferredWidth: 81
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        MouseArea {
                            hoverEnabled: true
                            anchors.fill: parent
                            onEntered: {parent.highlighted = true}
                            onExited: {parent.highlighted = false}
                            onPressed:{parent.scale = 0.9}
                            onReleased:{parent.scale = 1}
                        }
                    }

                }
            }

            ColumnLayout {
                id: columnLayout
                width: 316
                height: 275
                Layout.fillHeight: true
                Layout.fillWidth: false

                Text {
                    id: element_Queue
                    text: qsTr("Очередь на вход: 0\nОчередь на выход: 0")
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    anchors.left: grid.right
                    font.pixelSize: 12
                }

                Label {
                    id: label_Delay
                    text: qsTr("Задержка")
                    font.pointSize: 13
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }

                SpinBox {
                    id: spinBox_Delay
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
D{i:2;anchors_height:82;anchors_width:200;anchors_x:28;anchors_y:20}D{i:19;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:32;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}D{i:5;anchors_height:277;anchors_width:472;anchors_x:28;anchors_y:256}
D{i:1;anchors_height:100;anchors_width:100;anchors_x:175;anchors_y:22}
}
##^##*/
