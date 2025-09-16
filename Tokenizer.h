#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QStringList>

/**
 * Tokenizer - Responsable de découper l'expression en tokens
 * Convertit "2+3*4" en ["2", "+", "3", "*", "4"]
 */
class Tokenizer {
public:
    static QStringList tokenize(const QString& expression);
    static QString normalizeExpression(const QString& expression);
    static bool isOperator(const QString& token);
    static bool isNumber(const QString& token);
};


#endif // TOKENIZER_H
