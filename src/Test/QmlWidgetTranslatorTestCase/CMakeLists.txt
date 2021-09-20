cmake_minimum_required(VERSION 3.5)

project(QmlWidgetTranslatorTestCase LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql Qml Quick QuickControls2 PrintSupport Network Multimedia Concurrent LinguistTools Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql Qml Quick QuickControls2 PrintSupport Network Multimedia Concurrent LinguistTools Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

set(PROJECT_UI ../../MainWindow.ui)
set(PROJECT_APP_SOURCE ../../MainWindow.cpp)
set(PROJECT_APP_HEADER ../../MainWindow.h)
# TS Files
set(MY_TS_FILES
    ../../../translations/QmlWidgetTranslator_ar.ts
    ../../../translations/QmlWidgetTranslator_de.ts
    ../../../translations/QmlWidgetTranslator_en.ts
    ../../../translations/QmlWidgetTranslator_es.ts
    ../../../translations/QmlWidgetTranslator_fr.ts
    ../../../translations/QmlWidgetTranslator_it.ts
    ../../../translations/QmlWidgetTranslator_ja.ts
    ../../../translations/QmlWidgetTranslator_no.ts
    ../../../translations/QmlWidgetTranslator_ru.ts
    ../../../translations/QmlWidgetTranslator_sv.ts
    ../../../translations/QmlWidgetTranslator_zh_CN.ts
)
# QM Files
set(MY_QM_FILES
    ../../../translations/QmlWidgetTranslator_ar.qm
    ../../../translations/QmlWidgetTranslator_de.qm
    ../../../translations/QmlWidgetTranslator_en.qm
    ../../../translations/QmlWidgetTranslator_es.qm
    ../../../translations/QmlWidgetTranslator_fr.qm
    ../../../translations/QmlWidgetTranslator_it.qm
    ../../../translations/QmlWidgetTranslator_ja.qm
    ../../../translations/QmlWidgetTranslator_no.qm
    ../../../translations/QmlWidgetTranslator_ru.qm
    ../../../translations/QmlWidgetTranslator_sv.qm
    ../../../translations/QmlWidgetTranslator_zh_CN.qm
)
# Header Files
set(HEADERS
    ../../MyLanguageData.h
    ../../MyLanguageModel.h
    ../../MyOrgSettings.h
    ../../MyDatatables.h
    ../../SimpleCrypt.h
    ${PROJECT_APP_HEADER}
)
# Source Files
set(PROJECT_SOURCES
    #../../main.cpp
    ../../MyLanguageData.cpp
    ../../MyLanguageModel.cpp
    ../../MyOrgSettings.cpp
    ../../SimpleCrypt.cpp
    ../../MyDatatables.cpp
    ../../../QmlWidgetTranslator.qrc
    #${MY_TS_FILES}
    ${HEADERS}
    ${PROJECT_UI}
    ${PROJECT_APP_SOURCE}
    tst_qmlwidgettranslatortestcase.cpp
)

add_executable(QmlWidgetTranslatorTestCase ${PROJECT_SOURCES})
add_test(NAME QmlWidgetTranslatorTestCase COMMAND QmlWidgetTranslatorTestCase)

target_link_libraries(QmlWidgetTranslatorTestCase PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::PrintSupport Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2 Qt${QT_VERSION_MAJOR}::Test)

