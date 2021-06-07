#include "no_virtual_functions.hpp"
#include "main.hpp"
#include "printable.hpp"
#include "serializable.hpp"
#include <cstddef>
#include <iostream>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace no_virtual_functions {

A::A(int value) : a_data(value) {
}

int A::getData() const {
    return a_data;
}

void A::setData(int value) {
    a_data = value;
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
    node.add_child("offsets", offsets);
    tree.add_child("A", node);
}
#endif

B::B(int value) : b_data(value) {
}

int B::getData() const {
    return b_data;
}

void B::setData(int value) {
    b_data = value;
}

std::ptrdiff_t B::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << '\n';
    os << "b.b_data: " << b.offset_of(b.b_data) << '\n';
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

C::C(int value) : c_data(value) {
}

int C::getData() const {
    return c_data;
}

void C::setData(int value) {
    c_data = value;
}

std::ptrdiff_t C::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const C& c) {
    os << "C size: " << sizeof(C) << '\n';
    os << "C.c_data: " << c.offset_of(c.c_data) << '\n';
    os << "super_B: " << offset_of_base<B, C>(c) << '\n';
    os << "C.b_data: " << c.offset_of(c.b_data) << '\n';
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
    offsets.put("super_B", offset_of_base<B, C>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("C", node);
}
#endif

D::D(int value) : d_data(value) {
}

int D::getData() const {
    return d_data;
}

void D::setData(int value) {
    d_data = value;
}

std::ptrdiff_t D::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << '\n';
    os << "d.d_data: " << d.offset_of(d.d_data) << '\n';
    os << "super_B size: " << sizeof(D::B) - sizeof(B::A) << '\n';
    os << "super_B: " << offset_of_base<B, D>(d) << '\n';
    os << "d.b_data: " << d.offset_of(d.b_data) << '\n';
    os << "super_B::A: " << offset_of_base<A, D::B>(d) << '\n';
    os << "super_B.a_data: " << d.offset_of(d.a_data) << '\n';
    return os;
}

#if SERIALIZE
void D::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(D));
    offsets.put("d_data", offset_of(d_data));
    offsets.put("super_A", offset_of_base<A, D>(*this));
    offsets.put("super_B", offset_of_base<B, D>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("D", node);
}
#endif

static A a(0);
static B b(1);
static C c(2);
static D d(3);

static class Printer : public Printable, public Serializable {

    void print() const override;

#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const override;
#endif
} printer;

void Printer::print() const {
    printTitle(" NoVirtualFunctions ");
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
    tree.add_child("no_virtual_functions", node);
}
#endif

} // namespace no_virtual_functions
