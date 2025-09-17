import QtQuick

Item {
    property var calculatorObject
    property int selectedChildren: 1  // Nombre d'enfants sélectionné
    property double revenuDebiteur: 0.0
    property double revenuCreancier: 0.0

    function processButtonAction(text, type) {
        if (!calculatorObject) {
            console.log("ERREUR: calculatorObject est undefined!")
            return
        }

        if (type === "number") {
            calculatorObject.addNumber(text)
        } else if (type === "operator") {
            calculatorObject.addOperator(text)
        } else if (type === "pensionOperator") {
            // Gestion des boutons PA1, PA2, PA3
            handlePensionCalculation(text)
        } else if (text === "C") {
            calculatorObject.clear()
        } else if (text === "R") {
            // Return/Reset pour pension alimentaire
            resetPensionValues()
        } else if (text === "=") {
            calculatorObject.calculate()
        }
    }

    // Fonction appelée quand le ComboBox change
    function updateChildrenCount(count) {
        selectedChildren = count
        console.log("Nombre d'enfants mis à jour:", selectedChildren)
    }

    // Gestion des calculs de pension alimentaire
    function handlePensionCalculation(paType) {
        // Récupérer la valeur actuellement affichée comme revenu
        var displayValue = calculatorObject.getDisplay()
        var currentValue = parseFloat(displayValue)

        if (isNaN(currentValue) || currentValue <= 0) {
            console.log("ERREUR: Veuillez saisir un revenu valide")
            calculatorObject.clear()
            calculatorObject.addNumber("ERREUR")
            return
        }

        console.log("Calcul pension alimentaire:", paType)
        console.log("Revenu saisi:", currentValue)
        console.log("Nombre d'enfants:", selectedChildren)

        if (paType === "PA1") {
            // PA1 - Garde classique : besoin seulement du revenu débiteur
            pensionCalculator.calculerPA1(currentValue, selectedChildren)
        } else if (paType === "PA2") {
            // PA2 - Garde alternée : besoin des deux revenus
            handlePA2Calculation(currentValue)
        } else if (paType === "PA3") {
            // PA3 - Garde réduite : besoin seulement du revenu débiteur
            pensionCalculator.calculerPA3(currentValue, selectedChildren)
        }
    }

    // Gestion spéciale pour PA2 qui nécessite 2 revenus
    function handlePA2Calculation(firstRevenu) {
        if (revenuDebiteur === 0.0) {
            // Premier revenu (débiteur)
            revenuDebiteur = firstRevenu
            calculatorObject.clear()
            calculatorObject.addNumber("Revenu 2?")
            console.log("PA2 - Revenu débiteur enregistré:", revenuDebiteur, "- Saisissez le revenu créancier")
        } else {
            // Deuxième revenu (créancier)
            revenuCreancier = firstRevenu
            console.log("PA2 - Calcul avec:", revenuDebiteur, "vs", revenuCreancier)
            pensionCalculator.calculerPA2(revenuDebiteur, revenuCreancier, selectedChildren)

            // Reset pour prochaine utilisation
            revenuDebiteur = 0.0
            revenuCreancier = 0.0
        }
    }

    // Reset des valeurs pension alimentaire
    function resetPensionValues() {
        revenuDebiteur = 0.0
        revenuCreancier = 0.0
        calculatorObject.clear()
        console.log("Valeurs pension alimentaire réinitialisées")
    }

    // Connexion aux signaux de PensionCalculator
    Connections {
        target: pensionCalculator

        function onCalculTermine(montant, details) {
            console.log("Résultat PA:", montant, "€")
            console.log("Détails:", details)

            // Afficher le résultat dans la calculatrice
            calculatorObject.clear()
            calculatorObject.addNumber(montant.toFixed(2).toString())
        }
    }
}

/*
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
*/
