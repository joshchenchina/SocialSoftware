/****************************************************************************
** Meta object code from reading C++ file 'AdminMainMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project/Gui/AdminMainMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminMainMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminMainMenu_t {
    QByteArrayData data[7];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminMainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminMainMenu_t qt_meta_stringdata_AdminMainMenu = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AdminMainMenu"
QT_MOC_LITERAL(1, 14, 21), // "on_createUser_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_newBlogButton_clicked"
QT_MOC_LITERAL(4, 62, 7), // "checked"
QT_MOC_LITERAL(5, 70, 23), // "on_LogOutButton_pressed"
QT_MOC_LITERAL(6, 94, 25) // "on_addUsersButton_clicked"

    },
    "AdminMainMenu\0on_createUser_clicked\0"
    "\0on_newBlogButton_clicked\0checked\0"
    "on_LogOutButton_pressed\0"
    "on_addUsersButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminMainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminMainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminMainMenu *_t = static_cast<AdminMainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_createUser_clicked(); break;
        case 1: _t->on_newBlogButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_LogOutButton_pressed(); break;
        case 3: _t->on_addUsersButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AdminMainMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdminMainMenu.data,
      qt_meta_data_AdminMainMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminMainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminMainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminMainMenu.stringdata0))
        return static_cast<void*>(const_cast< AdminMainMenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdminMainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
