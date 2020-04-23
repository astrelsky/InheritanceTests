#include "interfaces.hpp"
#include <iostream>

namespace interfaces {

void E::aFoo() {
}

void E::bFoo() {
}

void E::cFoo() {
}

void E::dFoo() {
}

void E::print() {
    aFoo();
    bFoo();
    cFoo();
    dFoo();
}

void print() {
    E e;
    e.print();
}

} // interfaces
