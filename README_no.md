# QmlWidgetTranslator

Qml Widget Translator er et malprosjekt for både QML og QtWidgets.

Konseptet er enkelt, jeg ønsket et Qt -tempel som kan brukes til mange operativsystemer,
så vel som begrensninger, jeg trengte det for å fungere med SQL og uten det,
med lokal lagring og uten den,
men jeg ønsket ikke å skrive et QML- eller Qt -widgetprogram i C ++,
og alle variasjonene jeg må forholde meg til,
så denne malen er designet for å omgå alle disse problemene.

Jeg bruker cmake, men qmake -filen reguires hvis du vil bruke den til oversettelsesfiler,
annet enn det bruker jeg bare cmake -filen, og du finner precomipler -definisjoner for mange ting som:

* MY_QML: Når du arbeider i QML, setter du dette til ON, hvis QWidget -modus setter det til OFF
* USE_SQL_FLAG: Hvis du vil bruke SQL satt PÅ, hvis du vil lage WebAssemble og må slå av SQL og lokal lagring, sett til OFF.
* MY_INTERNET_CHECK_PING: Brukes hvis programmet trenger Internett -tilgangskontroller
* DO_LUPDATE: Oversettelse lupdate
* DO_LRELEASE: Oversettelse av utgivelse
* MY_TS_FILES: Oversettelse av TS -filer
* MY_QM_FILES: Oversettelse av QM -filer
* HEADERS: Header Files
* PROJECT_APP_HEADER: QWidget Header -filer
* PROJECT_SOURCES: Kildefiler
* PROJECT_UI: QWidget UI -filer
* PROJECT_APP_SOURCE: QWidget kildefiler
* ANDROID: Andrid -modus
* MY_URL: for Mac -pakke

Jeg jobber for tiden med alle funksjonene for Qt Widgets i C ++, så jeg har MY_QML av,
for øyeblikket har QML ikke funksjonene QWidget har,
men jeg planlegger å bytte gir og sette MY_QML PÅ og lage det samme settet med funksjoner.

# Doxygen

Jeg bruker Doxygen, du kan kjøre den fra kommandoene nedenfor.

`` bash
doxygen Doxyfile

eller

doxywizard
``

Jeg har Doxygen Documents under docs.



## Status

[! [Status for transportørbygger] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

##: pakke: ** Nedlastinger: **

-: penguin: [Linux] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
-: office: [Windows zip exe] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
-: apple: [Apple] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (Testet på 7 og 10, gi meg beskjed om 8 fungerer): Last ned zip og pakk det ut, og kjør filen QmlWidgetTranslator.exe inne i distribusjonsmappen.

# Om forfatteren

Alle bøkene mine er gratis online på http://LightWizzard.com, men det koster penger å skrive dem ut eller skyve ePubs til enheten din.

Jeg offentliggjør ikke bøkene mine her, du kan lese dem gratis på min
[Github-konto Light-Wizzard/The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
men du må betale for trykte bøker, eller enkelt for å få en ePub levert via ePub Reader på enhetene dine, uten å måtte laste den ned.

Trykt bok og ePub Tilgjengelig på:

Lulu
*: bok:: datamaskin: http://www.lulu.com/spotlight/LightWizzard

Amazon
*: bok: Bestill https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: datamaskin: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Utviklingsfremgang

Hvis du ikke ser operativsystemet, kan du bare laste ned, pakke ut til en mappe og åpne med Qt Creator,
som må installeres, og kompileres eller kjøres.


Slutt på README.md