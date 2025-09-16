// CalculatorGrid.qml - Grille de boutons avec données
import QtQuick

Grid {
    // PROPRIÉTÉS DE LA GRILLE
    id: grid
    columns: 4                              // 4 colonnes (standard calculatrice)
    spacing: 10                             // Espacement entre boutons
    anchors.horizontalCenter: parent.horizontalCenter  // Centré horizontalement

    // SIGNAL EXPOSÉ - Propagé vers le parent (Main.qml)
    signal buttonClicked(string text, string type)

    // GÉNÉRATEUR DE BOUTONS
    Repeater {
        // MODÈLE DE DONNÉES - Configuration de tous les boutons
        model: [
            // Ligne 1 : Actions et opérateurs spéciaux
            {text: "C", type: "action", color: "#e74c3c"},      // Clear (rouge)
            {text: "±", type: "operator", color: "#f39c12"},    // Plus/Moins (orange)
            {text: "%", type: "operator", color: "#f39c12"},    // Pourcentage (orange)
            {text: "÷", type: "operator", color: "#f39c12"},    // Division (orange)

            // Ligne 2 : Chiffres 7-9 et multiplication
            {text: "7", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "8", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "9", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "×", type: "operator", color: "#f39c12"},    // Multiplication (orange)

            // Ligne 3 : Chiffres 4-6 et soustraction
            {text: "4", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "5", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "6", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "-", type: "operator", color: "#f39c12"},    // Soustraction (orange)

            // Ligne 4 : Chiffres 1-3 et addition
            {text: "1", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "2", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "3", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: "+", type: "operator", color: "#f39c12"},    // Addition (orange)

            // Ligne 5 : Zéro, décimale et égal
            {text: "0", type: "number", color: "#95a5a6"},      // Chiffre (gris)
            {text: ".", type: "number", color: "#95a5a6"},      // Point décimal (gris)
            {text: "=", type: "action", color: "#27ae60"}       // Égal/Calcul (vert)
        ]

        // TEMPLATE DE BOUTON - Un CalculatorButton par élément du modèle
        CalculatorButton {
            buttonText: modelData.text
            buttonType: modelData.type
            buttonColor: modelData.color

            onButtonClicked: function(text, type) {
                console.log("Signal reçu dans CalculatorGrid:", text, type)
                grid.buttonClicked(text, type)  // Référence directe par ID

            }
        }
    }
}
