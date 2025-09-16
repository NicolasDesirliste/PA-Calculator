// CalculatorDisplay.qml - Composant pour l'écran d'affichage

import QtQuick

Rectangle {
    // DIMENSIONS ET APPARENCE
    width: parent.width   // Prend la largeur du parent
    height: 80           // Hauteur fixe
    color: "transparent" // Transparence fenêtre résultat
    radius: 10           // Coins arrondis
    border.color: "#3498db"     // ← Couleur des bords
    border.width: 1             // ← Épaisseur des bords

    // TEXTE AFFICHÉ
    Text {
        id: displayText
        anchors.centerIn: parent  // Centré dans le rectangle
        text: calculator.display  // BINDING AUTOMATIQUE avec la Q_PROPERTY
        font.pixelSize: 46       // Taille police
        color: "#3498db"           // Couleur blanche
        font.bold: true          // Gras
    }
}

/*

Ancien code

import QtQuick

Rectangle {
    // PROPRIÉTÉS EXPOSÉES - Paramètres configurables depuis l'extérieur
    property string displayValue: "0"  // Valeur à afficher (modifiable depuis Main.qml)

    // DIMENSIONS ET APPARENCE
    width: parent.width   // Prend la largeur du parent
    height: 80           // Hauteur fixe
    color: "#34495e"     // Gris foncé
    radius: 10           // Coins arrondis

    // TEXTE AFFICHÉ
    Text {
        id: displayText
        anchors.centerIn: parent  // Centré dans le rectangle
        text: displayValue        // Utilise la propriété exposée
        font.pixelSize: 36       // Taille police
        color: "white"           // Couleur blanche
        font.bold: true          // Gras
    }
}
*/
