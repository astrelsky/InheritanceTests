#ifndef NO_MEMBERS_HPP
#define NO_MEMBERS_HPP

#include "serializable.hpp"
#include <cstddef>

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

struct A {
    A() = default;
    ~A() = default;
    std::ptrdiff_t offset_of(const int &data) const;
#if SERIALIZE
    void serialize(boost::property_tree::ptree &tree) const;
#endif
};

struct B {
    B() = default;
    ~B() = default;
    std::ptrdiff_t offset_of(const int &data) const;
#if SERIALIZE
    void serialize(boost::property_tree::ptree &tree) const;
#endif
};

struct C : A, B {
    C() = default;
    ~C() = default;
    std::ptrdiff_t offset_of(const int &data) const;
#if SERIALIZE
    void serialize(boost::property_tree::ptree &tree) const;
#endif
};

struct D final : virtual A, virtual B {
    D() = default;
    ~D() = default;
    std::ptrdiff_t offset_of(const int &data) const;
#if SERIALIZE
    void serialize(boost::property_tree::ptree &tree) const;
#endif
};

// this forces the generation of typeinfo for C
class E final : virtual C {};

} // namespace no_members

#endif // NO_MEMBERS_HPP
