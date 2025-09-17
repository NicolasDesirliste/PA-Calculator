import QtQuick

Column {
    // PROPRIÉTÉS DU COMPOSANT PRINCIPAL
    property var calculatorInstance                          // Instance de Calculator C++ passée depuis CalculatorWindow
    property int currentMode: 0                             // Mode actuel: 0=Calculatrice normale, 1=Pension Alimentaire

    // POSITIONNEMENT ET ESPACEMENT
    anchors.fill: parent                                    // Remplit tout l'espace du parent
    anchors.margins: 20                                     // Marge de 20px sur tous les côtés
    spacing: 20                                             // Espacement de 20px entre les composants

    // ÉCRAN D'AFFICHAGE - Montre les calculs et résultats
    CalculatorDisplay {
        id: displayText                                     // Identifiant pour référencer l'affichage
    }

    // LOGIQUE DE CALCUL - Traite les actions des boutons
    CalculatorLogic {
        id: calculatorLogic                                 // Identifiant pour référencer la logique
        calculatorObject: calculatorInstance               // Passe l'instance Calculator C++ à la logique
    }

    // CONTAINER DES GRILLES - Contient les différentes interfaces
    Item {
        width: parent.width                                 // Prend toute la largeur disponible
        height: 380                                         // Hauteur fixe pour accommoder PA

        // GRILLE CALCULATRICE NORMALE - Interface standard
        CalculatorGrid {
            id: normalGrid                                  // Identifiant de la grille normale
            visible: currentMode === 0                      // Visible seulement si mode = 0 (calculatrice)
            anchors.centerIn: parent                        // Centré dans le container

            // CONNEXION SIGNAUX - Quand un bouton normal est cliqué
            onButtonClicked: function(text, type) {
                calculatorLogic.processButtonAction(text, type)  // Traite l'action via CalculatorLogic
            }
        }

        // GRILLE PENSION ALIMENTAIRE - Interface spécialisée PA
        CalculatorGridPA {
            id: paGrid                                      // Identifiant de la grille PA
            visible: currentMode === 1                      // Visible seulement si mode = 1 (pension alimentaire)
            anchors.centerIn: parent                        // Centré dans le container
            anchors.topMargin: 20                           // Marge supplémentaire en haut

            // CONNEXION BOUTONS - Traite les clics sur boutons PA
            onButtonClicked: function(text, type) {
                calculatorLogic.processButtonAction(text, type)  // Traite via la même logique
            }

            // CONNEXION ANCIEN SIGNAL PA - Gardé pour compatibilité
            onPensionCalculationRequested: function(type, mode, children) {
                console.log("Signal PA ancien format:", type, mode, "pour", children, "enfants")
                // Ce signal pourrait être supprimé plus tard
            }

            // NOUVELLE CONNEXION - Nombre d'enfants sélectionné dans ComboBox
            onChildrenCountChanged: function(count) {
                console.log("CalculatorLayout: Nombre d'enfants changé à", count)
                // Transmet le nombre d'enfants à CalculatorLogic
                if (calculatorLogic.updateChildrenCount) {
                    calculatorLogic.updateChildrenCount(count)  // Met à jour la logique PA
                } else {
                    console.log("ERREUR: updateChildrenCount n'existe pas dans CalculatorLogic")
                }
            }
        }
    }

    // ESPACEMENT SUPPLÉMENTAIRE - Évite que le sélecteur soit collé aux boutons
    Item {
        height: 30                                          // Espace vide de 30px de hauteur
    }

    // SÉLECTEUR DE MODE - Bascule entre calculatrice et PA
    Row {
        anchors.horizontalCenter: parent.horizontalCenter   // Centré horizontalement
        spacing: 20                                         // Espacement de 20px

        ModeSelector {
            id: modeSelector                                // Identifiant du sélecteur de mode

            // CHANGEMENT DE MODE - Quand l'utilisateur sélectionne un mode différent
            onModeChanged: function(mode) {
                currentMode = mode                          // Met à jour le mode actuel

                // LOG POUR DÉBOGAGE - Affiche le mode sélectionné
                console.log("Mode changé vers:",
                    mode === 0 ? "Calculatrice normale" :
                    mode === 1 ? "Pension Alimentaire" :
                    "Mode inconnu (" + mode + ")")

                // RÉINITIALISATION - Efface les calculs en cours lors du changement de mode
                if (calculatorLogic && calculatorLogic.resetPensionValues) {
                    calculatorLogic.resetPensionValues()    // Reset des valeurs PA
                }
            }
        }
    }
}
