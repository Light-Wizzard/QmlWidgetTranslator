# QmlWidgetTranslator

Qml Widget Translator es un proyecto de plantilla para QML y QtWidgets.

El concepto es simple, quería un Qt Temple que pudiera usarse para muchos sistemas operativos,
además de las restricciones, lo necesitaba para trabajar con SQL y sin él,
con Local Storage y sin él,
pero no quería escribir una aplicación de widget QML o Qt en C ++,
y todas las variaciones con las que tengo que lidiar,
por lo que esta plantilla está diseñada para solucionar todos estos problemas.

Yo uso cmake pero el archivo qmake es obligatorio si quieres usarlo para archivos de traducción,
Aparte de eso, solo uso el archivo cmake, y encontrará precomipler define para muchas cosas como:

* MY_QML: cuando trabaje en QML, configúrelo en ON, si el modo QWidget lo configuró en OFF
* USE_SQL_FLAG: si desea usar SQL, configure en ON, si desea hacer WebAssembly y necesita desactivar SQL y el almacenamiento local, configúrelo en OFF.
* MY_INTERNET_CHECK_PING: se usa si su aplicación necesita verificaciones de acceso a Internet
* DO_LUPDATE: Actualización de traducción
* DO_LRELEASE: Traducción lrelease
* MY_TS_FILES: Traducción de archivos TS
* MY_QM_FILES: Traducción de archivos QM
* HEADERS: Archivos de encabezado
* PROJECT_APP_HEADER: archivos de encabezado QWidget
* PROJECT_SOURCES: archivos de origen
* PROJECT_UI: archivos de IU de QWidget
* PROJECT_APP_SOURCE: archivos de origen QWidget
* ANDROID: Modo Andrid
* MY_URL: para Mac Bundle

Actualmente estoy trabajando en todas las características para Qt Widgets en C ++, así que tengo MY_QML desactivado,
Actualmente QML no tiene las características que tiene QWidget,
pero planeo cambiar de marcha y activar MY_QML y hacer el mismo conjunto de funciones.

# Doxygen

Yo uso Doxygen, puedes ejecutarlo desde los siguientes comandos.

`` bash
doxygen Doxyfile

o

doxywizard
''

Tengo documentos de Doxygen en docs.



## Estado

[! [Estado de compilación de Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

##: paquete: ** Descargas: **

-: pingüino: [Linux] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
-: oficina: [Windows zip exe] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
-: manzana: [Apple] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (probado en 7 y 10, avíseme si 8 funciona): descargue zip y extráigalo, y ejecute el archivo QmlWidgetTranslator.exe dentro de la carpeta de implementación.

# Sobre el Autor

Todos mis libros son gratuitos en línea en http://LightWizzard.com, pero cuesta dinero imprimirlos o enviar ePubs a su dispositivo.

No estoy publicando mis libros aquí, puede leerlos gratis en mi
[Cuenta de Github Light-Wizzard / The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
pero tienes que pagar por los libros impresos, o la facilidad de recibir un ePub a través de tu dispositivo ePub Reader, sin tener que descargarlo.

Libro impreso y ePub disponibles en:

Lulú
*: libro:: computadora: http://www.lulu.com/spotlight/LightWizzard

Amazonas
*: libro: Libro https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: computadora: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## El progreso del desarrollo

Si no ve su sistema operativo, simplemente descárguelo, extráigalo a una carpeta y ábralo con Qt Creator,
que debe estar instalado y compilarlo o ejecutarlo.


Fin de README.md