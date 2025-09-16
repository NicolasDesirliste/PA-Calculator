#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H

#include <QString>
#include "Tokenizer.h"
#include "ArithmeticCalculator.h"
#include "ExpressionParser.h"
#include "ErrorHandler.h"

/**
 * ExpressionEvaluator - Orchestrateur principal
 * Coordonne tous les composants pour évaluer une expression mathématique
 *
 * Architecture modulaire :
 * 1. Tokenizer - Découpe l'expression en tokens
 * 2. ErrorHandler - Valide et gère les erreurs
 * 3. ExpressionParser - Analyse syntaxique avec priorités
 * 4. ArithmeticCalculator - Exécute les opérations
 */
class ExpressionEvaluator {
public:
    /**
     * Point d'entrée principal pour évaluer une expression
     * @param expression L'expression à calculer (ex: "2+3*4")
     * @return Le résultat du calcul (ex: 14.0)
     */
    static double evaluate(const QString& expression);

private:
    // Méthodes d'orchestration
    static double evaluateTokens(const QStringList& tokens);
    static void validateInput(const QString& expression);
};

#endif // EXPRESSIONEVALUATOR_H
