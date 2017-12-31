import QtQuick 2.6
import QtQuick.Window 2.2

Window
{
    visible: true
    width: 480
    height: 480
    color: "red"
    title: qsTr("Hello World")

    Text
    {
        anchors.centerIn: parent
        text: "Hello,World!"
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: parent.color = "blue"
    }
}


