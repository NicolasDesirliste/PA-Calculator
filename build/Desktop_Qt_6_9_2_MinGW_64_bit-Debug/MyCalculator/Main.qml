import QtQuick

CalculatorWindow {
}

/*
import QtQuick.Controls

Window {
    width: 600
    height: 600
    visible: true
    title: "My Calculator"
    color: "#2c3e50"

    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        // ÉCRAN D'AFFICHAGE
        Rectangle {
            width: parent.width
            height: 80
            color: "#34495e"
            radius: 10

            Text {
                id: displayText
                anchors.centerIn: parent
                text: calculator.getDisplay()
                font.pixelSize: 36
                color: "white"
                font.bold: true
            }
        }

        // LOGIQUE MÉTIER
        CalculatorLogic {
            id: calculatorLogic
        }

        // GRILLE DE BOUTONS
        CalculatorGrid {
            onButtonClicked: function(text, type) {
                calculatorLogic.processButtonAction(text, type)
            }
        }
    }
}
*/
