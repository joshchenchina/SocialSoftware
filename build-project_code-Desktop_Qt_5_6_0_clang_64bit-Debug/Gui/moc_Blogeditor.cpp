/****************************************************************************
** Meta object code from reading C++ file 'Blogeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project/Gui/Blogeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Blogeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BlogEditor_t {
    QByteArrayData data[16];
    char stringdata0[366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlogEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlogEditor_t qt_meta_stringdata_BlogEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BlogEditor"
QT_MOC_LITERAL(1, 11, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 22), // "on_tweetButton_clicked"
QT_MOC_LITERAL(4, 59, 36), // "on_groupListWidget_itemDouble..."
QT_MOC_LITERAL(5, 96, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 113, 4), // "item"
QT_MOC_LITERAL(7, 118, 35), // "on_bloglistWidget_itemDoubleC..."
QT_MOC_LITERAL(8, 154, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(9, 174, 29), // "on_blogdeletionButton_clicked"
QT_MOC_LITERAL(10, 204, 38), // "on_commentlistWidget_itemDoub..."
QT_MOC_LITERAL(11, 243, 33), // "on_commentDeletionButton__cli..."
QT_MOC_LITERAL(12, 277, 21), // "on_blogButton_clicked"
QT_MOC_LITERAL(13, 299, 25), // "on_downloadButton_clicked"
QT_MOC_LITERAL(14, 325, 31), // "on_mediaPosts_itemDoubleClicked"
QT_MOC_LITERAL(15, 357, 8) // "onupdate"

    },
    "BlogEditor\0on_returnButton_clicked\0\0"
    "on_tweetButton_clicked\0"
    "on_groupListWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_bloglistWidget_itemDoubleClicked\0"
    "on_okButton_clicked\0on_blogdeletionButton_clicked\0"
    "on_commentlistWidget_itemDoubleClicked\0"
    "on_commentDeletionButton__clicked\0"
    "on_blogButton_clicked\0on_downloadButton_clicked\0"
    "on_mediaPosts_itemDoubleClicked\0"
    "onupdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlogEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void BlogEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlogEditor *_t = static_cast<BlogEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_returnButton_clicked(); break;
        case 1: _t->on_tweetButton_clicked(); break;
        case 2: _t->on_groupListWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_bloglistWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_okButton_clicked(); break;
        case 5: _t->on_blogdeletionButton_clicked(); break;
        case 6: _t->on_commentlistWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_commentDeletionButton__clicked(); break;
        case 8: _t->on_blogButton_clicked(); break;
        case 9: _t->on_downloadButton_clicked(); break;
        case 10: _t->on_mediaPosts_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->onupdate(); break;
        default: ;
        }
    }
}

const QMetaObject BlogEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BlogEditor.data,
      qt_meta_data_BlogEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlogEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlogEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlogEditor.stringdata0))
        return static_cast<void*>(const_cast< BlogEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BlogEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
