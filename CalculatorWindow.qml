import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 600
    height: 600
    visible: true
    title: "PA Calculator"

    // FOND AVEC GRADIENT ET EFFETS
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop { position: 0.0; color: "#1e3a5f" }
            GradientStop { position: 0.7; color: "#0f1e2e" }
            GradientStop { position: 1.0; color: "#020408" }
        }

        // GRILLE DE LIGNES (TEXTURE)
        Canvas {
            anchors.fill: parent
            opacity: 0.3
            onPaint: {
                var ctx = getContext("2d")
                ctx.strokeStyle = "#000000"
                ctx.lineWidth = 1
                // Lignes verticales
                for (var x = 0; x < width; x += 10) {
                    ctx.beginPath()
                    ctx.moveTo(x, 0)
                    ctx.lineTo(x, height)
                    ctx.stroke()
                }
                // Lignes horizontales
                for (var y = 0; y < height; y += 10) {
                    ctx.beginPath()
                    ctx.moveTo(0, y)
                    ctx.lineTo(width, y)
                    ctx.stroke()
                }
            }
        }

        // EFFET DE BRILLANCE
        Rectangle {
            id: glareEffect
            width: 200
            height: 6000
            y: 0
            visible: false
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: 0.0; color: "transparent" }
                GradientStop { position: 0.5; color: "#b2dcf1" }
                GradientStop { position: 1.0; color: "transparent" }
            }
            transform: Rotation {
                angle: 25
                origin.x: 100
                origin.y: height/2
            }
        }

        // TIMER POUR L'EFFET DE BRILLANCE
        Timer {
            id: glareTimer
            interval: 12000  // 15 secondes par passages.
            running: true
            repeat: true
            onTriggered: {
                glareEffect.x = -glareEffect.width - 200
                glareEffect.y = -4000
                glareEffect.visible = true
                glareAnimation.start()
            }
        }

        // ANIMATION DE L'EFFET
        ParallelAnimation {
            id: glareAnimation
            NumberAnimation {
                target: glareEffect
                property: "x"
                to: window.width + glareEffect.width + 200
                duration: 3000
            }
            NumberAnimation {
                target: glareEffect
                property: "y"
                to: window.height + 200
                duration: 7000
            }
            onFinished: {
                glareEffect.visible = false
            }
        }
    }

    // CONTENU DE LA CALCULATRICE
    CalculatorLayout {
        anchors.fill: parent
        calculatorInstance: calculator

        /* Débugg utilisé pour vérifie si l'objet
        calculator est bien disponible quand CalculatorWindow se crée */
        Component.onCompleted: {
            console.log("CalculatorWindow - calculator disponible:", calculator)
            console.log("CalculatorWindow - typeof calculator:", typeof calculator)
        }
    }
}
