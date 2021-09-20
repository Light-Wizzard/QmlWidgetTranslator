# QmlWidgetTranslator

Qml Widget Translator är ett mallprojekt för både QML och QtWidgets.

Konceptet är enkelt, jag ville ha ett Qt -tempel som kan användas för många operativsystem,
liksom begränsningar, jag behövde det för att fungera med SQL och utan det,
med lokal lagring och utan det,
men jag ville inte skriva ett QML- eller Qt -widgetprogram i C ++,
och alla variationer jag måste hantera,
så den här mallen är utformad för att kringgå alla dessa frågor.

Jag använder cmake men qmake -filen regregeras om du vill använda den för översättningsfiler,
annat än det använder jag bara cmake -filen, och du hittar precomipler definierar för många saker som:

* MY_QML: När du arbetar i QML, ställ in detta till ON, om QWidget -läget ställer det till OFF
* USE_SQL_FLAG: Om du vill använda SQL set ON, om du vill göra WebAssemble och måste stänga av SQL och Local Storage, ställ in på OFF.
* MY_INTERNET_CHECK_PING: Används om din applikation behöver Internetåtkomstkontroller
* DO_LUPDATE: Översättning lupdate
* DO_LRELEASE: Översättning av version
* MY_TS_FILES: Översättning av TS -filer
* MY_QM_FILES: Översättning av QM -filer
* Rubriker: Rubrikfiler
* PROJECT_APP_HEADER: QWidget Header -filer
* PROJECT_SOURCES: Källfiler
* PROJECT_UI: QWidget UI -filer
* PROJECT_APP_SOURCE: QWidget -källfiler
* ANDROID: Andrid -läge
* MY_URL: för Mac -paket

Jag arbetar för närvarande med alla funktioner för Qt -widgets i C ++, så jag har MY_QML avstängd,
för närvarande har QML inte de funktioner QWidget har,
men jag planerar att växla och ställa in MY_QML PÅ och göra samma uppsättning funktioner.

# Doxygen

Jag använder Doxygen, du kan köra den från kommandona nedan.

'' bash
doxygen Doxyfile

eller

doxywizard
''

Jag har Doxygen Documents under docs.



## Status

[! [Status för Appveyor Build] [https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true]] (https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

##: paket: ** Nedladdningar: **

-: penguin: [Linux] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
-: office: [Windows zip exe] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
-: apple: [Apple] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (Testat på 7 och 10 meddela mig om 8 fungerar): Ladda ner zip och extrahera det och kör filen QmlWidgetTranslator.exe inuti distributionsmappen.

# Om författaren

Alla mina böcker är gratis online på http://LightWizzard.com, men det kostar pengar att skriva ut dem eller skjuta ePubs till din enhet.

Jag publicerar inte mina böcker här, du kan läsa dem gratis på min
[Github-konto Light-Wizzard/The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
men du måste betala för tryckta böcker, eller enkelt för att få en ePub levererad via dina ePub -läsare utan att behöva ladda ner den.

Tryckt bok och ePub Finns på:

Lulu
*: bok:: dator: http://www.lulu.com/spotlight/LightWizzard

Amazon
*: bok: Boka https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: dator: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Utvecklingsframsteg

Om du inte ser ditt operativsystem, bara ladda ner, extrahera till en mapp och öppna med Qt Creator,
som måste installeras och kompileras eller köras.


Slut på README.md