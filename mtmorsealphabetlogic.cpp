#include "mtmorsealphabetlogic.h"

MTMorseAlphabetLogic::MTMorseAlphabetLogic(QObject *parent) : QObject{parent}
{
    //Заполняем хэш для перевода в Азбуку Морзе
    m_toMorseMap['A'] = ".-";
    m_toMorseMap['B'] = "-...";
    m_toMorseMap['C'] = "-.-.";
    m_toMorseMap['D'] = "-..";
    m_toMorseMap['E'] = ".";
    m_toMorseMap['F'] = "..-.";
    m_toMorseMap['G'] = "--.";
    m_toMorseMap['H'] = "....";
    m_toMorseMap['I'] = "..";
    m_toMorseMap['J'] = ".---";
    m_toMorseMap['K'] = "-.-";
    m_toMorseMap['L'] = ".-..";
    m_toMorseMap['M'] = "--";
    m_toMorseMap['N'] = "-.";
    m_toMorseMap['O'] = "---";
    m_toMorseMap['P'] = ".--.";
    m_toMorseMap['Q'] = "--.-";
    m_toMorseMap['R'] = ".-.";
    m_toMorseMap['S'] = "...";
    m_toMorseMap['T'] = "-";
    m_toMorseMap['U'] = "..-";
    m_toMorseMap['V'] = "...-";
    m_toMorseMap['W'] = ".--";
    m_toMorseMap['X'] = "-..-";
    m_toMorseMap['Y'] = "-.--";
    m_toMorseMap['Z'] = "--..";
    m_toMorseMap['.'] = ".-.-.-";
    m_toMorseMap[','] = "--..--";
    m_toMorseMap['?'] = "..--..";
    m_toMorseMap['`'] = ".----.";
    m_toMorseMap['!'] = "-.-.--";
    m_toMorseMap['/'] = "-..-.";
    m_toMorseMap['('] = "-.--.";
    m_toMorseMap[')'] = "-.--.-";
    m_toMorseMap['&'] = ".-...";
    m_toMorseMap[':'] = "---...";
    m_toMorseMap[';'] = "-.-.-.";
    m_toMorseMap['='] = "-...-";
    m_toMorseMap['+'] = ".-.-.";
    m_toMorseMap['-'] = "-....-";
    m_toMorseMap['_'] = "..--.-";
    m_toMorseMap['"'] = ".-..-.";
    m_toMorseMap['$'] = "...-..-";
    m_toMorseMap['@'] = ".--.-.";

    //Заполняем хэш для перевода из Азбуки Морзе
    m_fromMorseMap[".-"] = 'A';
    m_fromMorseMap["-..."] = 'B';
    m_fromMorseMap["-.-."] = 'C';
    m_fromMorseMap["-.."] = 'D';
    m_fromMorseMap["."] = 'E';
    m_fromMorseMap["..-."] = 'F';
    m_fromMorseMap["--."] = 'G';
    m_fromMorseMap["...."] = 'H';
    m_fromMorseMap[".."] = 'I';
    m_fromMorseMap[".---"] = 'J';
    m_fromMorseMap["-.-"] = 'K';
    m_fromMorseMap[".-.."] = 'L';
    m_fromMorseMap["--"] = 'M';
    m_fromMorseMap["-."] = 'N';
    m_fromMorseMap["---"] = 'O';
    m_fromMorseMap[".--."] = 'P';
    m_fromMorseMap["--.-"] = 'Q';
    m_fromMorseMap[".-."] = 'R';
    m_fromMorseMap["..."] = 'S';
    m_fromMorseMap["-"] = 'T';
    m_fromMorseMap["..-"] = 'U';
    m_fromMorseMap["...-"] = 'V';
    m_fromMorseMap[".--"] = 'W';
    m_fromMorseMap["-..-"] = 'X';
    m_fromMorseMap["-.--"] = 'Y';
    m_fromMorseMap["--.."] = 'Z';
    m_fromMorseMap[".-.-.-"] = '.';
    m_fromMorseMap["--..--"] = ',';
    m_fromMorseMap["..--.."] = '?';
    m_fromMorseMap[".----."] = '`';
    m_fromMorseMap["-.-.--"] = '!';
    m_fromMorseMap["-..-."] = '/';
    m_fromMorseMap["-.--."] = '(';
    m_fromMorseMap["-.--.-"] = ')';
    m_fromMorseMap[".-..."] = '&';
    m_fromMorseMap["---..."] = ':';
    m_fromMorseMap["-.-.-."] = ';';
    m_fromMorseMap["-...-"] = '=';
    m_fromMorseMap[".-.-."] = '+';
    m_fromMorseMap["-....-"] = '-';
    m_fromMorseMap["..--.-"] = '_';
    m_fromMorseMap[".-..-."] = '"';
    m_fromMorseMap["...-..-"] = '$';
    m_fromMorseMap[".--.-."] = '@';
}

//Если встречается не точка и не тире, то возвращаем false, иначе true
bool MTMorseAlphabetLogic::isMorseMessage(QString message)
{
    for (int i = 0; i < message.size(); i++)
        if (message.at(i) != '.' && message.at(i) != '-' && message.at(i) != ' ')
            return false;
    return true;
}

//Если нет латинских букв, то вызываем метод fromMorse, иначе toMorse
QString MTMorseAlphabetLogic::autoTranslate(QString message)
{
    if (isMorseMessage(message))
        return fromMorse(message);
    return toMorse(message);
}

QString MTMorseAlphabetLogic::fromMorse(QString message)
{
    QString result = "";
    QString symbol = "";
    // Проверяем все символы строки
    for (int i = 0; i < message.size(); i++) {
        //Если пробел, преобразуем символ в букву и записываем в результат
        if (message.at(i) == ' ') {
            result += m_fromMorseMap.value(symbol);
            symbol = "";
            if (i != message.size() - 1) {
                //Если за пробелом следует пробел, записываем пробел в результат
                if (message.at(i + 1) == ' ') {
                    i += 1;
                    result += ' ';
                }
            }
        //Если не пробел, то записываем в символ
        } else {
            symbol += message.at(i);
        }
    }
    if (symbol != "")
        result += m_fromMorseMap.value(symbol);
    return result;
}

//Если символ не пробел, то берем значение из хэша и записываем в результат, иначе записываем пробел в результат
QString MTMorseAlphabetLogic::toMorse(QString message)
{
    QString result = "";
    message = message.toUpper();
    for (int i = 0; i < message.size(); i++) {
        if (message.at(i) != ' ') {
            result += m_toMorseMap.value(message.at(i)) + " ";
        } else {
            result += " ";
        }
    }
    return result;
}
