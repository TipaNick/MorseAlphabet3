import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs
import Morse 1.0
import FileWork 1.0

Window {
    id: root

    width: 640
    height: 265
    visible: true
    title: qsTr("Morse translate")

    MTMorseAlphabetLogic {
        id: morse
    }

    MTFileWorkDialog {
        id: fileWorkDialog
    }

    FileDialog {
        id: saveFileDialog

        fileMode: FileDialog.SaveFile
        nameFilters: ["Text files (*.txt)"]
        onAccepted: fileWorkDialog.saveFile(selectedFile.toString().slice(8), outputText.currentText)
    }

    FileDialog {
        id: loadFileDialog

        fileMode: FileDialog.OpenFile
        nameFilters: ["Text files (*.txt)"]
        onAccepted: inputText.currentText = fileWorkDialog.loadFile(selectedFile.toString().slice(8))
    }

    Grid {
        columns: 2
        rows: 2
        rowSpacing: 15
        horizontalItemAlignment: Grid.AlignHCenter

        MTTextField {
            id: inputText

            header: "Ввод значения"
            textFieldWidth: root.width / 2
            isReadOnly: false
            onTextChanged: outputText.currentText = morse.autoTranslate(currentText)
        }

        MTTextField {
            id: outputText

            header: "Вывод значения"
            textFieldWidth: root.width / 2
            isReadOnly: true
        }

        Button {
            width: 150
            height: 50
            text: qsTr("Загрузить")

            onClicked: loadFileDialog.open()
        }

        Button {
            width: 150
            height: 50
            text: qsTr("Сохранить")

            onClicked: saveFileDialog.open()
        }

    }
}
