#include "large_inheritance.hpp"
#include "main.hpp"
#include "printable.hpp"
#include "serializable.hpp"
#include <cstddef>
#include <iostream>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace large_inheritance {

W::W() {
    std::cout << "W() called" << std::endl;
}

W::~W() {
    std::cout << "~W() called" << std::endl;
}

void A::a_foo() {
}

void A::set_a_data(int data) {
    hidden_a_data = data;
}

int A::get_a_data() const {
    return hidden_a_data;
}

std::ptrdiff_t A::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const A& a) {
    os << "A size: " << sizeof(A) << '\n';
    os << "a.a_data: " << a.offset_of(a.a_data) << '\n';
    return os;
}

#if SERIALIZE
void A::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(A));
    offsets.put("a_data", offset_of(a_data));
    offsets.put("hidden_a_data", offset_of(hidden_a_data));
    node.add_child("offsets", offsets);
    tree.add_child("A", node);
}
#endif

void B::b_foo() {
}

void B::set_b_data(int data) {
    b_data = data;
}

int B::get_b_data() const {
    return b_data;
}

std::ptrdiff_t B::offset_of(const int& data) const {
    return std::abs((std::ptrdiff_t) this - (std::ptrdiff_t) &data);
}

std::ostream& operator<<(std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << '\n';
    os << "b.b_data: " << b.offset_of(b.b_data) << '\n';
    os << "super_A: " << offset_of_base<A, B>(b) << '\n';
    os << "b.a_data: " << b.offset_of(b.a_data) << '\n';
    return os;
}

#if SERIALIZE
void B::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(B));
    offsets.put("b_data", offset_of(b_data));
    offsets.put("super_A", offset_of_base<A, B>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("B", node);
}
#endif

void C::c_foo() {
}

void C::set_c_data(int data) {
    c_data = data;
}

int C::get_c_data() const {
    return c_data;
}

std::ptrdiff_t C::offset_of(const int& data) const {
    return std::abs((std::ptrdiff_t) this - (std::ptrdiff_t) &data);
}

std::ostream& operator<<(std::ostream& os, const C& c) {
    os << "C size: " << sizeof(C) << '\n';
    os << "C.c_data: " << c.offset_of(c.c_data) << '\n';
    os << "super_A: " << offset_of_base<A, C>(c) << '\n';
    os << "C.a_data: " << c.offset_of(c.a_data) << '\n';
    return os;
}

#if SERIALIZE
void C::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(C));
    offsets.put("c_data", offset_of(c_data));
    offsets.put("super_A", offset_of_base<A, C>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("C", node);
}
#endif

void D::d_foo() {
}
void D::set_d_data(int data) {
    d_data = data;
}

int D::get_d_data() const {
    return d_data;
}

std::ptrdiff_t D::offset_of(const int& data) const {
    return std::abs((std::ptrdiff_t) this - (std::ptrdiff_t) &data);
}

std::ostream& operator<<(std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << '\n';
    os << "d.d_data: " << d.offset_of(d.d_data) << '\n';
    os << "super_A: " << offset_of_base<A, D>(d) << '\n';
    os << "d.a_data: " << d.offset_of(d.a_data) << '\n';
    os << "super_B: " << offset_of_base<B, D>(d) << '\n';
    os << "d.b_data: " << d.offset_of(d.b_data) << '\n';
    os << "super_C: " << offset_of_base<C, D>(d) << '\n';
    os << "d.c_data: " << d.offset_of(d.c_data) << '\n';
    os << "d.d_data: " << d.offset_of(d.d_data) << '\n';
    return os;
}

#if SERIALIZE
void D::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(D));
    offsets.put("d_data", offset_of(d_data));
    offsets.put("super_B", offset_of_base<B, D>(*this));
    offsets.put("super_C", offset_of_base<C, D>(*this));
    offsets.put("super_A", offset_of_base<A, D>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("D", node);
}
#endif

void Z::z_foo() {
}

void Z::set_z_data(int data) {
    z_data = data;
}

int Z::get_z_data() const {
    return z_data;
}

std::ptrdiff_t Z::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const Z& z) {
    os << "Z size: " << sizeof(Z) << '\n';
    os << "z.z_data: " << z.offset_of(z.z_data) << '\n';
    return os;
}

#if SERIALIZE
void Z::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(Z));
    offsets.put("z_data", offset_of(z_data));
    node.add_child("offsets", offsets);
    tree.add_child("Z", node);
}
#endif

void U::u_foo() {
}

void U::set_u_data(int data) {
    u_data = data;
}

int U::get_u_data() const {
    return u_data;
}

std::ptrdiff_t U::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const U& u) {
    os << "U size: " << sizeof(U) << '\n';
    os << "u.u_data: " << u.offset_of(u.u_data) << '\n';
    return os;
}

#if SERIALIZE
void U::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(U));
    offsets.put("u_data", offset_of(u_data));
    node.add_child("offsets", offsets);
    tree.add_child("U", node);
}
#endif

void Y::y_foo() {
}

