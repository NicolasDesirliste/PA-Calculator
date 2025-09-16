#ifndef ARITHMETICCALCULATOR_H
#define ARITHMETICCALCULATOR_H

/**
 * ArithmeticCalculator - Responsable des opérations arithmétiques de base
 * Addition, Soustraction, Multiplication, Division
 */
class ArithmeticCalculator {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);

    // Validation
    static bool isValidDivision(double divisor);
};

#endif // ARITHMETICCALCULATOR_H
