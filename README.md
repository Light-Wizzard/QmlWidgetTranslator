# QmlWidgetTranslator

Qml Widget Translator is a Template Project for both QML and QtWidgets.

The concept is simple, I wanted a Qt Temple that could be used for many OS's,
as well as restraints, I needed it to work with SQL and without it, 
with Local Storage and without it, 
but I did not want to write a QML or Qt Widget Application in C++, 
and all the variations I have to deal with,
so this Template is designed to work around all these issues.

I use cmake but the qmake file is reguired if you want use it for translation files, 
other than that I only use the cmake file, and you will find precomipler defines for many things like:

* MY_QML: When working in QML set this to ON, if QWidget mode set it to OFF
* USE_SQL_FLAG: If you want to use SQL set ON, if you want to make WebAssembly and need to turn off SQL and Local Storage, set to OFF.
* MY_INTERNET_CHECK_PING: Used if your Application needs Internet Access Checks
* DO_LUPDATE: Translation lupdate
* DO_LRELEASE: Translation lrelease
* MY_TS_FILES: Translation TS Files
* MY_QM_FILES: Translation QM Files
* HEADERS: Header Files
* PROJECT_APP_HEADER: QWidget Header files
* PROJECT_SOURCES: Source files
* PROJECT_UI: QWidget UI files
* PROJECT_APP_SOURCE: QWidget Source files
* ANDROID: Andrid Mode
* MY_URL: for Mac Bundle

I am currently working on all the Features for Qt Widgets in C++, so I have MY_QML off, 
currently QML does not have the features the QWidget has,
but I plan to switch gears and set MY_QML ON and make the same set of features.

# Doxygen

I use Doxygen, you can run it from the commands below.

```bash
doxygen Doxyfile 

or

doxywizard
```

I have Doxygen Documents under docs.



## Status

[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

## :package: **Downloads:**

- :penguin: [Linux](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
- :office: [Windows zip exe](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
- :apple: [Apple](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (Tested on 7 and 10 let me know if 8 works): Download zip and extract it, and run the file QmlWidgetTranslator.exe inside of the deploy folder.

# About the Author

All my books are free online at http://LightWizzard.com, but it cost money to print them or push ePubs to your device.

I am not publicizing my books here, you can read them for free on my 
[Github account Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
but you have to pay for printed books, or the easy of having an ePub delivered through your devices ePub Reader, without having to download it.

Printed Book and ePub Available at:

Lulu
* :book: :computer: http://www.lulu.com/spotlight/LightWizzard

Amazon
* :book: Book https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Development Progress

If you do not see your OS, just download, extract to a folder, and open with Qt Creator, 
which must be installed, and compile or run it.


End of README.md
