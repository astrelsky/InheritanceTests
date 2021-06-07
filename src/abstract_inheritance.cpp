#include "abstract_inheritance.hpp"
#include "main.hpp"
#include "printable.hpp"
#include <cstddef>
#include <iostream>
#include <string>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace abstract_inheritance {

F::F(int dataValue) : f_data(dataValue) {
}

void F::f_foo() {
}

int F::getData() const {
    return f_data;
}

std::string F::getParentName() const {
    return "F";
}

std::ptrdiff_t F::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream &operator<<(std::ostream &os, const F &f) {
    os << f.getName() << " size: " << f.getSize() << '\n';
    os << f.getName() << " data: " << f.getData() << '\n';
    return os;
}

#if SERIALIZE
void F::serialize(boost::property_tree::ptree &tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(F));
    offsets.put("f_data", offset_of(f_data));
    node.add_child("offsets", offsets);
    tree.add_child("F", node);
}
#endif

G::G(int dataValue) : F(dataValue) {
}

void G::g_foo() {
}

std::string G::getParentName() const {
    return "G & " + F::getParentName();
}

std::string G::getName() const {
    return "G";
}

std::size_t G::getSize() const {
    return sizeof(G);
}

std::ptrdiff_t G::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream &operator<<(std::ostream &os, const G &g) {
    os << *static_cast<const F *>(&g);
    os << "g.g_data: " << g.offset_of(g.g_data) << '\n';
    os << "super_F: " << offset_of_base<F, G>(g) << '\n';
    os << "g.f_data: " << g.offset_of(g.f_data) << '\n';
    return os;
}

#if SERIALIZE
void G::serialize(boost::property_tree::ptree &tree) const {
    F::serialize(tree);
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(G));
    offsets.put("g_data", offset_of(g_data));
    offsets.put("super_F", offset_of_base<F, G>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("G", node);
}
#endif

H::H(int dataValue) : F(dataValue) {
}

void H::h_foo() {
}

std::string H::getParentName() const {
    return "H & " + F::getParentName();
}

std::string H::getName() const {
    return "H";
}

std::size_t H::getSize() const {
    return sizeof(H);
}

std::ptrdiff_t H::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream &operator<<(std::ostream &os, const H &h) {
    os << *static_cast<const F *>(&h);
    os << "h.h_data: " << h.offset_of(h.h_data) << '\n';
    os << "super_F: " << offset_of_base<F, H>(h) << '\n';
    os << "h.h_data: " << h.offset_of(h.f_data) << '\n';
    return os;
}

#if SERIALIZE
void H::serialize(boost::property_tree::ptree &tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(H));
    offsets.put("h_data", offset_of(h_data));
    offsets.put("super_F", offset_of_base<F, H>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("H", node);
}
#endif

I::I(int dataValue) : G(dataValue), H(dataValue) {
}

void I::i_foo() {
}

std::size_t I::getSize() const {
    return sizeof(I);
}

std::string I::getName() const {
    return "I";
}

std::string I::getParentName() const {
    return G::getParentName() + " & " + H::getParentName();
}

std::ptrdiff_t I::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream &operator<<(std::ostream &os, const I &i) {
    os << *static_cast<const G *>(&i);
    os << *static_cast<const H *>(&i);
    os << "i.i_data: " << i.offset_of(i.i_data) << '\n';
    os << "super_G: " << offset_of_base<G, I>(i) << '\n';
    os << "i.g_data: " << i.offset_of(i.g_data) << '\n';
    os << "super_H: " << offset_of_base<H, I>(i) << '\n';
    os << "i.h_data: " << i.offset_of(i.h_data) << '\n';
    return os;
}

#if SERIALIZE
void I::serialize(boost::property_tree::ptree &tree) const {
    boost::property_tree::ptree node;
    boost::property_tree::ptree offsets;
    node.put("size", sizeof(I));
    offsets.put("i_data", offset_of(i_data));
    offsets.put("super_G", offset_of_base<G, I>(*this));
    offsets.put("super_H", offset_of_base<H, I>(*this));
    node.add_child("offsets", offsets);
    tree.add_child("I", node);
}
#endif

G g(1);
static H h(2);
static I i(3);

static class Printer : public Printable, public Serializable {

    void print() const override;

#if SERIALIZE
    void serialize(boost::property_tree::ptree &tree) const;
#endif
} printer;

void Printer::print() const {
    printTitle(" AbstractInheritance ");
    std::cout << g << '\n';
    std::cout << h << '\n';
    std::cout << i;
    std::cout.flush();
}

#if SERIALIZE
void Printer::serialize(boost::property_tree::ptree &tree) const {
    boost::property_tree::ptree node;
    g.serialize(node);
    h.serialize(node);
    i.serialize(node);
    tree.add_child("abstract_inheritance", node);
}
#endif

} // namespace abstract_inheritance
