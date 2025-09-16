#include "Tokenizer.h"

QStringList Tokenizer::tokenize(const QString& expression) {
    QString normalized = normalizeExpression(expression);
    QStringList tokens;
    QString currentToken;

    for (int i = 0; i < normalized.length(); ++i) {
        QChar c = normalized[i];

        if (c.isDigit() || c == '.') {
            currentToken += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!currentToken.isEmpty()) {
                tokens.append(currentToken);
                currentToken.clear();
            }

            // Gérer le signe négatif
            if (c == '-' && (tokens.isEmpty() || isOperator(tokens.last()))) {
                currentToken = "-";
            } else {
                tokens.append(QString(c));
            }
        } else if (c == '(' || c == ')') {
            if (!currentToken.isEmpty()) {
                tokens.append(currentToken);
                currentToken.clear();
            }
            tokens.append(QString(c));
        }
    }

    if (!currentToken.isEmpty()) {
        tokens.append(currentToken);
    }

    return tokens;
}

QString Tokenizer::normalizeExpression(const QString& expression) {
    QString result = expression;
    result.remove(' ');
    result.replace("×", "*");
    result.replace("÷", "/");
    result.replace("−", "-");
    return result;
}

bool Tokenizer::isOperator(const QString& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Tokenizer::isNumber(const QString& token) {
    bool ok;
    token.toDouble(&ok);
    return ok;
}
