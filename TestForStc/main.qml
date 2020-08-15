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
    minimumWidth: 420

    Connections{
        target: _Form
        onSendTextToView: {

            textArea.text = _Form.mainText()

            if (textArea.contentHeight > rectangle2.height)
                flickable.contentY = textArea.contentHeight - rectangle2.height + 10
        }

    }

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
            Flickable {
                id: flickable
                flickableDirection: Flickable.VerticalFlick
                anchors.fill: parent

                TextArea.flickable: TextArea {
                    id: textArea
                    x: 5
                    y: 5
                    color: "#000000"
                    text: "0"
                    font.pointSize: 14
                    anchors.rightMargin: 5
                    anchors.leftMargin: 5
                    anchors.bottomMargin: 5
                    anchors.topMargin: 5
                    anchors.fill: parent
                    verticalAlignment: Text.AlignTop
                    padding: 0
                    leftPadding: 0
                    rightPadding: 0
                    bottomPadding: 0
                    topPadding: 0
                    enabled: true
                    antialiasing: false
                    renderType: Text.QtRendering
                    horizontalAlignment: Text.AlignLeft
                    textFormat: Text.AutoText
                    wrapMode: Text.WrapAnywhere
                    selectByMouse: true
                    readOnly: true
                }

                ScrollBar.vertical: ScrollBar{
                    id: scrollBar
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

                                onClicked:
                                {
                                    _Form.buttonC_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button7_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button8_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button4_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button5_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button1_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button2_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.buttonDot_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button0_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.buttonBackspace_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.buttonPlus_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button9_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.buttonMinus_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button6_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.buttonMultiplication_onClick();
                                }
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

                                onClicked:
                                {
                                    _Form.button3_onClick();
                                }

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

                                onClicked:
                                {
                                    _Form.buttonDivision_onClick();
                                }
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

                            onClicked:
                            {
                                _Form.buttonEqualy_onClick();
                            }
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
                    //anchors.left: grid.right
                    font.pixelSize: 12
                }

                Label {
                    id: label_Delay
                    text: qsTr("Задержка")
                    font.pointSize: 13
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }

                RowLayout {
                    id: rowLayout2
                    width: 161
                    height: 100
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    spacing: 0

                    Button {
                        id: button_DelayMinus
                        text: qsTr("-")
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

                    Rectangle {
                        id: rectangle
                        width: 200
                        height: 200
                        color: "#ffffff"
                        border.width: 1
                        Layout.minimumHeight: 40
                        Layout.minimumWidth: 60
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 60
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        TextInput {
                            id: textInput_Delay
                            text: qsTr("0")
                            anchors.rightMargin: 1
                            anchors.leftMargin: 1
                            anchors.bottomMargin: 1
                            anchors.topMargin: 1
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                            font.pixelSize: 12
                            validator: RegExpValidator { regExp: /[0-9]{3}/ }

                        }
                    }

                    Button {
                        id: button_DelayPlus
                        width: 33
                        height: 40
                        text: qsTr("+")
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

                }
            }
        }

    }
}



/*##^##
Designer {
    D{i:1;anchors_height:100;anchors_width:100;anchors_x:175;anchors_y:22}D{i:4;anchors_height:23;anchors_width:480;anchors_x:0;anchors_y:0}
D{i:3;anchors_height:57;anchors_width:200;anchors_x:23;anchors_y:15}D{i:18;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:17;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}D{i:20;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:19;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}D{i:31;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:30;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}D{i:33;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}
D{i:32;anchors_height:104;anchors_width:180;anchors_x:200;anchors_y:134}D{i:57;anchors_height:20;anchors_width:80;anchors_x:"-166";anchors_y:93}
D{i:56;anchors_height:20;anchors_width:80;anchors_x:"-166";anchors_y:93}D{i:58;anchors_height:20;anchors_width:80;anchors_x:"-166";anchors_y:93}
D{i:55;anchors_height:20;anchors_width:80;anchors_x:"-166";anchors_y:93}D{i:2;anchors_height:82;anchors_width:200;anchors_x:28;anchors_y:20}
}
##^##*/
