/****************************************************************************
** Meta object code from reading C++ file 'wallclock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analogwidgets/wallclock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wallclock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WallClock_t {
    QByteArrayData data[21];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WallClock_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WallClock_t qt_meta_stringdata_WallClock = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 7),
QT_MOC_LITERAL(4, 27, 11),
QT_MOC_LITERAL(5, 39, 22),
QT_MOC_LITERAL(6, 62, 19),
QT_MOC_LITERAL(7, 82, 10),
QT_MOC_LITERAL(8, 93, 9),
QT_MOC_LITERAL(9, 103, 8),
QT_MOC_LITERAL(10, 112, 8),
QT_MOC_LITERAL(11, 121, 7),
QT_MOC_LITERAL(12, 129, 11),
QT_MOC_LITERAL(13, 141, 10),
QT_MOC_LITERAL(14, 152, 10),
QT_MOC_LITERAL(15, 163, 9),
QT_MOC_LITERAL(16, 173, 10),
QT_MOC_LITERAL(17, 184, 9),
QT_MOC_LITERAL(18, 194, 9),
QT_MOC_LITERAL(19, 204, 8),
QT_MOC_LITERAL(20, 213, 8)
    },
    "WallClock\0setTime\0\0setDate\0setDateTime\0"
    "setShowCurrentDateTime\0showCurrentDateTime\0"
    "updateTime\0digitFont\0dateFont\0timeFont\0"
    "dayFont\0digitOffset\0dateOffset\0"
    "timeOffset\0dayOffset\0digitColor\0"
    "dateColor\0timeColor\0dayColor\0dateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WallClock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
      14,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    1,   42,    2, 0x0a /* Public */,
       4,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QTime,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDateTime,    2,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QFont, 0x00095103,
       9, QMetaType::QFont, 0x00095103,
      10, QMetaType::QFont, 0x00095103,
      11, QMetaType::QFont, 0x00095103,
      12, QMetaType::Int, 0x00095103,
      13, QMetaType::Int, 0x00095103,
      14, QMetaType::Int, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      18, QMetaType::QColor, 0x00095103,
      19, QMetaType::QColor, 0x00095103,
      20, QMetaType::QDateTime, 0x00095103,
       6, QMetaType::Bool, 0x00095103,

       0        // eod
};

void WallClock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WallClock *_t = static_cast<WallClock *>(_o);
        switch (_id) {
        case 0: _t->setTime((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 1: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->setDateTime((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 3: _t->setShowCurrentDateTime((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateTime(); break;
        default: ;
        }
    }
}

const QMetaObject WallClock::staticMetaObject = {
    { &WidgetWithBackground::staticMetaObject, qt_meta_stringdata_WallClock.data,
      qt_meta_data_WallClock,  qt_static_metacall, 0, 0}
};


const QMetaObject *WallClock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WallClock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WallClock.stringdata))
        return static_cast<void*>(const_cast< WallClock*>(this));
    return WidgetWithBackground::qt_metacast(_clname);
}

int WallClock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WidgetWithBackground::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QFont*>(_v) = digitFont(); break;
        case 1: *reinterpret_cast< QFont*>(_v) = dateFont(); break;
        case 2: *reinterpret_cast< QFont*>(_v) = timeFont(); break;
        case 3: *reinterpret_cast< QFont*>(_v) = dayFont(); break;
        case 4: *reinterpret_cast< int*>(_v) = digitOffset(); break;
        case 5: *reinterpret_cast< int*>(_v) = dateOffset(); break;
        case 6: *reinterpret_cast< int*>(_v) = timeOffset(); break;
        case 7: *reinterpret_cast< int*>(_v) = dayOffset(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = digitColor(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = dateColor(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = timeColor(); break;
        case 11: *reinterpret_cast< QColor*>(_v) = dayColor(); break;
        case 12: *reinterpret_cast< QDateTime*>(_v) = dateTime(); break;
        case 13: *reinterpret_cast< bool*>(_v) = showCurrentDateTime(); break;
        default: break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDigitFont(*reinterpret_cast< QFont*>(_v)); break;
        case 1: setDateFont(*reinterpret_cast< QFont*>(_v)); break;
        case 2: setTimeFont(*reinterpret_cast< QFont*>(_v)); break;
        case 3: setDayFont(*reinterpret_cast< QFont*>(_v)); break;
        case 4: setDigitOffset(*reinterpret_cast< int*>(_v)); break;
        case 5: setDateOffset(*reinterpret_cast< int*>(_v)); break;
        case 6: setTimeOffset(*reinterpret_cast< int*>(_v)); break;
        case 7: setDayOffset(*reinterpret_cast< int*>(_v)); break;
        case 8: setDigitColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: setDateColor(*reinterpret_cast< QColor*>(_v)); break;
        case 10: setTimeColor(*reinterpret_cast< QColor*>(_v)); break;
        case 11: setDayColor(*reinterpret_cast< QColor*>(_v)); break;
        case 12: setDateTime(*reinterpret_cast< QDateTime*>(_v)); break;
        case 13: setShowCurrentDateTime(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
