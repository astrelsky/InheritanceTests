#include "main.hpp"
#include "no_virtual_functions.hpp"
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
    os << "A size: " << sizeof(A) << std::endl;
    os << "a.a_data: " << a.offset_of(a.a_data) << std::endl;
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
    os << "B size: " << sizeof(B) << std::endl;
    os << "b.b_data: " << b.offset_of(b.b_data) << std::endl;
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
    os << "C size: " << sizeof(C) << std::endl;
    os << "C.c_data: " << c.offset_of(c.c_data) << std::endl;
    os << "super_B: " << offset_of_base<B, C>(c) << std::endl;
    os << "C.b_data: " << c.offset_of(c.b_data) << std::endl;
    os << "super_A: " << offset_of_base<A, C>(c) << std::endl;
    os << "C.a_data: " << c.offset_of(c.a_data) << std::endl;
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
    os << "D size: " << sizeof(D) << std::endl;
    os << "d.d_data: " << d.offset_of(d.d_data) << std::endl;
    os << "super_B size: " << sizeof(D::B)-sizeof(B::A) << std::endl;
    os << "super_B: " << offset_of_base<B, D>(d) << std::endl;
    os << "d.b_data: " << d.offset_of(d.b_data) << std::endl;
    os << "super_B::A: " << offset_of_base<A, D::B>(d) << std::endl;
    os << "super_B.a_data: " << d.offset_of(d.a_data) << std::endl;
    return os;
}

static A a(0);
static B b(1);
static C c(2);
static D d(3);

void print() {
    printTitle(" NoVirtualFunctions ");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d;
}

} // no_virtual_functions
