import QtQuick 2.7
import QtQuick.Window 2.2

Rectangle
{
    id:page
    width: 500
    height: 200
    color: "gray"

    Text
    {
        id: hello
        text: "Hello,World!"
        font.pointSize:24
        font.bold:true
        y:30
        anchors.horizontalCenter: page.horizontalCenter
    }

}
