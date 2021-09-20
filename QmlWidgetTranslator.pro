TARGET = QmlWidgetTranslator
QT += quick
CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/MyLanguageData.cpp \
    src/MyLanguageModel.cpp \
    src/MyOrgSettings.cpp \
    src/SimpleCrypt.cpp \
    src/MyDatatables.cpp

HEADERS += \
    src/MyLanguageData.h \
    src/MyLanguageModel.h \
    src/MyOrgSettings.h \
    src/MyDatatables.h \
    src/SimpleCrypt.h

RESOURCES += QmlWidgetTranslator.qrc

# Translations
#
CONFIG += localize_deployment
SYMBIAN_SUPPORTED_LANGUAGES += zh_CN
SYMBIAN_LANG.zh_CN = 31
CONFIG += lrelease
CONFIG += embed_translations
LRELEASE_DIR=./translations
QM_FILES_RESOURCE_PREFIX=./translations
# ar,de,en,es,fr,it,ja,no,ru,sv,zh_CN
TRANSLATIONS += translations/QmlWidgetTranslator_ar.ts \
                translations/QmlWidgetTranslator_de.ts \
                translations/QmlWidgetTranslator_en.ts \
                translations/QmlWidgetTranslator_es.ts \
                translations/QmlWidgetTranslator_fr.ts \
                translations/QmlWidgetTranslator_it.ts \
                translations/QmlWidgetTranslator_ja.ts \
                translations/QmlWidgetTranslator_no.ts \
                translations/QmlWidgetTranslator_ru.ts \
                translations/QmlWidgetTranslator_sv.ts \
                translations/QmlWidgetTranslator_zh_CN.ts

COPY_CONFIG = $$files(*.qm, true)
copy_cmd.input = COPY_CONFIG
copy_cmd.output = ${QMAKE_FILE_IN_BASE}${QMAKE_FILE_EXT}
copy_cmd.commands = $$QMAKE_COPY_DIR ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
copy_cmd.CONFIG += no_link_no_clean
copy_cmd.variable_out = PRE_TARGETDEPS
QMAKE_EXTRA_COMPILERS += copy_cmd 
