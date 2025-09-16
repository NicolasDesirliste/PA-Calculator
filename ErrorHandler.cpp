#include "ErrorHandler.h"
#include <QDebug>

// Constructeur de l'exception personnalisée
ErrorHandler::CalculationError::CalculationError(ErrorType type, const QString& message)
    : std::runtime_error(message.toStdString()), errorType(type) {
}

ErrorHandler::ErrorType ErrorHandler::CalculationError::getType() const {
    return errorType;
}

void ErrorHandler::validateDivision(double divisor) {
    if (divisor == 0.0) {
        throw CalculationError(DIVISION_BY_ZERO, "Division par zéro");
    }
}

void ErrorHandler::validateExpression(const QString& expression) {
    if (expression.trimmed().isEmpty()) {
        throw CalculationError(EMPTY_EXPRESSION, "Expression vide");
    }
}

void ErrorHandler::validateToken(const QString& token) {
    if (token.isEmpty()) {
        throw CalculationError(MALFORMED_EXPRESSION, "Token vide");
    }

    // Vérifier si c'est un opérateur valide de votre calculatrice
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "×" || token == "÷") {
        return; // Opérateur valide
    }

    // Sinon, vérifier si c'est un nombre valide
    bool ok;
    token.toDouble(&ok);
    if (!ok) {
        throw CalculationError(INVALID_NUMBER, "Nombre invalide: " + token);
    }
}

void ErrorHandler::validateParentheses(const QString& expression) {
    // Votre calculatrice n'a pas de parenthèses, donc cette validation est simplifiée
    // On peut la garder au cas où vous ajouteriez des parenthèses plus tard
    int count = 0;
    for (QChar c : expression) {
        if (c == '(') count++;
        else if (c == ')') count--;
        if (count < 0) {
            throw CalculationError(MISSING_PARENTHESIS, "Parenthèse fermante sans ouvrante");
        }
    }
    if (count != 0) {
        throw CalculationError(MISSING_PARENTHESIS, "Parenthèses non équilibrées");
    }
}

QString ErrorHandler::getErrorMessage(ErrorType type) {
    switch (type) {
    case DIVISION_BY_ZERO:
        return "Erreur: Division par zéro";
    case MALFORMED_EXPRESSION:
        return "Erreur: Expression malformée";
    case INVALID_NUMBER:
        return "Erreur: Nombre invalide";
    case MISSING_PARENTHESIS:
        return "Erreur: Parenthèses manquantes";
    case EMPTY_EXPRESSION:
        return "Erreur: Expression vide";
    default:
        return "Erreur inconnue";
    }
}

double ErrorHandler::handleError(const std::exception& e) {
    qDebug() << "Erreur de calcul:" << e.what();
    return 0.0;  // Valeur par défaut en cas d'erreur
}
