#include "main.hpp"
#include "interfaces.hpp"
#include "printable.hpp"
#include <iostream>

namespace interfaces {

void E::aFoo() const {
    std::cout << "E::aFoo\n";
}

void E::bFoo() const {
    std::cout << "E::bFoo\n";
}

void E::cFoo() const {
    std::cout << "E::cFoo\n";
}

void E::dFoo() const {
    std::cout << "E::dFoo\n";
}

void F::aFoo() const {
    std::cout << "F::aFoo\n";
}

void F::bFoo() const {
    std::cout << "F::bFoo\n";
}

void F::cFoo() const {
    std::cout << "F::cFoo\n";
}

void F::dFoo() const {
    std::cout << "F::dFoo\n";
}

static void doAfoo(const A *a) {
    a->aFoo();
}

static void doBfoo(const B *b) {
    b->bFoo();
}

static void doCfoo(const C *c) {
    c->cFoo();
}

static void doDfoo(const D *d) {
    d->dFoo();
}

static class : Printable {

    void print() const {
        E e;
        F f;
        printTitle(" Interfaces ");
        doAfoo(&e);
        doAfoo(&f);
        doBfoo(&e);
        doBfoo(&f);
        doCfoo(&e);
        doCfoo(&f);
        doDfoo(&e);
        doDfoo(&f);
    }
} printer;

} // interfaces
