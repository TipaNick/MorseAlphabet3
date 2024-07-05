import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs
import Morse 1.0
import FileWork 1.0

Column {
    id: root

    property string header: ""
    property int textFieldWidth: 0
    property bool isReadOnly: value
    property alias currentText: textEdit.text

    signal textChanged

    Text {
        text: qsTr(root.header)
        font { pointSize: 18; bold: true }
    }

    Rectangle {
        border.color: "#000000"
        border.width: 1
        width: root.textFieldWidth
        height: 150

        TextEdit {
            id: textEdit

            width: root.textFieldWidth
            height: 150
            font.pointSize: 16
            wrapMode: TextEdit.Wrap
            selectByMouse: true
            readOnly: root.isReadOnly

            onTextChanged: root.textChanged()
        }
    }
}
