/****************************************************************************
** Meta object code from reading C++ file 'scriptwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analogwidgets/scriptwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scriptwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScriptWidget_t {
    QByteArrayData data[16];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptWidget_t qt_meta_stringdata_ScriptWidget = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 8),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 1),
QT_MOC_LITERAL(5, 35, 10),
QT_MOC_LITERAL(6, 46, 4),
QT_MOC_LITERAL(7, 51, 7),
QT_MOC_LITERAL(8, 59, 4),
QT_MOC_LITERAL(9, 64, 10),
QT_MOC_LITERAL(10, 75, 11),
QT_MOC_LITERAL(11, 87, 8),
QT_MOC_LITERAL(12, 96, 9),
QT_MOC_LITERAL(13, 106, 6),
QT_MOC_LITERAL(14, 113, 6),
QT_MOC_LITERAL(15, 120, 5)
    },
    "ScriptWidget\0evaluate\0\0setScript\0s\0"
    "setSvgFile\0file\0addItem\0name\0resetItems\0"
    "loadSvgFile\0setPName\0setPValue\0script\0"
    "PValue\0PName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       3,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a /* Public */,
       5,    1,   73,    2, 0x0a /* Public */,
       7,    1,   76,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      12,    1,   92,    2, 0x0a /* Public */,
      12,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QVariant,    2,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00095103,
      14, QMetaType::QVariant, 0x00084103,
      15, QMetaType::QString, 0x00084103,

       0        // eod
};

void ScriptWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptWidget *_t = static_cast<ScriptWidget *>(_o);
        switch (_id) {
        case 0: _t->evaluate(); break;
        case 1: _t->setScript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setSvgFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->addItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->resetItems(); break;
        case 5: _t->loadSvgFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setPName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setPValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setPValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setPValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setPValue((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptWidget::evaluate)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScriptWidget::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_ScriptWidget.data,
      qt_meta_data_ScriptWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptWidget.stringdata))
        return static_cast<void*>(const_cast< ScriptWidget*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int ScriptWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = script(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = getPValue(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getPName(); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScript(*reinterpret_cast< QString*>(_v)); break;
        case 1: setPValue(*reinterpret_cast< QVariant*>(_v)); break;
        case 2: setPName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ScriptWidget::evaluate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
