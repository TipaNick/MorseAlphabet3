#ifndef MTMORSEALPHABETLOGIC_H
#define MTMORSEALPHABETLOGIC_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QChar>
#include <QDebug>

class MTMorseAlphabetLogic : public QObject
{
    Q_OBJECT
public:
    explicit MTMorseAlphabetLogic(QObject *parent = nullptr);

public slots:
    QString autoTranslate(QString message);

private:
    QHash<QChar, QString> m_toMorseMap;
    QHash<QString, QChar> m_fromMorseMap;

private slots:
    QString fromMorse(QString message);
    QString toMorse(QString message);
    bool isMorseMessage(QString message);
};

#endif // MTMORSEALPHABETLOGIC_H
