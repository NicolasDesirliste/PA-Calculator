import QtQuick

Item {
    property var calculatorObject  // ← Propriété pour recevoir l'objet calculator

    function processButtonAction(text, type) {
        // Vérification de sécurité
        if (!calculatorObject) {
            console.log("ERREUR: calculatorObject est undefined!")
            return
        }

        if (type === "number") {
            calculatorObject.addNumber(text)
        } else if (type === "operator") {
            calculatorObject.addOperator(text)
        } else if (text === "C") {
            calculatorObject.clear()
        } else if (text === "=") {
            calculatorObject.calculate()
        }
    }
}
