// CalculatorButton.qml - Composant bouton réutilisable
import QtQuick
import QtQuick.Controls

Button {
    property string buttonText: ""
    property string buttonType: "number"
    property string buttonColor: "#95a5a6"

    signal buttonClicked(string text, string type)

    text: buttonText
    width: buttonText === "Enfant(s)" ? 120 : 60
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
        color: "#3498db"
        font.pixelSize: 18
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    onClicked: {
        buttonClicked(buttonText, buttonType)
    }
}



