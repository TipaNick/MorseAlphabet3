#ifndef QFILEWORKDIALOG_H
#define QFILEWORKDIALOG_H

#include <QObject>
#include <QFile>
#include <QDebug>

class QFileWorkDialog : public QObject
{
    Q_OBJECT
public:
    explicit QFileWorkDialog(QObject *parent = nullptr);

signals:

public slots:
    void qSaveFile(QString path, QString outputText);
    QString qLoadFile(QString path);
};

#endif // QFILEWORKDIALOG_H
