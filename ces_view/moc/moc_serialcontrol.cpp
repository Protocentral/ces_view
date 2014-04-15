/****************************************************************************
** Meta object code from reading C++ file 'serialcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialProcessThread_t {
    QByteArrayData data[10];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SerialProcessThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SerialProcessThread_t qt_meta_stringdata_SerialProcessThread = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 20),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 15),
QT_MOC_LITERAL(4, 58, 16),
QT_MOC_LITERAL(5, 75, 11),
QT_MOC_LITERAL(6, 87, 13),
QT_MOC_LITERAL(7, 101, 13),
QT_MOC_LITERAL(8, 115, 5),
QT_MOC_LITERAL(9, 121, 12)
    },
    "SerialProcessThread\0signalPacketReceived\0"
    "\0CES_Pkt_PktType\0CES_Pkt_DestAddr\0"
    "packet_data\0packet_length\0slotInsertRxQ\0"
    "items\0items_length\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialProcessThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    2,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UShort, QMetaType::QByteArray, QMetaType::UShort,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    8,    9,

       0        // eod
};

void SerialProcessThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialProcessThread *_t = static_cast<SerialProcessThread *>(_o);
        switch (_id) {
        case 0: _t->signalPacketReceived((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 1: _t->slotInsertRxQ((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialProcessThread::*_t)(quint8 , quint16 , QByteArray , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialProcessThread::signalPacketReceived)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SerialProcessThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SerialProcessThread.data,
      qt_meta_data_SerialProcessThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *SerialProcessThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialProcessThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialProcessThread.stringdata))
        return static_cast<void*>(const_cast< SerialProcessThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SerialProcessThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SerialProcessThread::signalPacketReceived(quint8 _t1, quint16 _t2, QByteArray _t3, quint16 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
