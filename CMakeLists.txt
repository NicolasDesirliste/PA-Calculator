cmake_minimum_required(VERSION 3.16)

project(MyCalculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appMyCalculator
    main.cpp
)

qt_add_qml_module(appMyCalculator
    URI MyCalculator
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES
        SOURCES Calculator.h Calculator.cpp
        SOURCES ExpressionEvaluator.h
        SOURCES ExpressionEvaluator.cpp
        QML_FILES CalculatorDisplay.qml
        QML_FILES CalculatorButton.qml
        QML_FILES CalculatorLogic.qml
        QML_FILES CalculatorGrid.qml
        QML_FILES CalculatorWindow.qml
        QML_FILES CalculatorLayout.qml
        SOURCES Tokenizer.h
        SOURCES ArithmeticCalculator.h
        SOURCES ExpressionParser.h
        SOURCES ErrorHandler.h
        SOURCES Tokenizer.cpp
        SOURCES ArithmeticCalculator.cpp
        SOURCES ErrorHandler.cpp
        SOURCES ExpressionParser.cpp
        QML_FILES ModeSelector.qml
        QML_FILES
        QML_FILES ChildrenSelector.qml
        QML_FILES PensionButton.qml
        QML_FILES CalculatorGridPA.qml
        SOURCES PensionCalculator.cpp
        SOURCES PensionCalculator.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMyCalculator PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMyCalculator
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMyCalculator
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMyCalculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
