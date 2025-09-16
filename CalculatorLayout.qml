import QtQuick

Column {
    property var calculatorInstance

    anchors.fill: parent
    anchors.margins: 20
    spacing: 20

    Component.onCompleted: {
        console.log("CalculatorLayout - calculatorInstance reçu:", calculatorInstance)
        console.log("CalculatorLayout - typeof calculatorInstance:", typeof calculatorInstance)
    }

    CalculatorDisplay {
        id: displayText
    }

    CalculatorLogic {
        id: calculatorLogic
        calculatorObject: calculatorInstance

        Component.onCompleted: {
            console.log("CalculatorLogic - calculatorObject reçu:", calculatorObject)
        }
    }

    CalculatorGrid {
        onButtonClicked: function(text, type) {
            calculatorLogic.processButtonAction(text, type)
        }
    }
}
