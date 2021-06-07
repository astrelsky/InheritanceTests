#include "no_members.hpp"
#include "main.hpp"
#include "printable.hpp"
#include "serializable.hpp"
#include <cstddef>
#include <iostream>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

/*
    These are practically just namespaces. The main reason for including them
    is that when they are not actually ever inherited unless they contain
    a virtual function. Because of this, when they appear in a type_info structure
    their reported offset is 0. Analyzers need to be able to determine if the
    inherited class is just a namespace.
*/

namespace no_members {

std::ptrdiff_t A::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const A& a) {
    os << "A size: " << sizeof(A) << '\n';
    return os;
}

#if SERIALIZE
void A::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    node.put("size", sizeof(A));
    tree.add_child("A", node);
}
#endif

std::ptrdiff_t B::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const B& b) {
    os << "B size: " << sizeof(B) << '\n';
    return os;
}

#if SERIALIZE
void B::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    node.put("size", sizeof(B));
    tree.add_child("B", node);
}
#endif

std::ptrdiff_t C::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const C& c) {
    os << "C size: " << sizeof(C) << '\n';
    os << "super_A: " << offset_of_base<A, C>(c) << '\n';
    os << "super_B: " << offset_of_base<B, C>(c) << '\n';
    return os;
}

#if SERIALIZE
void C::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(C));
    offsets.put("super_A", offset_of_base<A, C>(*this));
    offsets.put("super_B", offset_of_base<B, C>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("C", node);
}
#endif

std::ptrdiff_t D::offset_of(const int& data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<<(std::ostream& os, const D& d) {
    os << "D size: " << sizeof(D) << '\n';
    os << "super_B: " << offset_of_base<B, D>(d) << '\n';
    os << "super_A: " << offset_of_base<A, D>(d) << '\n';
    return os;
}

#if SERIALIZE
void D::serialize(boost::property_tree::ptree& tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(D));
    offsets.put("super_A", offset_of_base<A, D>(*this));
    offsets.put("super_B", offset_of_base<B, D>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("D", node);
}
#endif

static A a;
static B b;
static C c;
static D d;
static E e;

static class Printer : public Printable, public Serializable {

    void print() const override;

#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const override;
#endif
} printer;

void Printer::print() const {
    printTitle(" NoMembers ");
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
    tree.add_child("no_members", node);
}
#endif

} // namespace no_members
