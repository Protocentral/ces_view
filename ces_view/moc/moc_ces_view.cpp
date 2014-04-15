/****************************************************************************
** Meta object code from reading C++ file 'ces_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ces_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ces_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ces_view_t {
    QByteArrayData data[22];
    char stringdata[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ces_view_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ces_view_t qt_meta_stringdata_ces_view = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 26),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 5),
QT_MOC_LITERAL(4, 43, 12),
QT_MOC_LITERAL(5, 56, 24),
QT_MOC_LITERAL(6, 81, 6),
QT_MOC_LITERAL(7, 88, 6),
QT_MOC_LITERAL(8, 95, 6),
QT_MOC_LITERAL(9, 102, 17),
QT_MOC_LITERAL(10, 120, 17),
QT_MOC_LITERAL(11, 138, 12),
QT_MOC_LITERAL(12, 151, 13),
QT_MOC_LITERAL(13, 165, 12),
QT_MOC_LITERAL(14, 178, 11),
QT_MOC_LITERAL(15, 190, 14),
QT_MOC_LITERAL(16, 205, 24),
QT_MOC_LITERAL(17, 230, 7),
QT_MOC_LITERAL(18, 238, 7),
QT_MOC_LITERAL(19, 246, 11),
QT_MOC_LITERAL(20, 258, 10),
QT_MOC_LITERAL(21, 269, 12)
    },
    "ces_view\0signalSerialRxDataReceived\0"
    "\0items\0items_length\0signalDataPacketReceived\0"
    "data_x\0data_y\0data_z\0signalCh1Received\0"
    "signalCh2Received\0slotOpenPort\0"
    "slotClosePort\0slotStartLog\0slotStopLog\0"
    "slotSerialRead\0slotSerialPacketReceived\0"
    "PktType\0SrcAddr\0packet_data\0packet_len\0"
    "slotCloseApp\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ces_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06,
       5,    3,   74,    2, 0x06,
       9,    1,   81,    2, 0x06,
      10,    1,   84,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   87,    2, 0x0a,
      12,    0,   88,    2, 0x0a,
      13,    0,   89,    2, 0x0a,
      14,    0,   90,    2, 0x0a,
      15,    0,   91,    2, 0x0a,
      16,    4,   92,    2, 0x0a,
      21,    0,  101,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UShort, QMetaType::QByteArray, QMetaType::UShort,   17,   18,   19,   20,
    QMetaType::Void,

       0        // eod
};

void ces_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ces_view *_t = static_cast<ces_view *>(_o);
        switch (_id) {
        case 0: _t->signalSerialRxDataReceived((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->signalDataPacketReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->signalCh1Received((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->signalCh2Received((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->slotOpenPort(); break;
        case 5: _t->slotClosePort(); break;
        case 6: _t->slotStartLog(); break;
        case 7: _t->slotStopLog(); break;
        case 8: _t->slotSerialRead(); break;
        case 9: _t->slotSerialPacketReceived((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 10: _t->slotCloseApp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ces_view::*_t)(QByteArray , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ces_view::signalSerialRxDataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (ces_view::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ces_view::signalDataPacketReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (ces_view::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ces_view::signalCh1Received)) {
                *result = 2;
            }
        }
        {
            typedef void (ces_view::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ces_view::signalCh2Received)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ces_view::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ces_view.data,
      qt_meta_data_ces_view,  qt_static_metacall, 0, 0}
};


const QMetaObject *ces_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ces_view::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ces_view.stringdata))
        return static_cast<void*>(const_cast< ces_view*>(this));
    return QWidget::qt_metacast(_clname);
}

int ces_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void ces_view::signalSerialRxDataReceived(QByteArray _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ces_view::signalDataPacketReceived(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ces_view::signalCh1Received(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ces_view::signalCh2Received(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
