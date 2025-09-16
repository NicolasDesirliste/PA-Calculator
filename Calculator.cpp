#include "Calculator.h"
#include "ExpressionEvaluator.h"
#include <QDebug>

Calculator::Calculator() {
    clear();
}

void Calculator::clear() {
    expression = "";
    emit displayChanged();  // ✅ Signal émis
}

void Calculator::addNumber(QString number) {
    qDebug() << "addNumber appelée avec:" << number;
    expression += number;
    qDebug() << "Expression maintenant:" << expression;
    emit displayChanged();  // ✅ Signal émis
}

void Calculator::addOperator(QString op) {
    expression += op;
    emit displayChanged();  // ✅ Signal émis
}

QString Calculator::getDisplay() {
    qDebug() << "getDisplay appelée, retourne:" << expression;
    return expression.isEmpty() ? "0" : expression;
}

double Calculator::calculate() {
    double result = ExpressionEvaluator::evaluate(expression);
    expression = QString::number(result);  // ✅ Afficher le résultat
    emit displayChanged();  // ✅ Signal émis
    return result;
}
/*
#include "Calculator.h"
#include "ExpressionEvaluator.h"
#include <QDebug>

Calculator::Calculator() {
    clear();
}

void Calculator::clear() {
    expression = "";
}

void Calculator::addNumber(QString number) {
    qDebug() << "addNumber appelée avec:" << number;
    expression += number;
    qDebug() << "Expression maintenant:" << expression;
}

void Calculator::addOperator(QString op) {
    expression += op;
}

QString Calculator::getDisplay() {
    qDebug() << "getDisplay appelée, retourne:" << expression;
    return expression.isEmpty() ? "0" : expression;
}

double Calculator::calculate() {
    return ExpressionEvaluator::evaluate(expression);
}
*/
