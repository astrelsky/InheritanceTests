#include "abstract_inheritance.hpp"
#include "main.hpp"
#include <iostream>
#include <cstddef>
#include <string>

namespace abstract_inheritance {

F::F(int dataValue) : f_data(dataValue) {
}

void F::f_foo() {}

int F::getData() const {
    return f_data;
}

std::string F::getParentName() const {
    return "F";
}

std::ptrdiff_t F::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const F& f) {
    os << f.getName() << " size: " << f.getSize() << '\n';
    os << f.getName() << " data: " << f.getData() << '\n';
    return os;
}

G::G(int dataValue) : F(dataValue) {
}

void G::g_foo() {
}

std::string G::getParentName() const {
    return "G & "+ F::getParentName();
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

std::ostream& operator<< (std::ostream& os, const G& g){
    os << *static_cast<const F*>(&g);
    os << "g.g_data: " << g.offset_of(g.g_data) << '\n';
    os << "super_F: " << offset_of_base<F, G>(g) << '\n';
    os << "g.f_data: " << g.offset_of(g.f_data) << '\n';
    return os;
}

H::H(int dataValue) : F(dataValue) {
}

void H::h_foo() {
}

std::string H::getParentName() const {
    return "H & "+ F::getParentName();
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

std::ostream& operator<< (std::ostream& os, const H& h) {
    os << *static_cast<const F*>(&h);
    os << "h.h_data: " << h.offset_of(h.h_data) << '\n';
    os << "super_F: " << offset_of_base<F, H>(h) << '\n';
    os << "h.h_data: " << h.offset_of(h.f_data) << '\n';
    return os;
}

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
    return G::getParentName()+" & "+H::getParentName();
}

std::ptrdiff_t I::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const I& i){
    os << *static_cast<const G*>(&i);
    os << *static_cast<const H*>(&i);
    os << "i.i_data: " << i.offset_of(i.i_data) << '\n';
    os << "super_G: " << offset_of_base<G, I>(i) << '\n';
    os << "i.g_data: " << i.offset_of(i.g_data) << '\n';
    os << "super_H: " << offset_of_base<H, I>(i) << '\n';
    os << "i.h_data: " << i.offset_of(i.h_data) << '\n';
    return os;
}

G g(1);
static H h(2);
static I i(3);

void print() {
    printTitle(" AbstractInheritance ");
    std::cout << g << '\n';
    std::cout << h << '\n';
    std::cout << i;
    std::cout.flush();
}

} // abstract_inheritance
