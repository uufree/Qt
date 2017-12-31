import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 39
        anchors.bottomMargin: 253
        anchors.leftMargin: -39
        anchors.topMargin: -253
        anchors.fill: parent

        BorderImage {
            id: borderImage
            x: 77
            y: 90
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
        }
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
