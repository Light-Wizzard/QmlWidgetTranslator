#include <QtTest>
#include <QCoreApplication>

#include "../../MyOrgSettings.h"
/************************************************
 * @brief QmlWidgetTranslatorTestCase Class.
 * /class QmlWidgetTranslatorTestCase
 ***********************************************/
class QmlWidgetTranslatorTestCase : public QObject
{
        Q_OBJECT

    public:
        QmlWidgetTranslatorTestCase();
        ~QmlWidgetTranslatorTestCase();

    private slots:
        void initTestCase();
        void cleanupTestCase();
        void test_case1();

};
/************************************************
 * @brief QmlWidgetTranslatorTestCase Constructor.
 * QmlWidgetTranslatorTestCase
 ***********************************************/
QmlWidgetTranslatorTestCase::QmlWidgetTranslatorTestCase()
{

}
/************************************************
 * @brief QmlWidgetTranslatorTestCase Deconstructor.
 * ~QmlWidgetTranslatorTestCase
 ***********************************************/
QmlWidgetTranslatorTestCase::~QmlWidgetTranslatorTestCase()
{

}
/************************************************
 * @brief initTestCase.
 * initTestCase
 ***********************************************/
void QmlWidgetTranslatorTestCase::initTestCase()
{
    MyOrgSettings *myOrgSettings = new MyOrgSettings(this);
    QCOMPARE(myOrgSettings->getAppName(), qApp->applicationName());
}
/************************************************
 * @brief cleanupTestCase.
 * cleanupTestCase
 ***********************************************/
void QmlWidgetTranslatorTestCase::cleanupTestCase()
{

}
/************************************************
 * @brief test_case1.
 * test_case1
 ***********************************************/
void QmlWidgetTranslatorTestCase::test_case1()
{
    QString theTest = "This is my Secret";
    MyOrgSettings *myOrgSettings = new MyOrgSettings(this);
    QCOMPARE(theTest, myOrgSettings->decryptThis(myOrgSettings->encryptThis(theTest)));
}
/************************************************
 * @brief main.
 * main
 ***********************************************/
QTEST_MAIN(QmlWidgetTranslatorTestCase)

#include "tst_qmlwidgettranslatortestcase.moc"
/******************************* End of File *********************************/
