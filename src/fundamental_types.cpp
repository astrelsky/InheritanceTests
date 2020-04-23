#include "abstract_inheritance.hpp"
#include "fundamental_types.hpp"
#include "main.hpp"
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

static const std::type_info& intType = typeid(int);
static const std::type_info& arrayType = typeid(int[]);
static const std::type_info& pointerType = typeid(int*);
static const std::type_info& enumType = typeid(Number::ZERO);
static const std::type_info& classType = typeid(abstract_inheritance::g);
static const std::type_info& pointerToMemberType = typeid(&abstract_inheritance::G::getSize);
static const std::type_info& functionType = typeid(printTitle);

void print() {
    printTitle(" FundamentalTypes ");
    std::cout << intType.name() << std::endl;
    std::cout << arrayType.name() << std::endl;
    std::cout << pointerType.name() << std::endl;
    std::cout << enumType.name() << std::endl;
    std::cout << classType.name() << std::endl;
    std::cout << pointerToMemberType.name() << std::endl;
    std::cout << functionType.name() << std::endl;
}

} // fundamental_types
