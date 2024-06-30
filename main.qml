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

    QMorseAlphabetLogic {
        id: morse
    }

    QFileWorkDialog {
        id: filework
    }

    FileDialog {
        id: saveFileDialog
        fileMode: FileDialog.SaveFile
        nameFilters: ["Text files (*.txt)"]
        onAccepted: filework.qSaveFile(selectedFile.toString().slice(8), outputText.text)
    }

    FileDialog {
        id: loadFileDialog
        fileMode: FileDialog.OpenFile
        nameFilters: ["Text files (*.txt)"]
        onAccepted: inputText.text = filework.qLoadFile(selectedFile.toString().slice(8))
    }

    Grid {
        columns: 2
        rows: 2
        rowSpacing: 15
        horizontalItemAlignment: Grid.AlignHCenter

        Column {
            Text {
                text: qsTr("Ввод значения")
                font { pointSize: 18; bold: true }
            }
            Rectangle {
                border.color: "#000000"
                border.width: 1
                width: root.width/2
                height: 150

                TextEdit {
                    id: inputText
                    width: root.width/2
                    height: 150
                    font.pointSize: 16
                    wrapMode: TextEdit.Wrap
                    selectByMouse: true
                    onTextChanged: outputText.text = morse.qAutoTranslate(inputText.text)
                }
            }
        }

        Column {
            Text {
                text: qsTr("Вывод значения")
                font { pointSize: 18; bold: true }
            }
            Rectangle {
                border.color: "#000000"
                border.width: 1
                width: root.width/2
                height: 150

                TextEdit {
                    id: outputText
                    width: root.width/2
                    height: 150
                    font.pointSize: 16
                    wrapMode: TextEdit.Wrap
                }
            }
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
