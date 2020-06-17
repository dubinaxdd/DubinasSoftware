/****************************************************************************
** Meta object code from reading C++ file 'MainModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MathModeling/MainModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainModel_t {
    QByteArrayData data[19];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainModel_t qt_meta_stringdata_MainModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MainModel"
QT_MOC_LITERAL(1, 10, 21), // "sendPretreatmentEnded"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "time"
QT_MOC_LITERAL(4, 38, 17), // "sendCountingEnded"
QT_MOC_LITERAL(5, 56, 11), // "CountFinded"
QT_MOC_LITERAL(6, 68, 10), // "PointCount"
QT_MOC_LITERAL(7, 79, 6), // "Method"
QT_MOC_LITERAL(8, 86, 6), // "method"
QT_MOC_LITERAL(9, 93, 15), // "RandomizePoints"
QT_MOC_LITERAL(10, 109, 10), // "pointCount"
QT_MOC_LITERAL(11, 120, 12), // "Pretreatment"
QT_MOC_LITERAL(12, 133, 8), // "Counting"
QT_MOC_LITERAL(13, 142, 17), // "receiveMousePress"
QT_MOC_LITERAL(14, 160, 19), // "receiveMouseRelease"
QT_MOC_LITERAL(15, 180, 16), // "receiveMouseMove"
QT_MOC_LITERAL(16, 197, 1), // "X"
QT_MOC_LITERAL(17, 199, 1), // "Y"
QT_MOC_LITERAL(18, 201, 22) // "receiveFormSizeChanged"

    },
    "MainModel\0sendPretreatmentEnded\0\0time\0"
    "sendCountingEnded\0CountFinded\0PointCount\0"
    "Method\0method\0RandomizePoints\0pointCount\0"
    "Pretreatment\0Counting\0receiveMousePress\0"
    "receiveMouseRelease\0receiveMouseMove\0"
    "X\0Y\0receiveFormSizeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    4,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x0a /* Public */,
      14,    0,   81,    2, 0x0a /* Public */,
      15,    2,   82,    2, 0x0a /* Public */,
      18,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    5,    3,    6,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,

       0        // eod
};

void MainModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainModel *_t = static_cast<MainModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPretreatmentEnded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendCountingEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Method(*)>(_a[4]))); break;
        case 2: _t->RandomizePoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Pretreatment((*reinterpret_cast< Method(*)>(_a[1]))); break;
        case 4: _t->Counting((*reinterpret_cast< Method(*)>(_a[1]))); break;
        case 5: _t->receiveMousePress(); break;
        case 6: _t->receiveMouseRelease(); break;
        case 7: _t->receiveMouseMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->receiveFormSizeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainModel::sendPretreatmentEnded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainModel::*)(int , int , int , Method );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainModel::sendCountingEnded)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MainModel.data,
    qt_meta_data_MainModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void MainModel::sendPretreatmentEnded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainModel::sendCountingEnded(int _t1, int _t2, int _t3, Method _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
