＃QmlWidgetTranslator

Qml Widget Translatorは、QMLとQtWidgetsの両方のテンプレートプロジェクトです。

コンセプトはシンプルです。多くのOSで使用できるQtTempleが欲しかったのですが、
制約だけでなく、SQLを使用する場合と使用しない場合で動作するために必要でした。
ローカルストレージがある場合とない場合
しかし、C ++でQMLまたはQtウィジェットアプリケーションを作成したくありませんでした。
そして私が扱わなければならないすべてのバリエーション、
したがって、このテンプレートは、これらすべての問題を回避するように設計されています。

私はcmakeを使用していますが、翻訳ファイルに使用する場合はqmakeファイルが必要です。
それ以外は、cmakeファイルのみを使用しており、precomiplerが次のような多くのことを定義していることがわかります。

* MY_QML：QMLで作業しているときに、これをONに設定し、QWidgetモードでOFFに設定している場合
* USE_SQL_FLAG：SQLセットをオンにしたい場合、WebAssemblyを作成し、SQLとローカルストレージをオフにする必要がある場合は、オフに設定します。
* MY_INTERNET_CHECK_PING：アプリケーションでインターネットアクセスチェックが必要な場合に使用されます
* DO_LUPDATE：翻訳lupdate
* DO_LRELEASE：翻訳lrelease
* MY_TS_FILES：翻訳TSファイル
* MY_QM_FILES：翻訳QMファイル
*ヘッダー：ヘッダーファイル
* PROJECT_APP_HEADER：QWidgetヘッダーファイル
* PROJECT_SOURCES：ソースファイル
* PROJECT_UI：QWidgetUIファイル
* PROJECT_APP_SOURCE：QWidgetソースファイル
* ANDROID：Andridモード
* MY_URL：Macバンドル用

現在、C ++のQtウィジェットのすべての機能に取り組んでいるので、MY_QMLをオフにします。
現在、QMLにはQWidgetの機能がありません。
しかし、ギアを切り替えてMY_QMLをオンに設定し、同じ機能セットを作成する予定です。

＃Doxygen

私はDoxygenを使用していますが、以下のコマンドから実行できます。

`` `bash
doxygen Doxyfile

また

ドキシウィザード
`` `

ドキュメントの下にDoxygenドキュメントがあります。



＃＃ 状態

[！[Appveyorビルドステータス]（https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true）]（https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator）

##：パッケージ：**ダウンロード：**

-：penguin：[Linux]（https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage）
-：office：[Windows zip exe]（https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip）
-：apple：[Apple]（https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg）

Windows（7および10でテスト済み）：zipをダウンロードして解凍し、デプロイフォルダー内でファイルQmlWidgetTranslator.exeを実行します。

＃ 著者について

私の本はすべてhttp://LightWizzard.comからオンラインで無料で入手できますが、印刷したり、ePubをデバイスにプッシュしたりするにはお金がかかります。

私はここで私の本を公表していません、あなたは私の本でそれらを無料で読むことができます
[GithubアカウントLight-Wizzard / The-Principles-Of-The-Trinary-Universe]（https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe）、
ただし、印刷された本、またはePubをダウンロードせずにデバイスのePubリーダーから簡単に配信できるようにするために料金を支払う必要があります。

印刷された本とePubは次の場所で入手できます。

ルル
*：book ：： computer：http：//www.lulu.com/spotlight/LightWizzard

アマゾン
*：book：Book https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*：コンピューター：ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

##開発の進捗状況

OSが表示されない場合は、ダウンロードしてフォルダーに解凍し、QtCreatorで開きます。
これをインストールし、コンパイルまたは実行する必要があります。


README.mdの終わり