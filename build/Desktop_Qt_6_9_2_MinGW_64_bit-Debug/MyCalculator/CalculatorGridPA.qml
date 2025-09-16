import QtQuick
import QtQuick.Controls

Column {
    // PROPRIÉTÉS DE LA GRILLE
    id: grid
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter
    // SIGNAUX EXPOSÉS - Propagés vers le parent
    signal buttonClicked(string text, string type)
    signal pensionCalculationRequested(string type, string mode, int children)

    // Ligne 1
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        CalculatorButton { buttonText: "C"; buttonType: "action"; buttonColor: "#e74c3c"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "R"; buttonType: "action"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "%"; buttonType: "operator"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "PA1"; buttonType: "pensionOperator"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
    }

    // Ligne 2
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        CalculatorButton { buttonText: "7"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "8"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "9"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "PA2"; buttonType: "pensionOperator"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
    }

    // Ligne 3
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        CalculatorButton { buttonText: "4"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "5"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "6"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "PA3"; buttonType: "pensionOperator"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
    }

    // Ligne 4
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        CalculatorButton { buttonText: "1"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "2"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "3"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "+"; buttonType: "operator"; buttonColor: "#f39c12"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
    }

    // Ligne 5 - Avec ComboBox pour nombre d'enfants
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        CalculatorButton { buttonText: "0"; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }
        CalculatorButton { buttonText: "."; buttonType: "number"; buttonColor: "#95a5a6"; onButtonClicked: function(text, type) { grid.buttonClicked(text, type) } }

        // ComboBox pour sélectionner le nombre d'enfants
        ComboBox {
            width: 130
            height: 60

            // Modèle avec nombres de 1 à 9
            model: ["1 enfant", "2 enfants", "3 enfants", "4 enfants", "5 enfants",
                    "6 enfants", "7 enfants", "8 enfants", "9 enfants"]

            currentIndex: 0  // Par défaut : 1 enfant

            // Style cohérent avec vos boutons
            background: Rectangle {
                color: "transparent"
                border.color: "#3498db"
                border.width: 1
                radius: 10
            }

            contentItem: Text {
                text: parent.displayText
                color: "#3498db"
                font.pixelSize: 14
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            // Signal quand la sélection change
            onCurrentIndexChanged: {
                console.log("Nombre d'enfants sélectionné:", currentIndex + 1)
                // Émettre le signal avec le nombre d'enfants
                grid.pensionCalculationRequested("children", "selected", currentIndex + 1)
            }
        }
    }
}
