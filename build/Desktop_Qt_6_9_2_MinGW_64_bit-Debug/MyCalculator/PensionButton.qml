import QtQuick
import QtQuick.Controls

Button {
    id: pensionButton

    // Propriétés configurables
    property string pensionType: ""        // PA1, PA2, PA3
    property string pensionMode: ""        // Classique, Alternée, Réduite
    property string buttonColor: "#f39c12" // Couleur du bouton
    property int childrenCount: 1          // Nombre d'enfants

    // Signal personnalisé avec données structurées
    signal pensionClicked(string type, string mode, int children)

    // Dimensions
    width: 80
    height: 60

    // Style du bouton
    background: Rectangle {
        color: "transparent"
        border.color: pensionButton.buttonColor
        border.width: 2
        radius: 10

        // Effet au survol
        Rectangle {
            anchors.fill: parent
            color: pensionButton.buttonColor
            opacity: parent.parent.hovered ? 0.2 : 0
            radius: 10

            Behavior on opacity {
                NumberAnimation { duration: 150 }
            }
        }
    }

    // Contenu du bouton : nom + description
    contentItem: Column {
        anchors.centerIn: parent
        spacing: 2

        Text {
            text: pensionType
            color: pensionButton.buttonColor
            font.pixelSize: 14
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            text: pensionMode
            color: "#ffffff"
            font.pixelSize: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    // Gestion du clic
    onClicked: {
        console.log("PensionButton clicked:", pensionType, pensionMode, "pour", childrenCount, "enfant(s)")
        pensionClicked(pensionType, pensionMode, childrenCount)
    }
}
