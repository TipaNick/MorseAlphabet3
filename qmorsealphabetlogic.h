#ifndef QMORSEALPHABETLOGIC_H
#define QMORSEALPHABETLOGIC_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QChar>
#include <QDebug>

class QMorseAlphabetLogic : public QObject
{
    Q_OBJECT
public:
    explicit QMorseAlphabetLogic(QObject *parent = nullptr);
private:
    QHash<QChar, QString> toMorseMap;
    QHash<QString, QChar> fromMorseMap;

signals:

public slots:
    QString qAutoTranslate(QString message);

private slots:
    QString fromMorse(QString message);
    QString toMorse(QString message);
    bool isMorseMessage(QString message);
};

#endif // QMORSEALPHABETLOGIC_H
