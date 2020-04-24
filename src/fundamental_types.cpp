#include "abstract_inheritance.hpp"
#include "fundamental_types.hpp"
#include "main.hpp"
#include "printable.hpp"
#include <cstddef>
#include <iostream>
#include <typeinfo>

namespace fundamental_types {

/*
    It appears that it may be possible to analyze and track these instances.
    Could potentially be done by tracking created pointers to the single type instance.
    However, their usage is likely so rare that it may not even be worth it.
    Also, the __enum_type_info hold absolutely no useful information regarding the enum.
*/

static void dummyFunction() {
}

static const std::type_info& intType = typeid(int);
static const std::type_info& arrayType = typeid(int[]);
static const std::type_info& pointerType = typeid(int*);
static const std::type_info& enumType = typeid(Number::ZERO);
static const std::type_info& classType = typeid(abstract_inheritance::g);
static const std::type_info& pointerToMemberType = typeid(&abstract_inheritance::G::getSize);
static const std::type_info& functionType = typeid(dummyFunction);

static class : Printable {

    void print() const {
        printTitle(" FundamentalTypes ");
        std::cout << intType.name() << '\n';
        std::cout << arrayType.name() << '\n';
        std::cout << pointerType.name() << '\n';
        std::cout << enumType.name() << '\n';
        std::cout << classType.name() << '\n';
        std::cout << pointerToMemberType.name() << '\n';
        std::cout << functionType.name() << std::endl;
    }
} printer;

} // fundamental_types
