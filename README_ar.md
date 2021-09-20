# QmlWidgetTranslator

Qml Widget Translator هو مشروع نموذجي لكل من QML و QtWidgets.

المفهوم بسيط ، أردت معبد Qt يمكن استخدامه للعديد من أنظمة التشغيل ،
بالإضافة إلى القيود ، كنت أحتاجها للعمل مع SQL وبدونها ،
مع التخزين المحلي وبدونه ،
لكنني لم أرغب في كتابة تطبيق QML أو Qt Widget في C ++ ،
وجميع الاختلافات التي يجب أن أتعامل معها ،
لذلك تم تصميم هذا النموذج للتغلب على كل هذه المشكلات.

أنا أستخدم cmake ولكن ملف qmake يتم إعادة استخدامه إذا كنت تريد استخدامه لملفات الترجمة ،
بخلاف ذلك ، أستخدم ملف cmake فقط ، وستجد تعريفات prepomipler للعديد من الأشياء مثل:

* MY_QML: عند العمل في QML ، اضبطه على ON ، إذا قام وضع QWidget بضبطه على OFF
* USE_SQL_FLAG: إذا كنت تريد استخدام SQL set ON ، إذا كنت تريد إنشاء WebAssembly وتحتاج إلى إيقاف تشغيل SQL والتخزين المحلي ، فاضبط على OFF.
* MY_INTERNET_CHECK_PING: يُستخدم إذا كان التطبيق الخاص بك يحتاج إلى عمليات التحقق من الوصول إلى الإنترنت
* DO_LUPDATE: تأريخ الترجمة
* DO_LRELEASE: إصدار الترجمة
* MY_TS_FILES: ترجمة ملفات TS
* MY_QM_FILES: ترجمة ملفات QM
* رؤوس: ملفات الرأس
* PROJECT_APP_HEADER: ملفات رأس QWidget
* PROJECT_SOURCES: ملفات المصدر
* PROJECT_UI: ملفات QWidget UI
* PROJECT_APP_SOURCE: ملفات مصدر QWidget
* ANDROID: وضع Andrid
* MY_URL: لحزمة Mac

أنا أعمل حاليًا على جميع ميزات Qt Widgets في C ++ ، لذلك أوقف تشغيل MY_QML ،
لا يحتوي QML حاليًا على ميزات QWidget ،
لكنني أخطط لتبديل التروس وتعيين MY_QML في وضع التشغيل وإنشاء نفس مجموعة الميزات.

# دوكسجين

أنا أستخدم Doxygen ، يمكنك تشغيله من الأوامر أدناه.

"" باش
دوكسجين Doxyfile

أو

دوكسيويارد
""

لدي مستندات Doxygen ضمن المستندات.



## حالة

[! [حالة إصدار Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6؟svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

##: الحزمة: ** التنزيلات: **

-: penguin: [Linux] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
-: office: [Windows zip exe] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
-: apple: [Apple] (https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (تم اختباره في 7 و 10 ، أخبرني إذا كان 8 يعمل): قم بتنزيل zip واستخرجه ، وقم بتشغيل الملف QmlWidgetTranslator.exe داخل مجلد النشر.

# نبذة عن الكاتب

جميع كتبي مجانية عبر الإنترنت على الموقع http://LightWizzard.com ، ولكن طباعتها أو دفع ePubs إلى جهازك يكلف بعض المال.

أنا لا أنشر كتبي هنا ، يمكنك قراءتها مجانًا على موقعي
[حساب Github Light-Wizzard / The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe) ،
ولكن عليك أن تدفع مقابل الكتب المطبوعة ، أو سهولة الحصول على ePub من خلال أجهزتك ePub Reader ، دون الحاجة إلى تنزيله.

الكتاب المطبوع و ePub متوفران في:

لولو
*: كتاب: كمبيوتر: http://www.lulu.com/spotlight/LightWizzard

أمازون
*: كتاب: كتاب https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: الكمبيوتر: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## التقدم في عملية التنمية

إذا كنت لا ترى نظام التشغيل الخاص بك ، فما عليك سوى تنزيله واستخراجه إلى مجلد وافتحه باستخدام Qt Creator ،
التي يجب تثبيتها وتجميعها أو تشغيلها.


نهاية الملف README.md