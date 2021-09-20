/****************************************************************************
** Meta object code from reading C++ file 'MyLanguageModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../MyLanguageModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLanguageModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLanguageModel_t {
    QByteArrayData data[14];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLanguageModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLanguageModel_t qt_meta_stringdata_MyLanguageModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MyLanguageModel"
QT_MOC_LITERAL(1, 16, 15), // "languageChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "addItem"
QT_MOC_LITERAL(4, 41, 8), // "thisName"
QT_MOC_LITERAL(5, 50, 18), // "thisNameTranslated"
QT_MOC_LITERAL(6, 69, 10), // "removeItem"
QT_MOC_LITERAL(7, 80, 7), // "thisRow"
QT_MOC_LITERAL(8, 88, 12), // "setLanguages"
QT_MOC_LITERAL(9, 101, 11), // "setLanguage"
QT_MOC_LITERAL(10, 113, 16), // "thisLanguageName"
QT_MOC_LITERAL(11, 130, 15), // "setLanguageList"
QT_MOC_LITERAL(12, 146, 16), // "thisLanguageList"
QT_MOC_LITERAL(13, 163, 15) // "getLanguageList"

    },
    "MyLanguageModel\0languageChanged\0\0"
    "addItem\0thisName\0thisNameTranslated\0"
    "removeItem\0thisRow\0setLanguages\0"
    "setLanguage\0thisLanguageName\0"
    "setLanguageList\0thisLanguageList\0"
    "getLanguageList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLanguageModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    2,   50,    2, 0x02 /* Public */,
       6,    1,   55,    2, 0x02 /* Public */,
       8,    0,   58,    2, 0x02 /* Public */,
       9,    1,   59,    2, 0x02 /* Public */,
      11,    1,   62,    2, 0x02 /* Public */,
      13,    0,   65,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void,

       0        // eod
};

void MyLanguageModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyLanguageModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->languageChanged(); break;
        case 1: _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setLanguages(); break;
        case 4: _t->setLanguage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setLanguageList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 6: _t->getLanguageList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLanguageModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLanguageModel::languageChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyLanguageModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_MyLanguageModel.data,
    qt_meta_data_MyLanguageModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyLanguageModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLanguageModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLanguageModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int MyLanguageModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyLanguageModel::languageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
