#include "PensionCalculator.h"      // Inclusion du fichier d'en-tête de la classe PensionCalculator
#include <QDebug>                    // Inclusion pour utiliser qDebug() - affichage de messages de debug
#include <QtMath>                    // Inclusion pour les fonctions mathématiques comme qAbs()

PensionCalculator::PensionCalculator(QObject *parent)  // Constructeur de la classe PensionCalculator
    : QObject(parent)                // Initialisation de la classe parent QObject
    , m_revenuDebiteur(0.0)          // Initialisation du revenu débiteur à 0.0
    , m_revenuCreancier(0.0)         // Initialisation du revenu créancier à 0.0
    , m_nombreEnfants(1)             // Initialisation du nombre d'enfants à 1
    , m_montantPA(0.0)               // Initialisation du montant PA à 0.0
{                                    // Début du corps du constructeur
}                                    // Fin du constructeur (corps vide)

void PensionCalculator::setRevenuDebiteur(double revenu) {  // Fonction pour définir le revenu du débiteur
    if (qFuzzyCompare(m_revenuDebiteur, revenu)) return;    // Si la valeur est déjà identique : sortir de la fonction

    if (validerRevenu(revenu)) {                            // Si le revenu est valide (validation)
        m_revenuDebiteur = revenu;                          // Assigner la nouvelle valeur au membre privé
        emit revenuDebiteurChanged();                       // Émettre le signal de changement vers QML
    }                                                       // Fin du if de validation
}                                                          // Fin de la fonction setRevenuDebiteur

void PensionCalculator::setRevenuCreancier(double revenu) { // Fonction pour définir le revenu du créancier
    if (qFuzzyCompare(m_revenuCreancier, revenu)) return;   // Si la valeur est déjà identique : sortir de la fonction

    if (validerRevenu(revenu)) {                            // Si le revenu est valide (validation)
        m_revenuCreancier = revenu;                         // Assigner la nouvelle valeur au membre privé
        emit revenuCreancierChanged();                      // Émettre le signal de changement vers QML
    }                                                       // Fin du if de validation
}                                                          // Fin de la fonction setRevenuCreancier

void PensionCalculator::setNombreEnfants(int nombre) {      // Fonction pour définir le nombre d'enfants
    if (m_nombreEnfants == nombre) return;                 // Si la valeur est déjà identique : sortir de la fonction

    if (validerNombreEnfants(nombre)) {                     // Si le nombre d'enfants est valide (validation)
        m_nombreEnfants = nombre;                           // Assigner la nouvelle valeur au membre privé
        emit nombreEnfantsChanged();                        // Émettre le signal de changement vers QML
    }                                                       // Fin du if de validation
}                                                          // Fin de la fonction setNombreEnfants

// ==================== CALCULS PRINCIPAUX ====================

void PensionCalculator::calculerPA1(double revenuDebiteur, int nombreEnfants) { // Fonction de calcul PA1 (garde classique)
    qDebug() << "Calcul PA1 - Garde classique";                                 // Affichage debug : type de calcul
    qDebug() << "Revenu débiteur:" << revenuDebiteur << "€";                     // Affichage debug : revenu débiteur
    qDebug() << "Nombre d'enfants:" << nombreEnfants;                           // Affichage debug : nombre d'enfants

    if (!validerRevenu(revenuDebiteur) || !validerNombreEnfants(nombreEnfants)) { // Si revenu ou nombre d'enfants invalide
        m_montantPA = 0.0;                                                       // Mettre le montant PA à zéro
        emit montantPAChanged();                                                 // Émettre signal de changement
        return;                                                                  // Sortir de la fonction
    }                                                                            // Fin du if de validation

    m_montantPA = calculerPA1Interne(revenuDebiteur, nombreEnfants);            // Appel de la fonction de calcul interne
    m_derniersDetails = QString("PA1 (Garde classique): %1€ pour %2 enfant(s) sur revenu de %3€") // Création du message détaillé
                            .arg(m_montantPA, 0, 'f', 2)                            // Insertion du montant PA avec 2 décimales
                            .arg(nombreEnfants)                                      // Insertion du nombre d'enfants
                            .arg(revenuDebiteur, 0, 'f', 2);                        // Insertion du revenu avec 2 décimales

    qDebug() << "Résultat PA1:" << m_montantPA << "€";                          // Affichage debug : résultat final

    emit montantPAChanged();                                                     // Émettre signal de changement du montant
    emit calculTermine(m_montantPA, m_derniersDetails);                         // Émettre signal de fin de calcul avec détails
}                                                                                // Fin de la fonction calculerPA1

