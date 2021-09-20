/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[54];
    char stringdata0[1212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "onSaveAll"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "thisStatus"
QT_MOC_LITERAL(4, 33, 6), // "onSave"
QT_MOC_LITERAL(5, 40, 11), // "changeEvent"
QT_MOC_LITERAL(6, 52, 7), // "QEvent*"
QT_MOC_LITERAL(7, 60, 5), // "event"
QT_MOC_LITERAL(8, 66, 39), // "on_comboBoxLanguage_currentIn..."
QT_MOC_LITERAL(9, 106, 12), // "thisLanguage"
QT_MOC_LITERAL(10, 119, 46), // "on_comboBoxSqlDatabaseType_cu..."
QT_MOC_LITERAL(11, 166, 11), // "thisSqlType"
QT_MOC_LITERAL(12, 178, 39), // "on_comboBoxProjects_currentIn..."
QT_MOC_LITERAL(13, 218, 9), // "thisIndex"
QT_MOC_LITERAL(14, 228, 58), // "on_comboBoxProjectsDateTimeFo..."
QT_MOC_LITERAL(15, 287, 18), // "thisDateTimeFormat"
QT_MOC_LITERAL(16, 306, 56), // "on_comboBoxProjectsDateTimeFo..."
QT_MOC_LITERAL(17, 363, 42), // "on_pushButtonSqlDatabaseNameB..."
QT_MOC_LITERAL(18, 406, 36), // "on_pushButtonSqlPasswordShow_..."
QT_MOC_LITERAL(19, 443, 28), // "on_pushButtonSqlSave_clicked"
QT_MOC_LITERAL(20, 472, 33), // "on_pushButtonProjectsSave_cli..."
QT_MOC_LITERAL(21, 506, 35), // "on_pushButtonProjectsDelete_c..."
QT_MOC_LITERAL(22, 542, 32), // "on_pushButtonProjectsAdd_clicked"
QT_MOC_LITERAL(23, 575, 34), // "on_pushButtonProjectsClear_cl..."
QT_MOC_LITERAL(24, 610, 38), // "on_pushButtonProjectsDateStar..."
QT_MOC_LITERAL(25, 649, 36), // "on_pushButtonProjectsDateDue_..."
QT_MOC_LITERAL(26, 686, 46), // "on_pushButtonProjectsProgress..."
QT_MOC_LITERAL(27, 733, 49), // "on_pushButtonProjectsProgress..."
QT_MOC_LITERAL(28, 783, 49), // "on_pushButtonProjectsProgress..."
QT_MOC_LITERAL(29, 833, 41), // "on_pushButtonProjectsShowPass..."
QT_MOC_LITERAL(30, 875, 6), // "onHelp"
QT_MOC_LITERAL(31, 882, 7), // "onAbout"
QT_MOC_LITERAL(32, 890, 8), // "onAuthor"
QT_MOC_LITERAL(33, 899, 18), // "onInternetProgress"
QT_MOC_LITERAL(34, 918, 35), // "on_lineEditProjectsName_textC..."
QT_MOC_LITERAL(35, 954, 8), // "thisText"
QT_MOC_LITERAL(36, 963, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(37, 991, 5), // "index"
QT_MOC_LITERAL(38, 997, 10), // "onTextBold"
QT_MOC_LITERAL(39, 1008, 15), // "onTextUnderline"
QT_MOC_LITERAL(40, 1024, 12), // "onTextItalic"
QT_MOC_LITERAL(41, 1037, 28), // "mergeFormatOnWordOrSelection"
QT_MOC_LITERAL(42, 1066, 15), // "QTextCharFormat"
QT_MOC_LITERAL(43, 1082, 6), // "format"
QT_MOC_LITERAL(44, 1089, 11), // "fontChanged"
QT_MOC_LITERAL(45, 1101, 1), // "f"
QT_MOC_LITERAL(46, 1103, 26), // "onCurrentCharFormatChanged"
QT_MOC_LITERAL(47, 1130, 23), // "onCursorPositionChanged"
QT_MOC_LITERAL(48, 1154, 8), // "MainTabs"
QT_MOC_LITERAL(49, 1163, 11), // "TabSettings"
QT_MOC_LITERAL(50, 1175, 6), // "TabSql"
QT_MOC_LITERAL(51, 1182, 11), // "TabProjects"
QT_MOC_LITERAL(52, 1194, 10), // "TabTabHelp"
QT_MOC_LITERAL(53, 1205, 6) // "TabAll"

    },
    "MainWindow\0onSaveAll\0\0thisStatus\0"
    "onSave\0changeEvent\0QEvent*\0event\0"
    "on_comboBoxLanguage_currentIndexChanged\0"
    "thisLanguage\0"
    "on_comboBoxSqlDatabaseType_currentIndexChanged\0"
    "thisSqlType\0on_comboBoxProjects_currentIndexChanged\0"
    "thisIndex\0"
    "on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged\0"
    "thisDateTimeFormat\0"
    "on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged\0"
    "on_pushButtonSqlDatabaseNameBrowse_clicked\0"
    "on_pushButtonSqlPasswordShow_clicked\0"
    "on_pushButtonSqlSave_clicked\0"
    "on_pushButtonProjectsSave_clicked\0"
    "on_pushButtonProjectsDelete_clicked\0"
    "on_pushButtonProjectsAdd_clicked\0"
    "on_pushButtonProjectsClear_clicked\0"
    "on_pushButtonProjectsDateStart_clicked\0"
    "on_pushButtonProjectsDateDue_clicked\0"
    "on_pushButtonProjectsProgressStatusAdd_clicked\0"
    "on_pushButtonProjectsProgressStatusDelete_clicked\0"
    "on_pushButtonProjectsProgressStatusModify_clicked\0"
    "on_pushButtonProjectsShowPassword_clicked\0"
    "onHelp\0onAbout\0onAuthor\0onInternetProgress\0"
    "on_lineEditProjectsName_textChanged\0"
    "thisText\0on_tabWidget_currentChanged\0"
    "index\0onTextBold\0onTextUnderline\0"
    "onTextItalic\0mergeFormatOnWordOrSelection\0"
    "QTextCharFormat\0format\0fontChanged\0f\0"
    "onCurrentCharFormatChanged\0"
    "onCursorPositionChanged\0MainTabs\0"
    "TabSettings\0TabSql\0TabProjects\0"
    "TabTabHelp\0TabAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       1,  242, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  184,    2, 0x0a /* Public */,
       4,    0,  187,    2, 0x0a /* Public */,
       5,    1,  188,    2, 0x09 /* Protected */,
       8,    1,  191,    2, 0x08 /* Private */,
      10,    1,  194,    2, 0x08 /* Private */,
      12,    1,  197,    2, 0x08 /* Private */,
      14,    1,  200,    2, 0x08 /* Private */,
      16,    1,  203,    2, 0x08 /* Private */,
      17,    0,  206,    2, 0x08 /* Private */,
      18,    0,  207,    2, 0x08 /* Private */,
      19,    0,  208,    2, 0x08 /* Private */,
      20,    0,  209,    2, 0x08 /* Private */,
      21,    0,  210,    2, 0x08 /* Private */,
      22,    0,  211,    2, 0x08 /* Private */,
      23,    0,  212,    2, 0x08 /* Private */,
      24,    0,  213,    2, 0x08 /* Private */,
      25,    0,  214,    2, 0x08 /* Private */,
      26,    0,  215,    2, 0x08 /* Private */,
      27,    0,  216,    2, 0x08 /* Private */,
      28,    0,  217,    2, 0x08 /* Private */,
      29,    0,  218,    2, 0x08 /* Private */,
      30,    0,  219,    2, 0x08 /* Private */,
      31,    0,  220,    2, 0x08 /* Private */,
      32,    0,  221,    2, 0x08 /* Private */,
      33,    0,  222,    2, 0x08 /* Private */,
      34,    1,  223,    2, 0x08 /* Private */,
      36,    1,  226,    2, 0x08 /* Private */,
      38,    0,  229,    2, 0x08 /* Private */,
      39,    0,  230,    2, 0x08 /* Private */,
      40,    0,  231,    2, 0x08 /* Private */,
      41,    1,  232,    2, 0x08 /* Private */,
      44,    1,  235,    2, 0x08 /* Private */,
      46,    1,  238,    2, 0x08 /* Private */,
      47,    0,  241,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, QMetaType::QFont,   45,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      48,   48, 0x0,    5,  247,

 // enum data: key, value
      49, uint(MainWindow::TabSettings),
      50, uint(MainWindow::TabSql),
      51, uint(MainWindow::TabProjects),
      52, uint(MainWindow::TabTabHelp),
      53, uint(MainWindow::TabAll),

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSaveAll((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onSave(); break;
        case 2: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 3: _t->on_comboBoxLanguage_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBoxSqlDatabaseType_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_comboBoxProjects_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonSqlDatabaseNameBrowse_clicked(); break;
        case 9: _t->on_pushButtonSqlPasswordShow_clicked(); break;
        case 10: _t->on_pushButtonSqlSave_clicked(); break;
        case 11: _t->on_pushButtonProjectsSave_clicked(); break;
        case 12: _t->on_pushButtonProjectsDelete_clicked(); break;
        case 13: _t->on_pushButtonProjectsAdd_clicked(); break;
        case 14: _t->on_pushButtonProjectsClear_clicked(); break;
        case 15: _t->on_pushButtonProjectsDateStart_clicked(); break;
        case 16: _t->on_pushButtonProjectsDateDue_clicked(); break;
        case 17: _t->on_pushButtonProjectsProgressStatusAdd_clicked(); break;
        case 18: _t->on_pushButtonProjectsProgressStatusDelete_clicked(); break;
        case 19: _t->on_pushButtonProjectsProgressStatusModify_clicked(); break;
        case 20: _t->on_pushButtonProjectsShowPassword_clicked(); break;
        case 21: _t->onHelp(); break;
        case 22: _t->onAbout(); break;
        case 23: _t->onAuthor(); break;
        case 24: _t->onInternetProgress(); break;
        case 25: _t->on_lineEditProjectsName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->onTextBold(); break;
        case 28: _t->onTextUnderline(); break;
        case 29: _t->onTextItalic(); break;
        case 30: _t->mergeFormatOnWordOrSelection((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 31: _t->fontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 32: _t->onCurrentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 33: _t->onCursorPositionChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
