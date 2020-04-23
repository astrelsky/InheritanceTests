#include "main.hpp"
#include "no_members.hpp"
#include <cstddef>
#include <iostream>

/*
    These are practically just namespaces. The main reason for including them
    is that when they are not actually ever inherited unless they contain
    a virtual function. Because of this, when they appear in a type_info structure
    their reported offset is 0. Analyzers need to be able to determine if the
    inherited class is just a namespace.
*/

namespace no_members {

std::ptrdiff_t A::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const A& a){
    os << "A size: " << sizeof(A) << std::endl;
    return os;
}

std::ptrdiff_t B::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const B& b){
    os << "B size: " << sizeof(B) << std::endl;
    return os;
}

std::ptrdiff_t C::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const C& c){
    os << "C size: " << sizeof(C) << std::endl;
    os << "super_A: " << offset_of_base<A, C>(c) << std::endl;
    os << "super_B: " << offset_of_base<B, C>(c) << std::endl;
    return os;
}

std::ptrdiff_t D::offset_of(const int &data) const {
    return ::offset_of(this, data);
}

std::ostream& operator<< (std::ostream& os, const D& d){
    os << "D size: " << sizeof(D) << std::endl;
    os << "super_B: " << offset_of_base<B, D>(d) << std::endl;
    os << "super_A: " << offset_of_base<A, D>(d) << std::endl;
    return os;
}

static A a;
static B b;
static C c;
static D d;
static E e;

void print() {
    printTitle(" NoMembers ");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d;
}

} // no_members
