#ifndef NO_MEMBERS_HPP
#define NO_MEMBERS_HPP

#include <cstddef>

/*
    These are practically just namespaces. The main reason for including them
    is that when they are not actually ever inherited unless they contain
    a virtual function. Because of this, when they appear in a type_info structure
    their reported offset is 0. Analyzers need to be able to determine if the
    inherited class is just a namespace.
*/

namespace no_members {

struct A {
    A() = default;
    ~A() = default;
    std::ptrdiff_t offset_of(const int &data) const;
};

struct B {
    B() = default;
    ~B() = default;
    std::ptrdiff_t offset_of(const int &data) const;
};

struct C : A, B {
    C() = default;
    ~C() = default;
    std::ptrdiff_t offset_of(const int &data) const;
};

struct D : virtual A, virtual B {
    D() = default;
    ~D() = default;
    std::ptrdiff_t offset_of(const int &data) const;
};

// this forces the generation of typeinfo for C
class E : virtual C {
};

void print();

} // no_members

#endif // NO_MEMBERS_HPP
