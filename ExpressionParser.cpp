#include "ExpressionParser.h"
#include "ArithmeticCalculator.h"
#include "ErrorHandler.h"

double ExpressionParser::parse(const QStringList& tokens) {
    if (tokens.isEmpty()) {
        throw ErrorHandler::CalculationError(
            ErrorHandler::EMPTY_EXPRESSION,
            "Aucun token à analyser"
            );
    }

    int pos = 0;
    double result = parseAdditionSubtraction(tokens, pos);

    if (pos < tokens.size()) {
        throw ErrorHandler::CalculationError(
            ErrorHandler::MALFORMED_EXPRESSION,
            "Expression mal formée"
            );
    }

    return result;
}

double ExpressionParser::parseAdditionSubtraction(const QStringList& tokens, int& pos) {
    double left = parseMultiplicationDivision(tokens, pos);

    while (pos < tokens.size()) {
        QString op = tokens[pos];
        if (op == "+") {
            pos++;
            double right = parseMultiplicationDivision(tokens, pos);
            left = ArithmeticCalculator::add(left, right);
        } else if (op == "-") {
            pos++;
            double right = parseMultiplicationDivision(tokens, pos);
            left = ArithmeticCalculator::subtract(left, right);
        } else {
            break;
        }
    }

    return left;
}

double ExpressionParser::parseMultiplicationDivision(const QStringList& tokens, int& pos) {
    double left = parseFactor(tokens, pos);

    while (pos < tokens.size()) {
        QString op = tokens[pos];
        if (op == "*") {
            pos++;
            double right = parseFactor(tokens, pos);
            left = ArithmeticCalculator::multiply(left, right);
        } else if (op == "/") {
            pos++;
            double right = parseFactor(tokens, pos);
            left = ArithmeticCalculator::divide(left, right);
        } else {
            break;
        }
    }

    return left;
}

double ExpressionParser::parseFactor(const QStringList& tokens, int& pos) {
    if (pos >= tokens.size()) {
        throw ErrorHandler::CalculationError(
            ErrorHandler::MALFORMED_EXPRESSION,
            "Facteur attendu"
            );
    }

    QString token = tokens[pos];

    // Nombre négatif
    if (token.startsWith('-') && token.length() > 1) {
        pos++;
        return parseNumber(token);
    }

    // Parenthèses
    if (token == "(") {
        return parseParentheses(tokens, pos);
    }

    // Nombre positif
    pos++;
    return parseNumber(token);
}

double ExpressionParser::parseParentheses(const QStringList& tokens, int& pos) {
    pos++; // Consommer '('
    double result = parseAdditionSubtraction(tokens, pos);

    if (pos >= tokens.size() || tokens[pos] != ")") {
        throw ErrorHandler::CalculationError(
            ErrorHandler::MISSING_PARENTHESIS,
            "Parenthèse fermante manquante"
            );
    }

    pos++; // Consommer ')'
    return result;
}

double ExpressionParser::parseNumber(const QString& token) {
    bool ok;
    double value = token.toDouble(&ok);

    if (!ok) {
        throw ErrorHandler::CalculationError(
            ErrorHandler::INVALID_NUMBER,
            "Nombre invalide: " + token
            );
    }

    return value;
}
