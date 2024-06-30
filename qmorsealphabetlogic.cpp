#include "qmorsealphabetlogic.h"

QMorseAlphabetLogic::QMorseAlphabetLogic(QObject *parent) : QObject{parent}
{
    //Заполняем хэш для перевода в Азбуку Морзе
    toMorseMap['A'] = ".-";
    toMorseMap['B'] = "-...";
    toMorseMap['C'] = "-.-.";
    toMorseMap['D'] = "-..";
    toMorseMap['E'] = ".";
    toMorseMap['F'] = "..-.";
    toMorseMap['G'] = "--.";
    toMorseMap['H'] = "....";
    toMorseMap['I'] = "..";
    toMorseMap['J'] = ".---";
    toMorseMap['K'] = "-.-";
    toMorseMap['L'] = ".-..";
    toMorseMap['M'] = "--";
    toMorseMap['N'] = "-.";
    toMorseMap['O'] = "---";
    toMorseMap['P'] = ".--.";
    toMorseMap['Q'] = "--.-";
    toMorseMap['R'] = ".-.";
    toMorseMap['S'] = "...";
    toMorseMap['T'] = "-";
    toMorseMap['U'] = "..-";
    toMorseMap['V'] = "...-";
    toMorseMap['W'] = ".--";
    toMorseMap['X'] = "-..-";
    toMorseMap['Y'] = "-.--";
    toMorseMap['Z'] = "--..";
    toMorseMap['.'] = ".-.-.-";
    toMorseMap[','] = "--..--";
    toMorseMap['?'] = "..--..";
    toMorseMap['`'] = ".----.";
    toMorseMap['!'] = "-.-.--";
    toMorseMap['/'] = "-..-.";
    toMorseMap['('] = "-.--.";
    toMorseMap[')'] = "-.--.-";
    toMorseMap['&'] = ".-...";
    toMorseMap[':'] = "---...";
    toMorseMap[';'] = "-.-.-.";
    toMorseMap['='] = "-...-";
    toMorseMap['+'] = ".-.-.";
    toMorseMap['-'] = "-....-";
    toMorseMap['_'] = "..--.-";
    toMorseMap['"'] = ".-..-.";
    toMorseMap['$'] = "...-..-";
    toMorseMap['@'] = ".--.-.";

    //Заполняем хэш для перевода из Азбуки Морзе
    fromMorseMap[".-"] = 'A';
    fromMorseMap["-..."] = 'B';
    fromMorseMap["-.-."] = 'C';
    fromMorseMap["-.."] = 'D';
    fromMorseMap["."] = 'E';
    fromMorseMap["..-."] = 'F';
    fromMorseMap["--."] = 'G';
    fromMorseMap["...."] = 'H';
    fromMorseMap[".."] = 'I';
    fromMorseMap[".---"] = 'J';
    fromMorseMap["-.-"] = 'K';
    fromMorseMap[".-.."] = 'L';
    fromMorseMap["--"] = 'M';
    fromMorseMap["-."] = 'N';
    fromMorseMap["---"] = 'O';
    fromMorseMap[".--."] = 'P';
    fromMorseMap["--.-"] = 'Q';
    fromMorseMap[".-."] = 'R';
    fromMorseMap["..."] = 'S';
    fromMorseMap["-"] = 'T';
    fromMorseMap["..-"] = 'U';
    fromMorseMap["...-"] = 'V';
    fromMorseMap[".--"] = 'W';
    fromMorseMap["-..-"] = 'X';
    fromMorseMap["-.--"] = 'Y';
    fromMorseMap["--.."] = 'Z';
    fromMorseMap[".-.-.-"] = '.';
    fromMorseMap["--..--"] = ',';
    fromMorseMap["..--.."] = '?';
    fromMorseMap[".----."] = '`';
    fromMorseMap["-.-.--"] = '!';
    fromMorseMap["-..-."] = '/';
    fromMorseMap["-.--."] = '(';
    fromMorseMap["-.--.-"] = ')';
    fromMorseMap[".-..."] = '&';
    fromMorseMap["---..."] = ':';
    fromMorseMap["-.-.-."] = ';';
    fromMorseMap["-...-"] = '=';
    fromMorseMap[".-.-."] = '+';
    fromMorseMap["-....-"] = '-';
    fromMorseMap["..--.-"] = '_';
    fromMorseMap[".-..-."] = '"';
    fromMorseMap["...-..-"] = '$';
    fromMorseMap[".--.-."] = '@';
}

//Если встречается не точка и не тире, то возвращаем false, иначе true
bool QMorseAlphabetLogic::isMorseMessage(QString message)
{
    for(int i = 0; i < message.size(); i++)
        if (message.at(i) != '.' && message.at(i) != '-' && message.at(i) != ' ')
            return false;
    return true;
}

//Если нет латинских букв, то вызываем метод fromMorse, иначе toMorse
QString QMorseAlphabetLogic::qAutoTranslate(QString message)
{
    if (isMorseMessage(message))
        return fromMorse(message);
    return toMorse(message);
}

QString QMorseAlphabetLogic::fromMorse(QString message)
{
    QString result;
    QString symbol;
    // Проверяем все символы строки
    for(int i = 0; i < message.size(); i++) {
        //Если пробел, преобразуем символ в букву и записываем в результат
        if(message.at(i) == ' ') {
            result += fromMorseMap.value(symbol);
            symbol = "";
            if(i!=message.size()-1) {
                //Если за пробелом следует пробел, записываем пробел в результат
                if(message.at(i+1) == ' ') {
                    i+=1;
                    result += ' ';
                }
            }
        //Если не пробел, то записываем в символ
        } else {
            symbol += message.at(i);
        }
    }
    if(symbol != "")
        result += fromMorseMap.value(symbol);

    return result;
}

//Если символ не пробел, то берем значение из хэша и записываем в результат, иначе записываем пробел в результат
QString QMorseAlphabetLogic::toMorse(QString message)
{
    QString result;
    message = message.toUpper();
    for (int i = 0; i < message.size(); i++) {
        if(message.at(i) != ' ') {
            result += toMorseMap.value(message.at(i)) + " ";
        } else {
            result += "  ";
        }
    }
    return result;
}
