# QmlWidgetÜbersetzer

Qml Widget Translator ist ein Vorlagenprojekt für QML und QtWidgets.

Das Konzept ist einfach, ich wollte einen Qt-Tempel, der für viele Betriebssysteme verwendet werden kann,
sowie Einschränkungen, ich brauchte es, um mit SQL zu arbeiten und ohne,
mit lokalem Speicher und ohne,
aber ich wollte keine QML- oder Qt-Widget-Anwendung in C++ schreiben,
und all die Variationen, mit denen ich zu tun habe,
Daher wurde diese Vorlage entwickelt, um all diese Probleme zu umgehen.

Ich verwende cmake, aber die qmake-Datei ist erforderlich, wenn Sie sie für Übersetzungsdateien verwenden möchten.
Ansonsten verwende ich nur die cmake-Datei, und Sie finden Precomipler-Definitionen für viele Dinge wie:

* MY_QML: Wenn Sie in QML arbeiten, setzen Sie dies auf ON, im QWidget-Modus auf OFF
* USE_SQL_FLAG: Wenn Sie SQL verwenden möchten, setzen Sie ON, wenn Sie WebAssembly erstellen möchten und SQL und Local Storage deaktivieren müssen, setzen Sie diese auf OFF.
* MY_INTERNET_CHECK_PING: Wird verwendet, wenn Ihre Anwendung Internetzugriffsprüfungen benötigt
* DO_LUPDATE: Übersetzung lupdate
* DO_LRELEASE: Übersetzung lrelease
* MY_TS_FILES: Übersetzung von TS-Dateien
* MY_QM_FILES: Übersetzungs-QM-Dateien
* HEADERS: Header-Dateien
* PROJECT_APP_HEADER: QWidget-Header-Dateien
* PROJECT_SOURCES: Quelldateien
* PROJECT_UI: QWidget-UI-Dateien
* PROJECT_APP_SOURCE: QWidget-Quelldateien
* ANDROID: Android-Modus
* MY_URL: für Mac-Bundle

Ich arbeite derzeit an allen Funktionen für Qt-Widgets in C++, also habe ich MY_QML deaktiviert.
QML verfügt derzeit nicht über die Funktionen des QWidget,
aber ich plane, den Gang zu wechseln und MY_QML auf ON zu setzen und die gleichen Funktionen zu erstellen.

# Sauerstoff

Ich verwende Doxygen, Sie können es mit den folgenden Befehlen ausführen.

```bash
Doxygen Doxyfile

oder

Doxymagier
```

Ich habe Doxygen-Dokumente unter docs.



##Status

[![Appveyor-Build-Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

## :Paket: **Downloads:**

- :pinguin: [Linux](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
- :office: [Windows zip exe](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
- :apple: [Apple](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (auf 7 und 10 getestet, lassen Sie mich wissen, ob 8 funktioniert): Laden Sie die ZIP-Datei herunter, entpacken Sie sie und führen Sie die Datei QmlWidgetTranslator.exe im Bereitstellungsordner aus.

# Über den Autor

Alle meine Bücher sind kostenlos online unter http://LightWizzard.com erhältlich, aber es kostet Geld, sie auszudrucken oder ePubs auf Ihr Gerät zu übertragen.

Ich veröffentliche meine Bücher hier nicht, Sie können sie kostenlos auf meinem lesen
[Github-Account Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
Sie müssen jedoch für gedruckte Bücher bezahlen oder sich ein ePub über den ePub-Reader Ihres Geräts liefern lassen, ohne es herunterladen zu müssen.

Gedrucktes Buch und ePub Erhältlich bei:

Lulu
* :Buch: :Computer: http://www.lulu.com/spotlight/LightWizzard

Amazonas
* :Buch: Buch https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :Computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Entwicklungsfortschritt

Wenn Sie Ihr Betriebssystem nicht sehen, laden Sie es einfach herunter, extrahieren Sie es in einen Ordner und öffnen Sie es mit Qt Creator.
die installiert werden muss, und kompilieren oder ausführen.


Ende von README.md