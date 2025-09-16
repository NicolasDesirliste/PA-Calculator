#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>
#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString display READ getDisplay NOTIFY displayChanged)  // ✅ Binding automatique

private:
    QString expression;

public:
    Calculator();

public slots:
    void addNumber(QString number); // Ajouter une valeur
    void addOperator(QString op);
    double calculate(); // pour procéder avec =
    void clear(); // remettre à 0

    QString getDisplay(); // pour afficher

signals:
    void displayChanged();  // Signal pour notifier QML

};

#endif // CALCULATOR_H

/*
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>
#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
private:
    QString expression;

public:
    Calculator();

public slots:

    void addNumber(QString number); // Ajouter une valeur
    void addOperator(QString op);
    double calculate(); // pour procéder avec =
    void clear(); // remettre à 0

    QString getDisplay(); // pour afficher

signals:
    void displayChanged();  // Signal pour notifier QML

};

#endif // CALCULATOR_H

*/
