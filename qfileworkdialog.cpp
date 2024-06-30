#include "qfileworkdialog.h"

QFileWorkDialog::QFileWorkDialog(QObject *parent)
    : QObject{parent}
{

}

//Функция сохранения файла
void QFileWorkDialog::qSaveFile(QString path, QString outputText)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(outputText.toUtf8());
        file.close();
    }
}

//Функция загрузки файла
QString QFileWorkDialog::qLoadFile(QString path)
{
    QString result;
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        result = file.readAll();
        file.close();
    }
    return result;
}
