# QmlWidgetTranslator

Qml Widget Translator 是 QML 和 QtWidgets 的模板项目。

这个概念很简单，我想要一个可以用于许多操作系统的 Qt Temple，
以及限制，我需要它与 SQL 一起工作，没有它，
有本地存储和没有它，
但我不想用 C++ 编写 QML 或 Qt Widget 应用程序，
以及我必须处理的所有变化，
所以这个模板旨在解决所有这些问题。

我使用 cmake 但如果你想将它用于翻译文件，则需要 qmake 文件，
除此之外，我只使用 cmake 文件，你会发现预编译器定义了很多东西，比如：

* MY_QML：在 QML 中工作时将其设置为 ON，如果 QWidget 模式将其设置为 OFF
* USE_SQL_FLAG：如果要使用SQL设置ON，如果要制作WebAssembly需要关闭SQL和Local Storage，设置为OFF。
* MY_INTERNET_CHECK_PING：在您的应用程序需要 Internet 访问检查时使用
* DO_LUPDATE: 翻译 lupdate
* DO_LRELEASE: 翻译 lrelease
* MY_TS_FILES：翻译 TS 文件
* MY_QM_FILES：翻译 QM 文件
* HEADERS：头文件
* PROJECT_APP_HEADER: QWidget 头文件
* PROJECT_SOURCES：源文件
* PROJECT_UI：QWidget UI 文件
* PROJECT_APP_SOURCE：QWidget 源文件
* ANDROID：安卓模式
* MY_URL：适用于 Mac 捆绑包

我目前正在研究 C++ 中 Qt Widgets 的所有功能，所以我关闭了 MY_QML，
目前 QML 没有 QWidget 的功能，
但我计划换档并设置 MY_QML 并制作相同的功能集。

# 多氧

我使用 Doxygen，你可以从下面的命令运行它。

```bash
Doxygen 文件

或者

强力精灵
``

我在 docs 下有 Doxygen 文档。



＃＃ 地位

[![Appveyor 构建状态](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

## :package: **下载:**

- :penguin: [Linux](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
- :office: [Windows zip exe](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
- :apple: [Apple](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows（在 7 和 10 上测试让我知道 8 是否有效）：下载 zip 并解压缩，然后运行部署文件夹中的文件 QmlWidgetTranslator.exe。

＃ 关于作者

我所有的书都可以在 http://LightWizzard.com 上免费在线，但打印它们或将 ePub 推送到您的设备需要花钱。

我不在这里宣传我的书，你可以在我的网站上免费阅读
[Github 账号 Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe)，
但是您必须为印刷书籍付费，或者通过您的设备 ePub 阅读器轻松交付 ePub，而无需下载它。

印刷书籍和 ePub 可在以下位置获得：

露露
* :book: :computer: http://www.lulu.com/spotlight/LightWizzard

亚马逊
* :book: 书 https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## 开发进度

如果你没有看到你的操作系统，只需下载，解压到一个文件夹，然后用 Qt Creator 打开，
必须安装，并编译或运行它。


README.md 结束