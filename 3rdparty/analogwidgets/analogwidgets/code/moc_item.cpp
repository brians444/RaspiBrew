/****************************************************************************
** Meta object code from reading C++ file 'item.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Item_t {
    QByteArrayData data[17];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Item_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Item_t qt_meta_stringdata_Item = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 5),
QT_MOC_LITERAL(2, 11, 0),
QT_MOC_LITERAL(3, 12, 1),
QT_MOC_LITERAL(4, 14, 6),
QT_MOC_LITERAL(5, 21, 5),
QT_MOC_LITERAL(6, 27, 9),
QT_MOC_LITERAL(7, 37, 2),
QT_MOC_LITERAL(8, 40, 2),
QT_MOC_LITERAL(9, 43, 6),
QT_MOC_LITERAL(10, 50, 6),
QT_MOC_LITERAL(11, 57, 14),
QT_MOC_LITERAL(12, 72, 10),
QT_MOC_LITERAL(13, 83, 1),
QT_MOC_LITERAL(14, 85, 4),
QT_MOC_LITERAL(15, 90, 4),
QT_MOC_LITERAL(16, 95, 12)
    },
    "Item\0scale\0\0x\0rotate\0angle\0translate\0"
    "dx\0dy\0setPos\0moveBy\0resetTransform\0"
    "setVisible\0v\0hide\0show\0boundingRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    2,   65,    2, 0x0a /* Public */,
       9,    2,   70,    2, 0x0a /* Public */,
      10,    2,   75,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      14,    0,   84,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    7,    8,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    7,    8,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      16, QMetaType::QRectF, 0x00095001,

       0        // eod
};

void Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Item *_t = static_cast<Item *>(_o);
        switch (_id) {
        case 0: _t->scale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->rotate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->translate((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 3: _t->setPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 4: _t->moveBy((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 5: _t->resetTransform(); break;
        case 6: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->hide(); break;
        case 8: _t->show(); break;
        default: ;
        }
    }
}

const QMetaObject Item::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Item.data,
      qt_meta_data_Item,  qt_static_metacall, 0, 0}
};


const QMetaObject *Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Item::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Item.stringdata))
        return static_cast<void*>(const_cast< Item*>(this));
    return QObject::qt_metacast(_clname);
}

int Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QRectF*>(_v) = boundingRect(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