void PensionCalculator::calculerPA2(double revenuDebiteur, double revenuCreancier, int nombreEnfants) { // Fonction de calcul PA2 (garde alternée)
    qDebug() << "Calcul PA2 - Garde alternée";                                  // Affichage debug : type de calcul
    qDebug() << "Revenu débiteur:" << revenuDebiteur << "€";                     // Affichage debug : revenu débiteur
    qDebug() << "Revenu créancier:" << revenuCreancier << "€";                   // Affichage debug : revenu créancier
    qDebug() << "Nombre d'enfants:" << nombreEnfants;                           // Affichage debug : nombre d'enfants

    if (!validerRevenu(revenuDebiteur) || !validerRevenu(revenuCreancier) || !validerNombreEnfants(nombreEnfants)) { // Si un des paramètres est invalide
        m_montantPA = 0.0;                                                       // Mettre le montant PA à zéro
        emit montantPAChanged();                                                 // Émettre signal de changement
        return;                                                                  // Sortir de la fonction
    }                                                                            // Fin du if de validation

    m_montantPA = calculerPA2Interne(revenuDebiteur, revenuCreancier, nombreEnfants); // Appel de la fonction de calcul interne
    m_derniersDetails = QString("PA2 (Garde alternée): %1€ pour %2 enfant(s) - Revenus: %3€ vs %4€") // Création du message détaillé
                            .arg(m_montantPA, 0, 'f', 2)                            // Insertion du montant PA avec 2 décimales
                            .arg(nombreEnfants)                                      // Insertion du nombre d'enfants
                            .arg(revenuDebiteur, 0, 'f', 2)                         // Insertion du revenu débiteur avec 2 décimales
                            .arg(revenuCreancier, 0, 'f', 2);                       // Insertion du revenu créancier avec 2 décimales

    qDebug() << "Résultat PA2:" << m_montantPA << "€";                          // Affichage debug : résultat final

    emit montantPAChanged();                                                     // Émettre signal de changement du montant
    emit calculTermine(m_montantPA, m_derniersDetails);                         // Émettre signal de fin de calcul avec détails
}                                                                                // Fin de la fonction calculerPA2

void PensionCalculator::calculerPA3(double revenuDebiteur, int nombreEnfants) { // Fonction de calcul PA3 (garde réduite)
    qDebug() << "Calcul PA3 - Garde réduite";                                   // Affichage debug : type de calcul
    qDebug() << "Revenu débiteur:" << revenuDebiteur << "€";                     // Affichage debug : revenu débiteur
    qDebug() << "Nombre d'enfants:" << nombreEnfants;                           // Affichage debug : nombre d'enfants

    if (!validerRevenu(revenuDebiteur) || !validerNombreEnfants(nombreEnfants)) { // Si revenu ou nombre d'enfants invalide
        m_montantPA = 0.0;                                                       // Mettre le montant PA à zéro
        emit montantPAChanged();                                                 // Émettre signal de changement
        return;                                                                  // Sortir de la fonction
    }                                                                            // Fin du if de validation

    m_montantPA = calculerPA3Interne(revenuDebiteur, nombreEnfants);            // Appel de la fonction de calcul interne
    m_derniersDetails = QString("PA3 (Garde réduite): %1€ pour %2 enfant(s) sur revenu de %3€") // Création du message détaillé
                            .arg(m_montantPA, 0, 'f', 2)                            // Insertion du montant PA avec 2 décimales
                            .arg(nombreEnfants)                                      // Insertion du nombre d'enfants
                            .arg(revenuDebiteur, 0, 'f', 2);                        // Insertion du revenu avec 2 décimales

    qDebug() << "Résultat PA3:" << m_montantPA << "€";                          // Affichage debug : résultat final

    emit montantPAChanged();                                                     // Émettre signal de changement du montant
    emit calculTermine(m_montantPA, m_derniersDetails);                         // Émettre signal de fin de calcul avec détails
}                                                                                // Fin de la fonction calculerPA3

// ==================== CALCULS INTERNES ====================

double PensionCalculator::calculerPA1Interne(double revenu, int enfants) {      // Fonction interne de calcul PA1
    // PA1 - Garde classique : pourcentage du revenu disponible (après déduction du minimum vital)
    const double minimumVital = 648.0;                                          // Constante : minimum vital garanti au débiteur (648€ en 2025)
    double revenuDisponible = revenu - minimumVital;                            // Calcul du revenu disponible : revenu net - minimum vital

    if (revenuDisponible <= 0.0) {                                              // Si le revenu disponible est négatif ou nul
        return 0.0;                                                             // Retourner 0€ de pension (pas assez de revenus)
    }                                                                           // Fin du if revenu insuffisant

    double pourcentage = getPourcentagePA1(enfants);                            // Récupération du pourcentage selon le nombre d'enfants
    return revenuDisponible * pourcentage / 100.0;                             // Calcul : revenu disponible × pourcentage ÷ 100
}                                                                               // Fin de la fonction calculerPA1Interne

