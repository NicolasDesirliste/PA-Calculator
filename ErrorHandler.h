#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <QString>
#include <stdexcept>

/**
 * ErrorHandler - Responsable de la gestion et validation des erreurs
 * Gère les cas d'erreur comme division par zéro, expressions malformées, etc.
 */
class ErrorHandler {
public:
    // Types d'erreurs
    enum ErrorType {
        DIVISION_BY_ZERO,
        MALFORMED_EXPRESSION,
        INVALID_NUMBER,
        MISSING_PARENTHESIS,
        EMPTY_EXPRESSION
    };

    // Exceptions personnalisées
    class CalculationError : public std::runtime_error {
    public:
        CalculationError(ErrorType type, const QString& message);
        ErrorType getType() const;

    private:
        ErrorType errorType;
    };

    // Méthodes de validation
    static void validateDivision(double divisor);
    static void validateExpression(const QString& expression);
    static void validateToken(const QString& token);
    static void validateParentheses(const QString& expression);

    // Gestion des erreurs
    static QString getErrorMessage(ErrorType type);
    static double handleError(const std::exception& e);
};

#endif // ERRORHANDLER_H
