cmake_minimum_required(VERSION 3.16)
# I tried to put stuff you need to exit at the top
project(QmlWidgetTranslator VERSION 0.1.0.0 DESCRIPTION "QmlWidgetTranslator" LANGUAGES C CXX)
# Set this to your URL
set(MY_URL "light-wizzard.github.io")
# ON OFF
set(MY_QML OFF)
# If you have a project that has an SQL verion for Desktops, and No SQL for WebAssempy set to ON OFF
set(USE_SQL_FLAG ON)
# If Check Internet with Ping set to ON otherwise OFF
set(MY_INTERNET_CHECK_PING OFF)
# Set Target Name
set(MY_TARGET ${CMAKE_PROJECT_NAME})
# QML
if(MY_QML)
    add_compile_definitions(MY_QML)
endif()
# SQL
if(USE_SQL_FLAG)
    add_compile_definitions(USE_SQL_FLAG)
endif()
# Check Internet with Ping
if(MY_INTERNET_CHECK_PING)
    add_compile_definitions(MY_INTERNET_CHECK_PING)
endif()
#
if(NOT MY_QML)
    set(PROJECT_UI src/MainWindow.ui)
    set(PROJECT_APP_SOURCE src/MainWindow.cpp)
    set(PROJECT_APP_HEADER src/MainWindow.h)
endif()
# You can turn these ON OFF individually for Translations
option(DO_LUPDATE "Create TS files lupdate, turn off after you created them" ON)
option(DO_LRELEASE "Create QM files lrelease, turn off after you created them" ON)
#
# Include GNUInstallDirs to get canonical paths
include(GNUInstallDirs)
# Set App Version
set(APP_VERSION "0.1.0")
# Set include current directory
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
# Auto
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Define DEBUG
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
# TS Files
set(MY_TS_FILES
    translations/${MY_TARGET}_ar.ts
    translations/${MY_TARGET}_de.ts
    translations/${MY_TARGET}_en.ts
    translations/${MY_TARGET}_es.ts
    translations/${MY_TARGET}_fr.ts
    translations/${MY_TARGET}_it.ts
    translations/${MY_TARGET}_ja.ts
    translations/${MY_TARGET}_no.ts
    translations/${MY_TARGET}_ru.ts
    translations/${MY_TARGET}_sv.ts
    translations/${MY_TARGET}_zh_CN.ts
)
# QM Files
set(MY_QM_FILES
    translations/${MY_TARGET}_ar.qm
    translations/${MY_TARGET}_de.qm
    translations/${MY_TARGET}_en.qm
    translations/${MY_TARGET}_es.qm
    translations/${MY_TARGET}_fr.qm
    translations/${MY_TARGET}_it.qm
    translations/${MY_TARGET}_ja.qm
    translations/${MY_TARGET}_no.qm
    translations/${MY_TARGET}_ru.qm
    translations/${MY_TARGET}_sv.qm
    translations/${MY_TARGET}_zh_CN.qm
)
# Header Files
set(HEADERS
    src/MyLanguageData.h
    src/MyLanguageModel.h
    src/MyOrgSettings.h
    src/MyDatatables.h
    src/SimpleCrypt.h
    ${PROJECT_APP_HEADER}
)
# Source Files
set(PROJECT_SOURCES
    src/main.cpp
    src/MyLanguageData.cpp
    src/MyLanguageModel.cpp
    src/MyOrgSettings.cpp
    src/SimpleCrypt.cpp
    src/MyDatatables.cpp
    ${MY_TARGET}.qrc
    ${MY_TS_FILES}
    ${HEADERS}
    ${PROJECT_UI}
    ${PROJECT_APP_SOURCE}
)
# All Qt includes
#3DAnimation             Help                    QuickWidgets
#3DCore                  LinguistTools           RemoteObjects
#3DExtras                Location                RepParser
#3DInput                 Multimedia              Scxml
#3DLogic                 MultimediaWidgets       Sensors
#3DQuick                 Network                 SerialPort
#3DQuickAnimation        Nfc                     Sql
#3DQuickExtras           OpenGL                  Svg
#3DQuickInput            OpenGLExtensions        Test
#3DQuickRender           Positioning             TextToSpeech
#3DQuickScene2D          PositioningQuick        UiPlugin
#3DRender                PrintSupport            UiTools
#AndroidExtras           Qml                     WebChannel
#Bluetooth               Quick                   WebSockets
#Concurrent              QuickCompiler           WebView
#Core                    QuickControls2          Widgets
#Gamepad                 QuickTemplates2         Xml
#Gui                     QuickTest               XmlPatterns
# Find packages
if(DEFINED USE_SQL_FLAG)
    if(MY_QML)
        # QML
        find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Sql Qml Quick QuickControls2 Network LinguistTools REQUIRED)
        find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Sql Qml Quick QuickControls2 Network LinguistTools REQUIRED)
    else()
        # C++
        find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql Network LinguistTools REQUIRED)
        find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql Network LinguistTools REQUIRED)
    endif()
