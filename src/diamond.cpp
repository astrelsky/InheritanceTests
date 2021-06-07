#include "diamond.hpp"
#include "main.hpp"
#include "printable.hpp"
#include "serializable.hpp"
#include <cstddef>
#include <iostream>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace diamond {

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
    return ::offset_of(this, data);
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
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const C& c) {
    os << "C size: " << sizeof(B) << '\n';
    os << "c.c_data: " << c.offset_of(c.c_data) << '\n';
    os << "super_A: " << offset_of_base<A, C>(c) << '\n';
    os << "c.a_data: " << c.offset_of(c.a_data) << '\n';
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
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << '\n';
    os << "d.d_data: " << d.offset_of(d.d_data) << '\n';
    os << "super_B: " << offset_of_base<B, D>(d) << '\n';
    os << "d.b_data: " << d.offset_of(d.b_data) << '\n';
    os << "super_A: " << offset_of_base<A, D>(d) << '\n';
    os << "d.a_data: " << d.offset_of(d.a_data) << '\n';
    os << "super_C: " << offset_of_base<C, D>(d) << '\n';
    os << "d.c_data: " << d.offset_of(d.c_data) << '\n';
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

static A a;
static B b;
static C c;
static D d;

static class Printer : public Printable, public Serializable {

    void print() const override;

#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const override;
#endif
} printer;

void Printer::print() const {
    printTitle(" Diamond ");
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d;
    std::cout.flush();
}

#if SERIALIZE
void Printer::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    a.serialize(node);
    b.serialize(node);
    c.serialize(node);
    d.serialize(node);
    tree.add_child("diamond", node);
}
#endif

} // namespace diamond
