#include "main.hpp"
#include "no_virtual_functions.hpp"
#include "printable.hpp"
#include <cstddef>
#include <iostream>

namespace no_virtual_functions {

A::A(int value) : a_data(value) {
}

int A::getData() const {
    return a_data;
}

void A::setData(int value) {
    a_data = value;
}

std::ptrdiff_t A::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const A& a) {
    os << "A size: " << sizeof(A) << '\n';
    os << "a.a_data: " << a.offset_of(a.a_data) << '\n';
    return os;
}

B::B(int value) : b_data(value) {
}

int B::getData() const {
    return b_data;
}

void B::setData(int value) {
    b_data = value;
}

std::ptrdiff_t B::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << '\n';
    os << "b.b_data: " << b.offset_of(b.b_data) << '\n';
    return os;
}


C::C(int value) : c_data(value) {
}

int C::getData() const {
    return c_data;
}

void C::setData(int value) {
    c_data = value;
}

std::ptrdiff_t C::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const C& c) {
    os << "C size: " << sizeof(C) << '\n';
    os << "C.c_data: " << c.offset_of(c.c_data) << '\n';
    os << "super_B: " << offset_of_base<B, C>(c) << '\n';
    os << "C.b_data: " << c.offset_of(c.b_data) << '\n';
    os << "super_A: " << offset_of_base<A, C>(c) << '\n';
    os << "C.a_data: " << c.offset_of(c.a_data) << '\n';
    return os;
}

D::D(int value) : d_data(value) {
}

int D::getData() const {
    return d_data;
}

void D::setData(int value) {
    d_data = value;
}

std::ptrdiff_t D::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << '\n';
    os << "d.d_data: " << d.offset_of(d.d_data) << '\n';
    os << "super_B size: " << sizeof(D::B)-sizeof(B::A) << '\n';
    os << "super_B: " << offset_of_base<B, D>(d) << '\n';
    os << "d.b_data: " << d.offset_of(d.b_data) << '\n';
    os << "super_B::A: " << offset_of_base<A, D::B>(d) << '\n';
    os << "super_B.a_data: " << d.offset_of(d.a_data) << '\n';
    return os;
}

static A a(0);
static B b(1);
static C c(2);
static D d(3);

static class : Printable {

    void print() const {
        printTitle(" NoVirtualFunctions ");
        std::cout << a << '\n';
        std::cout << b << '\n';
        std::cout << c << '\n';
        std::cout << d;
        std::cout.flush();
    }
} printer;

} // no_virtual_functions
