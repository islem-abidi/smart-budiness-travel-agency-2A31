/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../New folder/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 29), // "on_pushButton_ajouter_clicked"
QT_MOC_LITERAL(4, 64, 31), // "on_pushButton_supprimer_clicked"
QT_MOC_LITERAL(5, 96, 32), // "on_pushButton_rechercher_clicked"
QT_MOC_LITERAL(6, 129, 22), // "on_pushButtonT_clicked"
QT_MOC_LITERAL(7, 152, 14), // "on_PDF_clicked"
QT_MOC_LITERAL(8, 167, 22), // "on_pushButtonS_clicked"
QT_MOC_LITERAL(9, 190, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(10, 214, 24), // "on_recherche_textChanged"
QT_MOC_LITERAL(11, 239, 4), // "arg1"
QT_MOC_LITERAL(12, 244, 24), // "on_lineEditR_textChanged"
QT_MOC_LITERAL(13, 269, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(14, 300, 18) // "on_Weather_clicked"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_pushButton_ajouter_clicked\0"
    "on_pushButton_supprimer_clicked\0"
    "on_pushButton_rechercher_clicked\0"
    "on_pushButtonT_clicked\0on_PDF_clicked\0"
    "on_pushButtonS_clicked\0on_pushButton_3_clicked\0"
    "on_recherche_textChanged\0arg1\0"
    "on_lineEditR_textChanged\0"
    "on_comboBox_currentTextChanged\0"
    "on_Weather_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      13,    1,   88,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_ajouter_clicked(); break;
        case 2: _t->on_pushButton_supprimer_clicked(); break;
        case 3: _t->on_pushButton_rechercher_clicked(); break;
        case 4: _t->on_pushButtonT_clicked(); break;
        case 5: _t->on_PDF_clicked(); break;
        case 6: _t->on_pushButtonS_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_recherche_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_lineEditR_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_Weather_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
