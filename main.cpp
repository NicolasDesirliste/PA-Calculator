#include <QGuiApplication>      // Classe principale pour applications GUI Qt sans widgets
#include <QQmlApplicationEngine> // Moteur pour charger et exécuter des fichiers QML
#include <QQmlContext>          // Contexte pour exposer des objets C++ vers QML
#include "Calculator.h"         // Ma classe Calculator personnalisée
#include "PensionCalculator.h"  // Ma classe PensionCalculator personnalisée

int main(int argc, char *argv[])
{
    // Créer l'application Qt avec les arguments de la ligne de commande
    QGuiApplication app(argc, argv);

    // Créer le moteur QML qui va charger mes fichiers .qml
    QQmlApplicationEngine engine;

    // Créer une instance pour la calculatrice normale
    Calculator calculator;

    // Créer une instance pour la calculatrice de pension alimentaire
    PensionCalculator pensionCalculator;

    // Exposer l'objet calculator vers QML sous le nom "calculator"
    // Permet d'utiliser "calculator.addNumber()" dans mes fichiers QML
    engine.rootContext()->setContextProperty("calculator", &calculator);

    // Exposer l'objet pensionCalculator vers QML sous le nom "pensionCalculator"
    // Permet d'utiliser "pensionCalculator.calculerPA1()" dans mes fichiers QML
    engine.rootContext()->setContextProperty("pensionCalculator", &pensionCalculator);

    // Connecter un signal d'erreur : si le QML ne se charge pas, quitter l'app
    QObject::connect(
        &engine,                                    // Objet émetteur
        &QQmlApplicationEngine::objectCreationFailed, // Signal d'échec
        &app,                                       // Objet récepteur
        []() { QCoreApplication::exit(-1); },      // Action : quitter avec code d'erreur
        Qt::QueuedConnection);                     // Type de connexion asynchrone

    // Charger le fichier QML principal depuis le module "MyCalculator"
    engine.loadFromModule("MyCalculator", "Main");

    // Démarrer la boucle d'événements Qt et retourner le code de sortie
    return app.exec();
}
