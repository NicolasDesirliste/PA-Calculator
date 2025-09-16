import QtQuick

Column {
    property var calculatorInstance
    property int currentMode: 0  // 0 = Calculatrice normale, 1 = Pension Alimentaire

    anchors.fill: parent
    anchors.margins: 20
    spacing: 20

    CalculatorDisplay {
        id: displayText
    }

    CalculatorLogic {
        id: calculatorLogic
        calculatorObject: calculatorInstance
    }

    // Grille qui change selon le mode
    Item {
        width: parent.width
        height: 380  // Hauteur augmentée pour éviter le débordement

        // Grille calculatrice normale
        CalculatorGrid {
            id: normalGrid
            visible: currentMode === 0
            anchors.centerIn: parent

            onButtonClicked: function(text, type) {
                calculatorLogic.processButtonAction(text, type)
            }
        }

        // Grille pension alimentaire
        CalculatorGridPA {
            id: paGrid
            visible: currentMode === 1
            anchors.centerIn: parent
            anchors.topMargin: 20  // Marge supplémentaire en haut

            onButtonClicked: function(text, type) {
                calculatorLogic.processButtonAction(text, type)
            }

            onPensionCalculationRequested: function(type, mode, children) {
                console.log("Calcul PA demandé:", type, mode, "pour", children, "enfants")
                // TODO: Appeler la logique C++ de calcul de pension
            }
        }
    }

    // Espacement supplémentaire avant le sélecteur
    Item {
        height: 30  // Plus d'espace pour éviter que le sélecteur soit collé aux boutons PA
    }

    // Sélecteur de mode en bas
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        ModeSelector {
            id: modeSelector

            onModeChanged: function(mode) {
                currentMode = mode
                console.log("Mode changé vers:", mode === 0 ? "Calculatrice" : "Pension Alimentaire")
            }
        }
    }
}
