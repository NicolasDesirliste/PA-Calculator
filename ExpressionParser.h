#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <QStringList>

/**
 * ExpressionParser - Responsable de l'analyse syntaxique
 * Parser récursif qui respecte les priorités mathématiques
 */
class ExpressionParser {
public:
    static double parse(const QStringList& tokens);

private:
    static double parseAdditionSubtraction(const QStringList& tokens, int& pos);
    static double parseMultiplicationDivision(const QStringList& tokens, int& pos);
    static double parseFactor(const QStringList& tokens, int& pos);
    static double parseParentheses(const QStringList& tokens, int& pos);
    static double parseNumber(const QString& token);
};

#endif // EXPRESSIONPARSER_H