double PensionCalculator::calculerPA2Interne(double revenuDeb, double revenuCrea, int enfants) { // Fonction interne de calcul PA2
    // PA2 - Garde alternée : pourcentage du revenu disponible le plus élevé (logique corrigée)
    const double minimumVital = 648.0;                                          // Constante : minimum vital garanti au débiteur (648€ en 2025)
    double revenuDisponibleDeb = revenuDeb - minimumVital;                      // Calcul du revenu disponible débiteur
    double revenuDisponibleCrea = revenuCrea - minimumVital;                    // Calcul du revenu disponible créancier

    if (revenuDisponibleDeb <= 0.0) {                                           // Si le revenu disponible débiteur est insuffisant
        return 0.0;                                                             // Retourner 0€ de pension
    }                                                                           // Fin du if revenu débiteur insuffisant

    // Pour la garde alternée, on prend généralement le revenu le plus élevé
    double revenuReference = (revenuDisponibleDeb > revenuDisponibleCrea) ?     // Opérateur ternaire : si revenu débiteur > créancier
                                 revenuDisponibleDeb : revenuDisponibleCrea;         // Alors prendre débiteur, sinon prendre créancier

    double pourcentage = getPourcentagePA2(enfants);                            // Récupération du pourcentage selon le nombre d'enfants
    return revenuReference * pourcentage / 100.0;                              // Calcul : revenu de référence × pourcentage ÷ 100
}                                                                               // Fin de la fonction calculerPA2Interne

double PensionCalculator::calculerPA3Interne(double revenu, int enfants) {      // Fonction interne de calcul PA3
    // PA3 - Garde réduite : pourcentage du revenu disponible (après déduction du minimum vital)
    const double minimumVital = 648.0;                                          // Constante : minimum vital garanti au débiteur (648€ en 2025)
    double revenuDisponible = revenu - minimumVital;                            // Calcul du revenu disponible : revenu net - minimum vital

    if (revenuDisponible <= 0.0) {                                              // Si le revenu disponible est négatif ou nul
        return 0.0;                                                             // Retourner 0€ de pension (pas assez de revenus)
    }                                                                           // Fin du if revenu insuffisant

    double pourcentage = getPourcentagePA3(enfants);                            // Récupération du pourcentage selon le nombre d'enfants
    return revenuDisponible * pourcentage / 100.0;                             // Calcul : revenu disponible × pourcentage ÷ 100
}                                                                               // Fin de la fonction calculerPA3Interne

// ==================== BARÈME OFFICIEL 2025 ====================

double PensionCalculator::getPourcentagePA1(int nombreEnfants) { // Fonction pour calculer le pourcentage PA1 selon le nombre d'enfants
    // PA1 = Garde classique - Barème officiel ministère de la Justice 2025
    // Colonne du milieu du tableau : quand un parent a la garde principale
    switch (nombreEnfants) {                                     // Structure de contrôle pour tester la valeur de nombreEnfants
    case 1: return 13.5;    // Si 1 enfant : retourner 13.5% du revenu net disponible
    case 2: return 11.5;    // Si 2 enfants : retourner 11.5% du revenu net disponible
    case 3: return 10.0;    // Si 3 enfants : retourner 10.0% du revenu net disponible
    case 4: return 8.8;     // Si 4 enfants : retourner 8.8% du revenu net disponible
    case 5: return 8.0;     // Si 5 enfants : retourner 8.0% du revenu net disponible
    case 6: return 7.2;     // Si 6 enfants : retourner 7.2% du revenu net disponible
    default:                // Cas par défaut si nombreEnfants ne correspond à aucun case précédent
        if (nombreEnfants > 6) return 7.2; // Si plus de 6 enfants : garder le même pourcentage que 6 enfants
        return 13.5; // Sinon (valeur aberrante) : retourner le pourcentage pour 1 enfant
    }                       // Fin du switch
}                          // Fin de la fonction getPourcentagePA1

double PensionCalculator::getPourcentagePA2(int nombreEnfants) { // Fonction pour calculer le pourcentage PA2 selon le nombre d'enfants
    // PA2 = Garde alternée - Barème officiel ministère de la Justice 2025
    // Colonne de droite du tableau : garde partagée 50/50 entre les parents
    switch (nombreEnfants) {                                     // Structure de contrôle pour tester la valeur de nombreEnfants
    case 1: return 9.0;     // Si 1 enfant : retourner 9.0% du revenu net disponible
    case 2: return 7.8;     // Si 2 enfants : retourner 7.8% du revenu net disponible
    case 3: return 6.7;     // Si 3 enfants : retourner 6.7% du revenu net disponible
    case 4: return 5.9;     // Si 4 enfants : retourner 5.9% du revenu net disponible
    case 5: return 5.3;     // Si 5 enfants : retourner 5.3% du revenu net disponible
    case 6: return 4.8;     // Si 6 enfants : retourner 4.8% du revenu net disponible
    default:                // Cas par défaut si nombreEnfants ne correspond à aucun case précédent
        if (nombreEnfants > 6) return 4.8; // Si plus de 6 enfants : garder le même pourcentage que 6 enfants
        return 9.0; // Sinon (valeur aberrante) : retourner le pourcentage pour 1 enfant
    }                       // Fin du switch
}                          // Fin de la fonction getPourcentagePA2

