#include "interfaces.hpp"
#include "main.hpp"
#include "printable.hpp"
#include <iostream>

namespace interfaces {

namespace virtual_functions {

void E::aFoo() const {
    std::cout << "virtual_functions::E::aFoo\n";
}

void E::bFoo() const {
    std::cout << "virtual_functions::E::bFoo\n";
}

void E::cFoo() const {
    std::cout << "virtual_functions::E::cFoo\n";
}

void E::dFoo() const {
    std::cout << "virtual_functions::E::dFoo\n";
}

void F::aFoo() const {
    std::cout << "virtual_functions::F::aFoo\n";
}

void F::bFoo() const {
    std::cout << "virtual_functions::F::bFoo\n";
}

void F::cFoo() const {
    std::cout << "virtual_functions::F::cFoo\n";
}

void F::dFoo() const {
    std::cout << "virtual_functions::F::dFoo\n";
}

} // virtual_functions

namespace non_virtual_functions {

void A::aFoo() const {
    std::cout << "non_virtual_functions::A::aFoo\n";
}

void B::bFoo() const {
    std::cout << "non_virtual_functions::B::bFoo\n";
}

void C::cFoo() const {
    std::cout << "non_virtual_functions::C::cFoo\n";
}

void D::dFoo() const {
    std::cout << "non_virtual_functions::D::dFoo\n";
}

void E::eFoo() const {
    std::cout << "non_virtual_functions::E::eFoo\n";
}

void F::fFoo() const {
    std::cout << "non_virtual_functions::F::fFoo\n";
}

} // non_virtual_functions

template <class T>
static void doAfoo(const T *a) {
    a->aFoo();
}

template <class T>
static void doBfoo(const T *b) {
    b->bFoo();
}

template <class T>
static void doCfoo(const T *c) {
    c->cFoo();
}

template <class T>
static void doDfoo(const T *d) {
    d->dFoo();
}

static class : public Printable {

    void print() const override {
        virtual_functions::E virtualE;
        virtual_functions::F virtualF;
        non_virtual_functions::E nonVirtualE;
        non_virtual_functions::F nonVirtualF;
        printTitle(" Interfaces ");
        doAfoo(&virtualE);
        doAfoo(&virtualF);
        doBfoo(&virtualE);
        doBfoo(&virtualF);
        doCfoo(&virtualE);
        doCfoo(&virtualF);
        doDfoo(&virtualE);
        doDfoo(&virtualF);
        doAfoo(&nonVirtualE);
        doAfoo(&nonVirtualF);
        doBfoo(&nonVirtualE);
        doBfoo(&nonVirtualF);
        doCfoo(&nonVirtualE);
        doCfoo(&nonVirtualF);
        doDfoo(&nonVirtualE);
        doDfoo(&nonVirtualF);
        // don't delete the type info
        std::cout << typeid(nonVirtualE).name() << '\n';
    }
} printer;

} // namespace interfaces
