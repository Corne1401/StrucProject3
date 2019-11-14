/****************************************************************************
** Meta object code from reading C++ file 'mapgraph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Admin/mapgraph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapgraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mapGraph_t {
    QByteArrayData data[8];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapGraph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapGraph_t qt_meta_stringdata_mapGraph = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mapGraph"
QT_MOC_LITERAL(1, 9, 18), // "on_primBtn_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 21), // "on_kurskalBtn_clicked"
QT_MOC_LITERAL(4, 51, 22), // "on_dijkstraBtn_clicked"
QT_MOC_LITERAL(5, 74, 26), // "on_articulationBtn_clicked"
QT_MOC_LITERAL(6, 101, 17), // "on_DFSBtn_clicked"
QT_MOC_LITERAL(7, 119, 17) // "on_BFSBtn_clicked"

    },
    "mapGraph\0on_primBtn_clicked\0\0"
    "on_kurskalBtn_clicked\0on_dijkstraBtn_clicked\0"
    "on_articulationBtn_clicked\0on_DFSBtn_clicked\0"
    "on_BFSBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapGraph[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mapGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mapGraph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_primBtn_clicked(); break;
        case 1: _t->on_kurskalBtn_clicked(); break;
        case 2: _t->on_dijkstraBtn_clicked(); break;
        case 3: _t->on_articulationBtn_clicked(); break;
        case 4: _t->on_DFSBtn_clicked(); break;
        case 5: _t->on_BFSBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mapGraph::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_mapGraph.data,
    qt_meta_data_mapGraph,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mapGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mapGraph.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mapGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