double PensionCalculator::getPourcentagePA3(int nombreEnfants) { // Fonction pour calculer le pourcentage PA3 selon le nombre d'enfants
    // PA3 = Garde réduite - Barème officiel ministère de la Justice 2025
    // Colonne de gauche du tableau : droit de visite et d'hébergement limité (weekends)
    switch (nombreEnfants) {                                     // Structure de contrôle pour tester la valeur de nombreEnfants
    case 1: return 18.0;    // Si 1 enfant : retourner 18.0% du revenu net disponible
    case 2: return 15.5;    // Si 2 enfants : retourner 15.5% du revenu net disponible
    case 3: return 13.3;    // Si 3 enfants : retourner 13.3% du revenu net disponible
    case 4: return 11.7;    // Si 4 enfants : retourner 11.7% du revenu net disponible
    case 5: return 10.6;    // Si 5 enfants : retourner 10.6% du revenu net disponible
    case 6: return 9.5;     // Si 6 enfants : retourner 9.5% du revenu net disponible
    default:                // Cas par défaut si nombreEnfants ne correspond à aucun case précédent
        if (nombreEnfants > 6) return 9.5; // Si plus de 6 enfants : garder le même pourcentage que 6 enfants
        return 18.0; // Sinon (valeur aberrante) : retourner le pourcentage pour 1 enfant
    }                       // Fin du switch
}                          // Fin de la fonction getPourcentagePA3

// ==================== VALIDATION ====================

bool PensionCalculator::validerRevenu(double revenu) {           // Fonction de validation du revenu
    if (revenu < 0.0) {                                          // Si le revenu est négatif
        qWarning() << "Revenu négatif non autorisé:" << revenu;  // Afficher un avertissement de debug
        return false;                                            // Retourner false (invalide)
    }                                                            // Fin du if négatif
    // Pas de plafond maximum - certaines personnes ont des revenus très élevés
    return true;                                                 // Retourner true (valide)
}                                                                // Fin de la fonction validerRevenu

bool PensionCalculator::validerNombreEnfants(int nombre) {       // Fonction de validation du nombre d'enfants
    if (nombre < 1) {                                            // Si le nombre d'enfants est inférieur à 1
        qWarning() << "Nombre d'enfants doit être >= 1:" << nombre; // Afficher un avertissement de debug
        return false;                                            // Retourner false (invalide)
    }                                                            // Fin du if < 1
    if (nombre > 9) { // Limite selon votre ComboBox (1-9 enfants)  // Si le nombre d'enfants est supérieur à 9
        qWarning() << "Nombre d'enfants doit être <= 9:" << nombre; // Afficher un avertissement de debug
        return false;                                            // Retourner false (invalide)
    }                                                            // Fin du if > 9
    return true;                                                 // Retourner true (valide)
}                                                                // Fin de la fonction validerNombreEnfants

// ==================== UTILITAIRES ====================

void PensionCalculator::clear() {                               // Fonction pour remettre à zéro tous les paramètres
    m_revenuDebiteur = 0.0;                                      // Remettre le revenu débiteur à zéro
    m_revenuCreancier = 0.0;                                     // Remettre le revenu créancier à zéro
    m_nombreEnfants = 1;                                         // Remettre le nombre d'enfants à 1 (valeur par défaut)
    m_montantPA = 0.0;                                           // Remettre le montant PA à zéro
    m_derniersDetails.clear();                                   // Vider la chaîne des derniers détails

    emit revenuDebiteurChanged();                                // Émettre signal de changement du revenu débiteur
    emit revenuCreancierChanged();                               // Émettre signal de changement du revenu créancier
    emit nombreEnfantsChanged();                                 // Émettre signal de changement du nombre d'enfants
    emit montantPAChanged();                                     // Émettre signal de changement du montant PA
}                                                                // Fin de la fonction clear

QString PensionCalculator::getDetailsCalcul() const {           // Fonction pour récupérer les détails du dernier calcul
    return m_derniersDetails;                                    // Retourner la chaîne contenant les derniers détails
}                                                                // Fin de la fonction getDetailsCalcul
