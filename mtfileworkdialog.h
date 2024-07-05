#ifndef MTFILEWORKDIALOG_H
#define MTFILEWORKDIALOG_H

#include <QObject>
#include <QFile>
#include <QDebug>

class MTFileWorkDialog : public QObject
{
    Q_OBJECT
public:
    explicit MTFileWorkDialog(QObject *parent = nullptr);

signals:

public slots:
    void saveFile(QString path, QString outputText);
    QString loadFile(QString path);
};

#endif // MTFILEWORKDIALOG_H
