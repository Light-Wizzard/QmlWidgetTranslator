# QmlWidgetTranslator

Qml Widget Translator - это шаблонный проект для QML и QtWidgets.

Идея проста, я хотел Qt Temple, который можно было бы использовать для многих ОС,
а также ограничения, мне было нужно, чтобы он работал с SQL и без него,
с локальным хранилищем и без него,
но я не хотел писать приложение QML или Qt Widget на C ++,
и все вариации, с которыми мне приходится иметь дело,
поэтому этот шаблон предназначен для решения всех этих проблем.

Я использую cmake, но файл qmake необходим, если вы хотите использовать его для файлов перевода,
кроме этого, я использую только файл cmake, и вы найдете определения прекомпилятора для многих вещей, например:

* MY_QML: при работе в QML установите для этого параметра значение ON, если для режима QWidget установлено значение OFF.
* USE_SQL_FLAG: если вы хотите использовать SQL, установите значение ON, если вы хотите сделать WebAssembly и вам нужно отключить SQL и локальное хранилище, установите значение OFF.
* MY_INTERNET_CHECK_PING: используется, если вашему приложению требуются проверки доступа в Интернет.
* DO_LUPDATE: перевод lupdate
* DO_LRELEASE: перевод lrelease
* MY_TS_FILES: файлы TS переводов
* MY_QM_FILES: файлы QM переводов
* ЗАГОЛОВКИ: файлы заголовков
* PROJECT_APP_HEADER: файлы заголовков QWidget
* PROJECT_SOURCES: исходные файлы
* PROJECT_UI: файлы пользовательского интерфейса QWidget
* PROJECT_APP_SOURCE: Исходные файлы QWidget
* ANDROID: режим Andrid
* MY_URL: для Mac Bundle

В настоящее время я работаю над всеми функциями для виджетов Qt на C ++, поэтому у меня отключен MY_QML,
в настоящее время QML не имеет функций QWidget,
но я планирую переключить передачи и включить MY_QML и сделать тот же набор функций.

# Doxygen

Я использую Doxygen, вы можете запустить его с помощью команд ниже.

Баш
doxygen Doxyfile

или

doxywizard
`` ''

У меня есть документы Doxygen в разделе docs.



## Положение дел

[! [Статус сборки приложения] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

##: package: ** Загрузки: **

-: penguin: [Linux] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
-: office: [Windows zip exe] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
-: apple: [Apple] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (проверено на 7 и 10, дайте мне знать, работает ли 8): загрузите zip-архив и извлеките его, а затем запустите файл QmlWidgetTranslator.exe внутри папки развертывания.

# Об авторе

Все мои книги доступны бесплатно на сайте http://LightWizzard.com, но их распечатка или отправка файлов в формате ePub на ваше устройство стоит денег.

Я не публикую здесь свои книги, вы можете бесплатно читать их на моем
[Аккаунт Github Light-Wizzard / The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
но вы должны платить за печатные книги или просто доставить ePub через ваши устройства ePub Reader, не загружая его.

Печатная книга и ePub доступны по адресу:

Лулу
*: книга:: компьютер: http://www.lulu.com/spotlight/LightWizzard

Амазонка
*: книга: Книга https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: компьютер: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Прогресс в разработке

Если вы не видите свою ОС, просто загрузите, распакуйте в папку и откройте с помощью Qt Creator,
который должен быть установлен, и скомпилируйте или запустите его.


Конец README.md