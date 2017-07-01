/****************************************************************************
** Meta object code from reading C++ file 'abstractmeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analogwidgets/abstractmeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractmeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AbstractMeter_t {
    QByteArrayData data[16];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractMeter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractMeter_t qt_meta_stringdata_AbstractMeter = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 3),
QT_MOC_LITERAL(4, 32, 8),
QT_MOC_LITERAL(5, 41, 7),
QT_MOC_LITERAL(6, 49, 7),
QT_MOC_LITERAL(7, 57, 5),
QT_MOC_LITERAL(8, 63, 7),
QT_MOC_LITERAL(9, 71, 8),
QT_MOC_LITERAL(10, 80, 6),
QT_MOC_LITERAL(11, 87, 6),
QT_MOC_LITERAL(12, 94, 9),
QT_MOC_LITERAL(13, 104, 11),
QT_MOC_LITERAL(14, 116, 9),
QT_MOC_LITERAL(15, 126, 11)
    },
    "AbstractMeter\0valueChanged\0\0val\0"
    "setValue\0minimum\0maximum\0value\0nominal\0"
    "critical\0prefix\0suffix\0valueFont\0"
    "valueOffset\0digitFont\0digitOffset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractMeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
      11,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       1,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   40,    2, 0x0a /* Public */,
       4,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,

 // properties: name, type, flags
       5, QMetaType::Double, 0x00095103,
       6, QMetaType::Double, 0x00095103,
       7, QMetaType::Double, 0x00095103,
       8, QMetaType::Double, 0x00095103,
       9, QMetaType::Double, 0x00095103,
      10, QMetaType::QString, 0x00095103,
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::QFont, 0x00095103,
      13, QMetaType::Double, 0x00095103,
      14, QMetaType::QFont, 0x00095103,
      15, QMetaType::Double, 0x00095103,

       0        // eod
};

void AbstractMeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractMeter *_t = static_cast<AbstractMeter *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractMeter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractMeter::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (AbstractMeter::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractMeter::valueChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AbstractMeter::staticMetaObject = {
    { &WidgetWithBackground::staticMetaObject, qt_meta_stringdata_AbstractMeter.data,
      qt_meta_data_AbstractMeter,  qt_static_metacall, 0, 0}
};


const QMetaObject *AbstractMeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractMeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractMeter.stringdata))
        return static_cast<void*>(const_cast< AbstractMeter*>(this));
    return WidgetWithBackground::qt_metacast(_clname);
}

int AbstractMeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WidgetWithBackground::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = minimum(); break;
        case 1: *reinterpret_cast< double*>(_v) = maximum(); break;
        case 2: *reinterpret_cast< double*>(_v) = value(); break;
        case 3: *reinterpret_cast< double*>(_v) = nominal(); break;
        case 4: *reinterpret_cast< double*>(_v) = critical(); break;
        case 5: *reinterpret_cast< QString*>(_v) = prefix(); break;
        case 6: *reinterpret_cast< QString*>(_v) = suffix(); break;
        case 7: *reinterpret_cast< QFont*>(_v) = valueFont(); break;
        case 8: *reinterpret_cast< double*>(_v) = valueOffset(); break;
        case 9: *reinterpret_cast< QFont*>(_v) = digitFont(); break;
        case 10: *reinterpret_cast< double*>(_v) = digitOffset(); break;
        default: break;
        }
        _id -= 11;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMinimum(*reinterpret_cast< double*>(_v)); break;
        case 1: setMaximum(*reinterpret_cast< double*>(_v)); break;
        case 2: setValue(*reinterpret_cast< double*>(_v)); break;
        case 3: setNominal(*reinterpret_cast< double*>(_v)); break;
        case 4: setCritical(*reinterpret_cast< double*>(_v)); break;
        case 5: setPrefix(*reinterpret_cast< QString*>(_v)); break;
        case 6: setSuffix(*reinterpret_cast< QString*>(_v)); break;
        case 7: setValueFont(*reinterpret_cast< QFont*>(_v)); break;
        case 8: setValueOffset(*reinterpret_cast< double*>(_v)); break;
        case 9: setDigitFont(*reinterpret_cast< QFont*>(_v)); break;
        case 10: setDigitOffset(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
        _id -= 11;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AbstractMeter::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AbstractMeter::valueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