else()
    if(MY_QML)
        # QML
        find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Qml Quick QuickControls2 Network LinguistTools REQUIRED)
        find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Qml Quick QuickControls2 Network LinguistTools REQUIRED)
    else()
        # C++
        find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Network LinguistTools REQUIRED)
        find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Network LinguistTools REQUIRED)
    endif()
endif()
# The lines below this should not need to be altered from one project to the next
# Set Properties and add executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${MY_TARGET} MANUAL_FINALIZATION ${PROJECT_SOURCES})
    # Define target properties for Android with Qt 6 as:
    set_property(TARGET ${MY_TARGET} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${MY_TS_FILES})
else()
    if(ANDROID)
        add_library(${MY_TARGET} SHARED ${PROJECT_SOURCES})
        # Define properties for Android with Qt 5 after find_package() calls as:
        set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${MY_TARGET} ${PROJECT_SOURCES})
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${MY_TS_FILES})
endif()
# Set Definitions and Library
target_compile_definitions(${MY_TARGET} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
# Libraries
if(DEFINED USE_SQL_FLAG)
    if(MY_QML)
        # QML
        target_link_libraries(${MY_TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2)
    else()
        # C++
        target_link_libraries(${MY_TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)
    endif()
else()
    if(MY_QML)
        # QML
        target_link_libraries(${MY_TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2)
    else()
        # C++
        target_link_libraries(${MY_TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)
    endif()
endif()
# Set Target Properties to include MACOS
set_target_properties(${MY_TARGET} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER ${MY_URL}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/macos/info.plist
)
# genearats ts and qm file searching recursively THIS_RC_DIR
function(generate_translations THIS_CUSTOM_TARGET THIS_TS_DIR THIS_TS_FILES THIS_RC_DIR)
    # lupdate
    if(DO_LUPDATE)
        message(STATUS "run lupdate")
        set(UPADTE_TS_TARGET_NAME ${THIS_CUSTOM_TARGET}_ts)
        add_custom_target(${UPADTE_TS_TARGET_NAME}
            COMMAND ${Qt5_LUPDATE_EXECUTABLE} -recursive ${THIS_RC_DIR} -ts ${THIS_TS_FILES}
            WORKING_DIRECTORY ${THIS_TS_DIR})
    endif()
    # lrelease
    if(DO_LRELEASE)
        message(STATUS "run lrelease")
        set(UPADTE_QM_TARGET_NAME ${THIS_CUSTOM_TARGET}_qm)
        add_custom_target(${UPADTE_QM_TARGET_NAME}
            COMMAND ${Qt5_LRELEASE_EXECUTABLE} ${THIS_TS_FILES}
            WORKING_DIRECTORY ${THIS_TS_DIR})
        add_dependencies(${UPADTE_QM_TARGET_NAME} ${UPADTE_TS_TARGET_NAME} )
        add_dependencies(${THIS_CUSTOM_TARGET} ${UPADTE_QM_TARGET_NAME})
    endif()
endfunction()
# Set variables to pass in
set(MY_TS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MY_SOURCE_LOOKUP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# Generate Tralations
generate_translations(${MY_TARGET} "${MY_TS_DIR}" "${MY_TS_FILES}" "${MY_SOURCE_LOOKUP_DIR}")
# Install QM files if not APPLE
if(UNIX AND NOT APPLE)
    install(FILES ${MY_QM_FILES} DESTINATION ${CMAKE_SOURCE_DIR}/translations)
endif()
# Qt 6 stuff
if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${MY_TARGET})
    qt_finalize_executable(${MY_TARGET})
endif()
# Install Target Destinations
install(TARGETS ${MY_TARGET}
  RUNTIME DESTINATION /usr/bin
  BUNDLE DESTINATION  /usr/bin
  LIBRARY DESTINATION /usr/lib
  ARCHIVE DESTINATION /usr/lib
)
###### End of File ######
