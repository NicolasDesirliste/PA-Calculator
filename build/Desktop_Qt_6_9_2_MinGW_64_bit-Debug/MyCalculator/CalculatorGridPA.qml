import QtQuick           // Import du module QML de base
import QtQuick.Controls // Import du module pour les contrôles (ComboBox)

Column {
    // PROPRIÉTÉS DE LA GRILLE - Container principal en colonnes
    id: grid                                              // Identifiant unique pour référencer ce composant
    spacing: 10                                           // Espacement de 10px entre chaque ligne
    anchors.horizontalCenter: parent.horizontalCenter     // Centre horizontalement dans le parent

    // SIGNAUX EXPOSÉS - Communication avec les composants parents
    signal buttonClicked(string text, string type)                        // Signal émis quand un bouton normal est cliqué
    signal pensionCalculationRequested(string type, string mode, int children) // Signal émis pour les calculs PA
    signal childrenCountChanged(int count)                                     // NOUVEAU: Signal pour le nombre d'enfants

    // LIGNE 1 - Actions, pourcentage et PA1
    Row {
        spacing: 10                                       // Espacement de 10px entre boutons
        anchors.horizontalCenter: parent.horizontalCenter // Centre la ligne horizontalement

        // Bouton Clear - Efface tout
        CalculatorButton {
            buttonText: "C"                              // Texte affiché sur le bouton
            buttonType: "action"                         // Type: action (pour la logique)
            buttonColor: "#e74c3c"                       // Couleur rouge pour les actions importantes
            onButtonClicked: function(text, type) {      // Gestionnaire d'événement clic
                grid.buttonClicked(text, type)           // Propage le signal vers le parent
            }
        }

        // Bouton Return - Reset des valeurs PA
        CalculatorButton {
            buttonText: "R"                              // R pour Return/Reset
            buttonType: "action"                         // Type: action
            buttonColor: "#f39c12"                       // Couleur orange pour les actions secondaires
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton Pourcentage - Calcul de pourcentage
        CalculatorButton {
            buttonText: "%"                              // Symbole pourcentage
            buttonType: "operator"                       // Type: opérateur mathématique
            buttonColor: "#f39c12"                       // Couleur orange pour les opérateurs
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton PA1 - Calcul pension alimentaire garde classique
        CalculatorButton {
            buttonText: "PA1"                            // PA1 = Pension Alimentaire type 1
            buttonType: "pensionOperator"                // Type spécial pour les calculs PA
            buttonColor: "#f39c12"                       // Couleur orange pour les opérateurs PA
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
    }

    // LIGNE 2 - Chiffres 7, 8, 9 et PA2
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        // Boutons numériques 7, 8, 9 - Saisie des revenus
        CalculatorButton {
            buttonText: "7"                              // Chiffre 7
            buttonType: "number"                         // Type: nombre (pour saisie revenus)
            buttonColor: "#95a5a6"                       // Couleur grise pour les chiffres
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "8"                              // Chiffre 8
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "9"                              // Chiffre 9
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton PA2 - Calcul pension alimentaire garde alternée
        CalculatorButton {
            buttonText: "PA2"                            // PA2 = Pension Alimentaire type 2 (garde alternée)
            buttonType: "pensionOperator"
            buttonColor: "#f39c12"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
    }

    // LIGNE 3 - Chiffres 4, 5, 6 et PA3
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        // Boutons numériques 4, 5, 6
        CalculatorButton {
            buttonText: "4"                              // Chiffre 4
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "5"                              // Chiffre 5
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "6"                              // Chiffre 6
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton PA3 - Calcul pension alimentaire garde réduite
        CalculatorButton {
            buttonText: "PA3"                            // PA3 = Pension Alimentaire type 3 (garde réduite)
            buttonType: "pensionOperator"
            buttonColor: "#f39c12"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
    }

    // LIGNE 4 - Chiffres 1, 2, 3 et addition
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        // Boutons numériques 1, 2, 3
        CalculatorButton {
            buttonText: "1"                              // Chiffre 1
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "2"                              // Chiffre 2
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
        CalculatorButton {
            buttonText: "3"                              // Chiffre 3
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton Addition - Opération mathématique classique
        CalculatorButton {
            buttonText: "+"                              // Symbole addition
            buttonType: "operator"                       // Type: opérateur mathématique standard
            buttonColor: "#f39c12"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }
    }

    // LIGNE 5 - Zéro, point décimal et sélecteur d'enfants
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        // Bouton zéro
        CalculatorButton {
            buttonText: "0"                              // Chiffre 0
            buttonType: "number"
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // Bouton point décimal - Pour les revenus avec décimales
        CalculatorButton {
            buttonText: "."                              // Point décimal (ex: 2500.50)
            buttonType: "number"                         // Traité comme un nombre
            buttonColor: "#95a5a6"
            onButtonClicked: function(text, type) {
                grid.buttonClicked(text, type)
            }
        }

        // COMBOBOX SÉLECTEUR D'ENFANTS - Composant spécialisé
        ComboBox {
            id: childrenComboBox                         // Identifiant unique du ComboBox
            width: 130                                   // Largeur: équivalent à 2 boutons + espacement
            height: 60                                   // Hauteur: identique aux boutons

            // MODÈLE DE DONNÉES - Liste déroulante 1 à 9 enfants
            model: ["1 enfant", "2 enfants", "3 enfants", "4 enfants", "5 enfants",
                    "6 enfants", "7 enfants", "8 enfants", "9 enfants"]

            currentIndex: 0                              // Valeur par défaut: 1 enfant (index 0)

            // STYLE VISUEL - Cohérent avec les boutons de la calculatrice
            background: Rectangle {
                color: "transparent"                     // Fond transparent
                border.color: "#3498db"                  // Bordure bleue (même couleur que les boutons)
                border.width: 1                          // Épaisseur de bordure: 1px
                radius: 10                               // Coins arrondis: 10px
            }

            // STYLE DU TEXTE AFFICHÉ
            contentItem: Text {
                text: parent.displayText                 // Texte affiché (ex: "2 enfants")
                color: "#3498db"                         // Couleur bleue (cohérente avec les boutons)
                font.pixelSize: 14                       // Taille police: plus petite car texte plus long
                font.bold: true                          // Police en gras
                verticalAlignment: Text.AlignVCenter     // Alignement vertical centré
                horizontalAlignment: Text.AlignHCenter   // Alignement horizontal centré
            }

            // GESTIONNAIRE D'ÉVÉNEMENT - Quand l'utilisateur change la sélection
            onCurrentIndexChanged: {
                var selectedCount = currentIndex + 1     // Conversion index (0-8) vers nombre (1-9)
                console.log("Nombre d'enfants sélectionné:", selectedCount)

                // ÉMISSION DES SIGNAUX vers les composants parents
                grid.pensionCalculationRequested("children", "selected", selectedCount)  // Signal existant
                grid.childrenCountChanged(selectedCount) // NOUVEAU: Signal spécifique pour CalculatorLogic
            }
        }
    }
}
