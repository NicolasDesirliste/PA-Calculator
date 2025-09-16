#include "ExpressionEvaluator.h"
#include <QDebug>

double ExpressionEvaluator::evaluate(const QString& expression) {
    try {
        // 1. Validation d'entrée
        validateInput(expression);

        // 2. Tokenisation
        QStringList tokens = Tokenizer::tokenize(expression);

        // 3. Évaluation
        return evaluateTokens(tokens);

    } catch (const ErrorHandler::CalculationError& e) {
        qDebug() << "Erreur de calcul:" << e.what();
        return ErrorHandler::handleError(e);
    } catch (const std::exception& e) {
        qDebug() << "Erreur inattendue:" << e.what();
        return ErrorHandler::handleError(e);
    }
}

double ExpressionEvaluator::evaluateTokens(const QStringList& tokens) {
    if (tokens.isEmpty()) {
        return 0.0;
    }

    // Validation des tokens
    for (const QString& token : tokens) {
        ErrorHandler::validateToken(token);
    }

    // Parse et calcul
    return ExpressionParser::parse(tokens);
}

void ExpressionEvaluator::validateInput(const QString& expression) {
    ErrorHandler::validateExpression(expression);
}
