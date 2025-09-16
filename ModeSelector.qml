import QtQuick
import QtQuick.Controls

ComboBox {
    id: modeSelector
    width: 180
    height: 40

    // Signal émis quand le mode change
    signal modeChanged(int mode)

    // Liste des modes disponibles
    model: ["Calculatrice", "Pension Alimentaire"]

    // Style du dropdown
    background: Rectangle {
        color: "transparent"
        border.color: "#3498db"
        border.width: 2
        radius: 10
    }

    // Style du texte
    contentItem: Text {
        text: modeSelector.displayText
        color: "#ffffff"
        font.pixelSize: 14
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        leftPadding: 10
    }

    // Style de la flèche dropdown
    indicator: Text {
        text: "▼"
        color: "#ffffff"
        font.pixelSize: 12
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }

    // Style du popup dropdown
    popup: Popup {
        y: modeSelector.height - 1
        width: modeSelector.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: modeSelector.popup.visible ? modeSelector.delegateModel : null
            currentIndex: modeSelector.highlightedIndex

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
        width: modeSelector.width
        height: 35

        contentItem: Text {
            text: modelData
            color: "#ffffff"
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            leftPadding: 10
        }

        background: Rectangle {
            color: parent.hovered ? "#3498db" : "transparent"
            radius: 3
        }
    }

    // Émettre le signal quand la sélection change
    onCurrentIndexChanged: {
        console.log("Mode changé vers:", currentIndex, currentText)
        modeChanged(currentIndex)
    }
}

