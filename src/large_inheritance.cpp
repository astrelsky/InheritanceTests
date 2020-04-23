#include "large_inheritance.hpp"
#include "main.hpp"
#include <cstddef>
#include <iostream>

namespace large_inheritance {

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

void B::set_b_data(int data) {
    b_data = data;
}

int B::get_b_data() const {
    return b_data;
}

std::ptrdiff_t B::offset_of(const int &data) const {
    return std::abs((std::ptrdiff_t)this - (std::ptrdiff_t)&data);
}

std::ostream& operator<< (std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << std::endl;
    os << "b.b_data: " << b.offset_of(b.b_data) << std::endl;
    os << "super_A: " << offset_of_base<A, B>(b) << std::endl;
    os << "b.a_data: " << b.offset_of(b.a_data) << std::endl;
    return os;
}

void C::c_foo() {
}

void C::set_c_data(int data) {
    c_data = data;
}

int C::get_c_data() const {
    return c_data;
}

std::ptrdiff_t C::offset_of(const int &data) const {
    return std::abs((std::ptrdiff_t)this - (std::ptrdiff_t)&data);
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
    return std::abs((std::ptrdiff_t)this - (std::ptrdiff_t)&data);
}

std::ostream& operator<< (std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << std::endl;
    os << "d.d_data: " << d.offset_of(d.d_data) << std::endl;
    os << "super_A: " << offset_of_base<A, D>(d) << std::endl;
    os << "d.a_data: " << d.offset_of(d.a_data) << std::endl;
    os << "super_B: " << offset_of_base<B, D>(d) << std::endl;
    os << "d.b_data: " << d.offset_of(d.b_data) << std::endl;
    os << "super_C: " << offset_of_base<C, D>(d) << std::endl;
    os << "d.c_data: " << d.offset_of(d.c_data) << std::endl;
    os << "d.d_data: " << d.offset_of(d.d_data) << std::endl;
    return os;
}

void Z::z_foo() {
}

void Z::set_z_data(int data) {
    z_data = data;
}

int Z::get_z_data() const {
    return z_data;
}

std::ptrdiff_t Z::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const Z& z) {
    os << "Z size: " << sizeof(Z) << std::endl;
    os << "z.z_data: " << z.offset_of(z.z_data) << std::endl;
    return os;
}

void U::u_foo() {
}

void U::set_u_data(int data) {
    u_data = data;
}

int U::get_u_data() const {
    return u_data;
}

std::ptrdiff_t U::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const U& u) {
    os << "U size: " << sizeof(U) << std::endl;
    os << "u.u_data: " << u.offset_of(u.u_data) << std::endl;
    return os;
}

void Y::y_foo() {
}

void Y::set_y_data(int data) {
    y_data = data;
}

int Y::get_y_data() const {
    return y_data;
}

std::ptrdiff_t Y::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const Y& y) {
    os << "Y size: " << sizeof(Y) << std::endl;
    os << "y.y_data: " << y.offset_of(y.y_data) << std::endl;
    os << "super_U: " << offset_of_base<U, Y>(y) << std::endl;
    os << "y.y_data: " << y.offset_of(y.y_data) << std::endl;
    return os;
}

void X::x_foo() {
}

void X::set_x_data(int data) {
    x_data = data;
}

int X::get_x_data() const {
    return x_data;
}

std::ptrdiff_t X::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const X& x) {
    os << "X size: " << sizeof(X) << std::endl;
    os << "x.x_data: " << x.offset_of(x.x_data) << std::endl;
    return os;
}

void W::w_foo() {
}

void W::z_foo() {
}

void W::set_w_data(int data) {
    w_data = data;
}

int W::get_w_data() const {
    return w_data;
}

std::ptrdiff_t W::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const W& w) {
    os << "W size: " << sizeof(W) << std::endl;
    os << "w.w_data: " << w.offset_of(w.w_data) << std::endl;
    os << "super_C: " << offset_of_base<C, W>(w) << std::endl;
    os << "w.c_data: " << w.offset_of(w.c_data) << std::endl;
    os << "super_A: " << offset_of_base<A, W>(w) << std::endl;
    os << "w.a_data: " << w.offset_of(w.a_data) << std::endl;
    os << "super_B: " << offset_of_base<B, W>(w) << std::endl;
    os << "w.b_data: " << w.offset_of(w.b_data) << std::endl;
    os << "super_Z: " << offset_of_base<Z, W>(w) << std::endl;
    os << "w.z_data: " << w.offset_of(w.z_data) << std::endl;
    os << "super_Y: " << offset_of_base<Y, W>(w) << std::endl;
    os << "w.y_data: " << w.offset_of(w.y_data) << std::endl;
    os << "super_X: " << offset_of_base<X, W>(w) << std::endl;
    os << "w.x_data: " << w.offset_of(w.x_data) << std::endl;
    os << "super_U: " << offset_of_base<U, W>(w) << std::endl;
    os << "w.y_data: " << w.offset_of(w.y_data) << std::endl;
    return os;
}

void V::v_foo() {
}

void V::z_foo() {
}

void V::y_foo() {
}

void V::x_foo() {
}

void V::a_foo() {
}

void V::set_v_data(int data) {
    v_data = data;
}

int V::get_v_data() const {
    return v_data;
}

std::ptrdiff_t V::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const V& v) {
    os << "V size: " << sizeof(V) << std::endl;
    os << "v.v_data: " << v.offset_of(v.v_data) << std::endl;
    os << "super_Z: " << offset_of_base<Z, V>(v) << std::endl;
    os << "v.z_data: " << v.offset_of(v.z_data) << std::endl;
    os << "super_Y: " << offset_of_base<Y, V>(v) << std::endl;
    os << "v.y_data: " << v.offset_of(v.y_data) << std::endl;
    os << "super_X: " << offset_of_base<X, V>(v) << std::endl;
    os << "v.x_data: " << v.offset_of(v.x_data) << std::endl;
    os << "super_A: " << offset_of_base<A, V>(v) << std::endl;
    os << "v.a_data: " << v.offset_of(v.a_data) << std::endl;
    return os;
}

static A a;
static B b;
static C c;
static D d;
static U u;
static V v;
static W w;
static X x;
static Y y;
static Z z;

void print() {
    printTitle(" LargeInheritance ");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << u << std::endl;
    std::cout << v << std::endl;
    std::cout << w << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z;
}

} // large_inheritance
