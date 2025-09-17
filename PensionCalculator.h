#ifndef PENSIONCALCULATOR_H
#define PENSIONCALCULATOR_H

#include <QObject>
#include <QString>

/**
 * PensionCalculator - Calculs de pension alimentaire selon barème français
 * Gère PA1, PA2, PA3 avec différents modes (classique, alternée, réduite)
 */
class PensionCalculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double revenuDebiteur READ getRevenuDebiteur WRITE setRevenuDebiteur NOTIFY revenuDebiteurChanged)
    Q_PROPERTY(double revenuCreancier READ getRevenuCreancier WRITE setRevenuCreancier NOTIFY revenuCreancierChanged)
    Q_PROPERTY(int nombreEnfants READ getNombreEnfants WRITE setNombreEnfants NOTIFY nombreEnfantsChanged)
    Q_PROPERTY(double montantPA READ getMontantPA NOTIFY montantPAChanged)

public:
    explicit PensionCalculator(QObject *parent = nullptr);

    // Types de pension alimentaire
    enum TypePA {
        PA1_CLASSIQUE,    // Garde classique (1 parent garde, 1 parent visite)
        PA2_ALTERNEE,     // Garde alternée (50/50)
        PA3_REDUITE       // Garde réduite (weekends seulement)
    };
    Q_ENUM(TypePA)

    // Getters
    double getRevenuDebiteur() const { return m_revenuDebiteur; }
    double getRevenuCreancier() const { return m_revenuCreancier; }
    int getNombreEnfants() const { return m_nombreEnfants; }
    double getMontantPA() const { return m_montantPA; }

    // Setters
    void setRevenuDebiteur(double revenu);
    void setRevenuCreancier(double revenu);
    void setNombreEnfants(int nombre);

public slots:
    // Calculs principaux - appelés depuis QML
    void calculerPA1(double revenuDebiteur, int nombreEnfants);
    void calculerPA2(double revenuDebiteur, double revenuCreancier, int nombreEnfants);
    void calculerPA3(double revenuDebiteur, int nombreEnfants);

    // Méthodes utilitaires
    void clear();
    QString getDetailsCalcul() const;

signals:
    void revenuDebiteurChanged();
    void revenuCreancierChanged();
    void nombreEnfantsChanged();
    void montantPAChanged();
    void calculTermine(double montant, QString details);

private:
    // Données membres
    double m_revenuDebiteur;
    double m_revenuCreancier;
    int m_nombreEnfants;
    double m_montantPA;
    QString m_derniersDetails;

    // Méthodes de calcul internes
    double calculerPA1Interne(double revenu, int enfants);
    double calculerPA2Interne(double revenuDeb, double revenuCrea, int enfants);
    double calculerPA3Interne(double revenu, int enfants);

    // Barème officiel français (pourcentages selon nombre d'enfants)
    double getPourcentagePA1(int nombreEnfants);
    double getPourcentagePA2(int nombreEnfants);
    double getPourcentagePA3(int nombreEnfants);

    // Validation
    bool validerRevenu(double revenu);
    bool validerNombreEnfants(int nombre);
};

#endif // PENSIONCALCULATOR_H
