/****************************************************************************
** Meta object code from reading C++ file 'PensionCalculator.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../PensionCalculator.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PensionCalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN17PensionCalculatorE_t {};
} // unnamed namespace

template <> constexpr inline auto PensionCalculator::qt_create_metaobjectdata<qt_meta_tag_ZN17PensionCalculatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PensionCalculator",
        "revenuDebiteurChanged",
        "",
        "revenuCreancierChanged",
        "nombreEnfantsChanged",
        "montantPAChanged",
        "calculTermine",
        "montant",
        "details",
        "calculerPA1",
        "revenuDebiteur",
        "nombreEnfants",
        "calculerPA2",
        "revenuCreancier",
        "calculerPA3",
        "clear",
        "getDetailsCalcul",
        "montantPA",
        "TypePA",
        "PA1_CLASSIQUE",
        "PA2_ALTERNEE",
        "PA3_REDUITE"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'revenuDebiteurChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'revenuCreancierChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nombreEnfantsChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'montantPAChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'calculTermine'
        QtMocHelpers::SignalData<void(double, QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 7 }, { QMetaType::QString, 8 },
        }}),
        // Slot 'calculerPA1'
        QtMocHelpers::SlotData<void(double, int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 10 }, { QMetaType::Int, 11 },
        }}),
        // Slot 'calculerPA2'
        QtMocHelpers::SlotData<void(double, double, int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 10 }, { QMetaType::Double, 13 }, { QMetaType::Int, 11 },
        }}),
        // Slot 'calculerPA3'
        QtMocHelpers::SlotData<void(double, int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 10 }, { QMetaType::Int, 11 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'getDetailsCalcul'
        QtMocHelpers::SlotData<QString() const>(16, 2, QMC::AccessPublic, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'revenuDebiteur'
        QtMocHelpers::PropertyData<double>(10, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'revenuCreancier'
        QtMocHelpers::PropertyData<double>(13, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'nombreEnfants'
        QtMocHelpers::PropertyData<int>(11, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'montantPA'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'TypePA'
        QtMocHelpers::EnumData<enum TypePA>(18, 18, QMC::EnumFlags{}).add({
            {   19, TypePA::PA1_CLASSIQUE },
            {   20, TypePA::PA2_ALTERNEE },
            {   21, TypePA::PA3_REDUITE },
        }),
    };
    return QtMocHelpers::metaObjectData<PensionCalculator, qt_meta_tag_ZN17PensionCalculatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PensionCalculator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17PensionCalculatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17PensionCalculatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17PensionCalculatorE_t>.metaTypes,
    nullptr
} };

void PensionCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PensionCalculator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->revenuDebiteurChanged(); break;
        case 1: _t->revenuCreancierChanged(); break;
        case 2: _t->nombreEnfantsChanged(); break;
        case 3: _t->montantPAChanged(); break;
        case 4: _t->calculTermine((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->calculerPA1((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->calculerPA2((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->calculerPA3((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->clear(); break;
        case 9: { QString _r = _t->getDetailsCalcul();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PensionCalculator::*)()>(_a, &PensionCalculator::revenuDebiteurChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PensionCalculator::*)()>(_a, &PensionCalculator::revenuCreancierChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PensionCalculator::*)()>(_a, &PensionCalculator::nombreEnfantsChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PensionCalculator::*)()>(_a, &PensionCalculator::montantPAChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PensionCalculator::*)(double , QString )>(_a, &PensionCalculator::calculTermine, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<double*>(_v) = _t->getRevenuDebiteur(); break;
        case 1: *reinterpret_cast<double*>(_v) = _t->getRevenuCreancier(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->getNombreEnfants(); break;
        case 3: *reinterpret_cast<double*>(_v) = _t->getMontantPA(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRevenuDebiteur(*reinterpret_cast<double*>(_v)); break;
        case 1: _t->setRevenuCreancier(*reinterpret_cast<double*>(_v)); break;
        case 2: _t->setNombreEnfants(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *PensionCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PensionCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17PensionCalculatorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PensionCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PensionCalculator::revenuDebiteurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PensionCalculator::revenuCreancierChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PensionCalculator::nombreEnfantsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PensionCalculator::montantPAChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PensionCalculator::calculTermine(double _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
