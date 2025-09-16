#include "ArithmeticCalculator.h"
#include "ErrorHandler.h"

double ArithmeticCalculator::add(double a, double b) {
    return a + b;
}

double ArithmeticCalculator::subtract(double a, double b) {
    return a - b;
}

double ArithmeticCalculator::multiply(double a, double b) {
    return a * b;
}

double ArithmeticCalculator::divide(double a, double b) {
    if (!isValidDivision(b)) {
        throw ErrorHandler::CalculationError(
            ErrorHandler::DIVISION_BY_ZERO,
            "Division par zéro"
            );
    }
    return a / b;
}

bool ArithmeticCalculator::isValidDivision(double divisor) {
    return divisor != 0.0;
}
