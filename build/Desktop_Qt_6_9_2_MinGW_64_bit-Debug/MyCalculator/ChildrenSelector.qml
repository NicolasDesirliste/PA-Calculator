import QtQuick
import QtQuick.Controls

ComboBox {
    id: childrenSelector
    width: 120
    height: 60

    // Propriété exposée pour récupérer le nombre sélectionné
    property int selectedChildren: currentIndex + 1

    // Signal émis quand la sélection change
    signal childrenChanged(int count)

    // Génération automatique du modèle 1-20
    model: {
        var children = []
        for (var i = 1; i <= 20; i++) {
            children.push(i + (i === 1 ? " enfant" : " enfants"))
        }
        return children
    }

    currentIndex: 0  // Par défaut : 1 enfant

    // Style cohérent avec les boutons de la calculatrice
    background: Rectangle {
        color: "transparent"
        border.color: "#3498db"
        border.width: 2
        radius: 10
    }

    contentItem: Text {
        text: childrenSelector.displayText
        color: "#ffffff"
        font.pixelSize: 16
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    // Style du popup dropdown
    popup: Popup {
        y: childrenSelector.height - 1
        width: childrenSelector.width
        implicitHeight: Math.min(contentItem.implicitHeight, 300)
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: childrenSelector.popup.visible ? childrenSelector.delegateModel : null
            currentIndex: childrenSelector.highlightedIndex

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle {
            color: "#34495e"
            border.color: "#3498db"
            border.width: 1
            radius: 5
        }
    }

    // Style des éléments de la liste
    delegate: ItemDelegate {
        width: childrenSelector.width
        height: 35

        contentItem: Text {
            text: modelData
            color: "#ffffff"
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        background: Rectangle {
            color: parent.hovered ? "#3498db" : "transparent"
            radius: 3
        }
    }

    // Émettre le signal quand la sélection change
    onCurrentIndexChanged: {
        childrenChanged(selectedChildren)
    }
}