void Y::set_y_data(int data) {
    y_data = data;
}

int Y::get_y_data() const {
    return y_data;
}

std::ptrdiff_t Y::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const Y& y) {
    os << "Y size: " << sizeof(Y) << '\n';
    os << "y.y_data: " << y.offset_of(y.y_data) << '\n';
    os << "super_U: " << offset_of_base<U, Y>(y) << '\n';
    os << "y.y_data: " << y.offset_of(y.y_data) << '\n';
    return os;
}

#if SERIALIZE
void Y::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(Y));
    offsets.put("y_data", offset_of(y_data));
    offsets.put("super_U", offset_of_base<U, Y>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("Y", node);
}
#endif

void X::x_foo() {
}

void X::set_x_data(int data) {
    x_data = data;
}

int X::get_x_data() const {
    return x_data;
}

std::ptrdiff_t X::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const X& x) {
    os << "X size: " << sizeof(X) << '\n';
    os << "x.x_data: " << x.offset_of(x.x_data) << '\n';
    return os;
}

#if SERIALIZE
void X::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(X));
    offsets.put("x_data", offset_of(x_data));
    node.add_child("offsets", offsets);
    tree.add_child("X", node);
}
#endif

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

std::ptrdiff_t W::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const W& w) {
    os << "W size: " << sizeof(W) << '\n';
    os << "w.w_data: " << w.offset_of(w.w_data) << '\n';
    os << "super_C: " << offset_of_base<C, W>(w) << '\n';
    os << "w.c_data: " << w.offset_of(w.c_data) << '\n';
    os << "super_A: " << offset_of_base<A, W>(w) << '\n';
    os << "w.a_data: " << w.offset_of(w.a_data) << '\n';
    os << "super_B: " << offset_of_base<B, W>(w) << '\n';
    os << "w.b_data: " << w.offset_of(w.b_data) << '\n';
    os << "super_Z: " << offset_of_base<Z, W>(w) << '\n';
    os << "w.z_data: " << w.offset_of(w.z_data) << '\n';
    os << "super_Y: " << offset_of_base<Y, W>(w) << '\n';
    os << "w.y_data: " << w.offset_of(w.y_data) << '\n';
    os << "super_X: " << offset_of_base<X, W>(w) << '\n';
    os << "w.x_data: " << w.offset_of(w.x_data) << '\n';
    os << "super_U: " << offset_of_base<U, W>(w) << '\n';
    os << "w.y_data: " << w.offset_of(w.y_data) << '\n';
    return os;
}

#if SERIALIZE
void W::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(W));
    offsets.put("w_data", offset_of(w_data));
    offsets.put("super_C", offset_of_base<C, W>(*this));
    offsets.put("super_A", offset_of_base<A, W>(*this));
    offsets.put("super_B", offset_of_base<B, W>(*this));
    offsets.put("super_Z", offset_of_base<Z, W>(*this));
    offsets.put("super_Y", offset_of_base<Y, W>(*this));
    offsets.put("super_X", offset_of_base<X, W>(*this));
    offsets.put("super_U", offset_of_base<U, W>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("W", node);
}
#endif

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

std::ptrdiff_t V::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const V& v) {
    os << "V size: " << sizeof(V) << '\n';
    os << "v.v_data: " << v.offset_of(v.v_data) << '\n';
    os << "super_Z: " << offset_of_base<Z, V>(v) << '\n';
    os << "v.z_data: " << v.offset_of(v.z_data) << '\n';
    os << "super_Y: " << offset_of_base<Y, V>(v) << '\n';
    os << "v.y_data: " << v.offset_of(v.y_data) << '\n';
    os << "super_X: " << offset_of_base<X, V>(v) << '\n';
    os << "v.x_data: " << v.offset_of(v.x_data) << '\n';
    os << "super_A: " << offset_of_base<A, V>(v) << '\n';
    os << "v.a_data: " << v.offset_of(v.a_data) << '\n';
    return os;
}

#if SERIALIZE
void V::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(V));
    offsets.put("v_data", offset_of(v_data));
    offsets.put("super_Z", offset_of_base<Z, V>(*this));
    offsets.put("super_Y", offset_of_base<Y, V>(*this));
    offsets.put("super_X", offset_of_base<X, V>(*this));
    offsets.put("super_A", offset_of_base<A, V>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("V", node);
}
#endif

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

static class Printer : public Printable, public Serializable {

    void print() const override;

#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const override;
#endif
} printer;

void Printer::print() const {
    printTitle(" LargeInheritance ");
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    std::cout << u << '\n';
    std::cout << v << '\n';
    std::cout << w << '\n';
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z;
    std::cout.flush();
}

#if SERIALIZE
void Printer::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    a.serialize(node);
    b.serialize(node);
    c.serialize(node);
    d.serialize(node);
    u.serialize(node);
    v.serialize(node);
    w.serialize(node);
    x.serialize(node);
    y.serialize(node);
    z.serialize(node);
    tree.add_child("large_inheritance", node);
}
#endif

} // namespace large_inheritance
