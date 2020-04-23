#include "main.hpp"
#include "non_diamond.hpp"
#include <cstddef>
#include <iostream>

namespace non_diamond {

void A::a_foo() {
}

void A::set_a_data(int data) {
    hidden_a_data = data;
}
int A::get_a_data() const {
    return hidden_a_data;
}
std::ptrdiff_t A::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const A& a) {
    os << "A size: " << sizeof(A) << std::endl;
    os << "a.a_data: " << a.offset_of(a.a_data) << std::endl;
    return os;
}

void B::b_foo() {
}

const int &B::getADataRef() const {
    return a_data;
}

void B::set_b_data(int data) {
    b_data = data;
}

int B::get_b_data() const {
    return b_data;
}

std::ptrdiff_t B::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << std::endl;
    os << "b.b_data: " << b.offset_of(b.b_data) << std::endl;
    return os;
}

void C::c_foo() {
}

const int &C::getADataRef() const {
    return a_data;
}

void C::set_c_data(int data) {
    c_data = data;
}

int C::get_c_data() const {
    return c_data;
}

std::ptrdiff_t C::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const C& c) {
    os << "C size: " << sizeof(C) << std::endl;
    os << "C.c_data: " << c.offset_of(c.c_data) << std::endl;
    os << "super_A: " << offset_of_base<A, C>(c) << std::endl;
    os << "C.a_data: " << c.offset_of(c.a_data) << std::endl;
    return os;
}

void D::d_foo() {
}

void D::set_d_data(int data) {
    d_data = data;
}

int D::get_d_data() const {
    return d_data;
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
    os << "super_B.a_data: " << d.offset_of(static_cast<B>(d).getADataRef()) << std::endl;
    os << "super_C size: " << sizeof(D::C) << std::endl;
    os << "super_C: " << offset_of_base<C, D>(d) << std::endl;
    os << "d.c_data: " << d.offset_of(d.c_data) << std::endl;
    os << "super_C::A: " << offset_of_base<C, D>(d) + offset_of_base<A, D::C>(d) << std::endl;
    os << "super_C.a_data: " << d.offset_of(static_cast<C>(d).getADataRef()) << std::endl;
    return os;
}

static A a;
static B b;
static C c;
static D d;

void print() {
    printTitle(" NonDiamond ");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d;
}

} // non_diamond
