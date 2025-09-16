import QtQuick

Column {
    id: paGrid
    spacing: 15  // Espacement augmenté
    anchors.horizontalCenter: parent.horizontalCenter

    // Signaux exposés vers le parent
    signal buttonClicked(string text, string type)
    signal pensionCalculationRequested(string type, string mode, int children)

    // État interne
    property int selectedChildren: 1

    // Ligne 1 : Clear et sélecteur d'enfants - bien en dessous de l'écran
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15  // Plus d'espacement entre C et le sélecteur

        CalculatorButton {
            buttonText: "C"
            buttonType: "action"
            buttonColor: "#e74c3c"
            onButtonClicked: function(text, type) {
                paGrid.buttonClicked(text, type)
            }
        }

        ChildrenSelector {
            id: childrenSelector
            onChildrenChanged: function(count) {
                selectedChildren = count
                console.log("Nombre d'enfants sélectionné:", count)
            }
        }
    }

    // Lignes de chiffres 7-9, 4-6, 1-3
    Grid {
        columns: 3
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        // Génération des boutons chiffres avec Repeater
        Repeater {
            model: ["7","8","9","4","5","6","1","2","3"]

            CalculatorButton {
                buttonText: modelData
                buttonType: "number"
                onButtonClicked: function(text, type) {
                    paGrid.buttonClicked(text, type)
                }
            }
        }
    }

    // Ligne : 0 et point décimal
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        CalculatorButton {
            buttonText: "0"
            buttonType: "number"
            onButtonClicked: function(text, type) {
                paGrid.buttonClicked(text, type)
            }
        }

        CalculatorButton {
            buttonText: "."
            buttonType: "number"
            onButtonClicked: function(text, type) {
                paGrid.buttonClicked(text, type)
            }
        }
    }

    // Boutons de calcul PA
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        PensionButton {
            pensionType: "PA1"
            pensionMode: "Classique"
            buttonColor: "#f39c12"
            childrenCount: selectedChildren

            onPensionClicked: function(type, mode, children) {
                paGrid.pensionCalculationRequested(type, mode, children)
            }
        }

        PensionButton {
            pensionType: "PA2"
            pensionMode: "Alternée"
            buttonColor: "#9b59b6"
            childrenCount: selectedChildren

            onPensionClicked: function(type, mode, children) {
                paGrid.pensionCalculationRequested(type, mode, children)
            }
        }

        PensionButton {
            pensionType: "PA3"
            pensionMode: "Réduite"
            buttonColor: "#e74c3c"
            childrenCount: selectedChildren

            onPensionClicked: function(type, mode, children) {
                paGrid.pensionCalculationRequested(type, mode, children)
            }
        }
    }
}
