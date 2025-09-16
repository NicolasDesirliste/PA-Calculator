// CalculatorButton.qml - Composant bouton réutilisable
import QtQuick
import QtQuick.Controls

Button {
    property string buttonText: ""
    property string buttonType: "number"
    property string buttonColor: "#95a5a6"

    signal buttonClicked(string text, string type)

    text: buttonText
    width: 60
    height: 60

    background: Rectangle {
        color: "transparent"
        border.color: "#3498db"
        border.width: 1
        radius: 10
    }

    // Style du texte uniforme
    contentItem: Text {
        text: buttonText
        color: "#3498db"        // Blanc pour tous les boutons
        font.pixelSize: 18
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    onClicked: {
        buttonClicked(buttonText, buttonType)
    }
}

/*
Button {
    // PROPRIÉTÉS EXPOSÉES - Paramètres configurables
    property string buttonText: ""           // Texte affiché sur le bouton
    property string buttonType: "number"     // Type : "number", "operator", "action"
    property string buttonColor: "#95a5a6"   // Couleur de fond du bouton

    // SIGNAL PERSONNALISÉ - Émis quand le bouton est cliqué
    signal buttonClicked(string text, string type)

    // APPARENCE
    text: buttonText        // Affiche le texte configuré
    width: 60              // Largeur fixe
    height: 60             // Hauteur fixe

    // STYLE DU BOUTON
    background: Rectangle {
        color: "transparent"  // Utilise la couleur configurée
        border.color: "#3498db"
        border.width: 3
        radius: 10         // Coins arrondis
    }

    // GESTION DU CLIC
    onClicked: {
        // Émet le signal personnalisé avec les données du bouton
        buttonClicked(buttonText, buttonType)
    }
}
*/
