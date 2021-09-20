#QmlWidgetTranslator

Qml Widget Translator è un progetto modello sia per QML che per QtWidgets.

Il concetto è semplice, volevo un Qt Temple che potesse essere utilizzato per molti sistemi operativi,
oltre alle restrizioni, ne avevo bisogno per funzionare con SQL e senza di essa,
con Local Storage e senza di esso,
ma non volevo scrivere un'applicazione QML o Qt Widget in C++,
e tutte le variazioni con cui ho a che fare,
quindi questo modello è progettato per aggirare tutti questi problemi.

Uso cmake ma il file qmake è richiesto se vuoi usarlo per i file di traduzione,
a parte questo, uso solo il file cmake e troverai le definizioni del precompiler per molte cose come:

* MY_QML: quando si lavora in QML impostarlo su ON, se la modalità QWidget impostarlo su OFF
* USE_SQL_FLAG: se si desidera utilizzare SQL impostato su ON, se si desidera creare WebAssembly e occorre disattivare SQL e Local Storage, impostare su OFF.
* MY_INTERNET_CHECK_PING: utilizzato se la tua applicazione necessita di controlli di accesso a Internet
* DO_LUPDATE: aggiornamento della traduzione
* DO_LRELEASE: Traduzione lrelease
* MY_TS_FILES: Traduzione di file TS
* MY_QM_FILES: Traduzione di file QM
* INTESTAZIONI: file di intestazione
* PROJECT_APP_HEADER: file di intestazione QWidget
* PROJECT_SOURCES: file sorgente
* PROJECT_UI: file dell'interfaccia utente di QWidget
* PROJECT_APP_SOURCE: file sorgente QWidget
* ANDROID: Modalità Andrid
* MY_URL: per Mac Bundle

Attualmente sto lavorando su tutte le funzionalità per i widget Qt in C++, quindi ho disattivato MY_QML,
attualmente QML non ha le funzionalità di QWidget,
ma ho intenzione di cambiare marcia e impostare MY_QML ON e creare lo stesso set di funzionalità.

# Doxygen

Uso Doxygen, puoi eseguirlo dai comandi seguenti.

```bash
doxygen Doxyfile

o

doxywizard
```

Ho documenti Doxygen sotto docs.



## Stato

[![Stato build Appveyor](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

## :pacchetto: **Download:**

- :penguin: [Linux](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
- :office: [Windows zip exe](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
- :apple: [Apple](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (testato su 7 e 10 fammi sapere se 8 funziona): scarica zip ed estrailo ed esegui il file QmlWidgetTranslator.exe all'interno della cartella di distribuzione.

# Circa l'autore

Tutti i miei libri sono gratuiti online su http://LightWizzard.com, ma è costoso stamparli o inviare ePub al tuo dispositivo.

Non pubblico i miei libri qui, puoi leggerli gratuitamente sul mio
[Account Github Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
ma devi pagare per i libri stampati, o la facilità di avere un ePub consegnato tramite i tuoi dispositivi ePub Reader, senza doverlo scaricare.

Libro cartaceo ed ePub Disponibile su:

Lulu
* :book: :computer: http://www.lulu.com/spotlight/LightWizzard

Amazon
* :book: Prenota https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Progressi dello sviluppo

Se non vedi il tuo sistema operativo, scarica, estrai in una cartella e apri con Qt Creator,
che deve essere installato e compilarlo o eseguirlo.


Fine di README.md