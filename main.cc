#include <iostream>
#include "main.hpp"
#include "diamond.hpp"
#include "non_diamond.hpp"
#include "large_inheritance.hpp"
#include "abstract_inheritance.hpp"
#include "fundamental_types.hpp"
#include "no_virtual_functions.hpp"
#include "no_members.hpp"
#include "virtual_member_access.hpp"
using namespace std;

int main() {
    Diamond::print();
    NonDiamond::print();
    LargeInheritance::print();
    AbstractInheritance::print();
    NoVirtualFunctions::print();
    FundamentalTypes::print();
    NoMembers::print();
    VirtualMemberAccess::run();
#ifdef _EE
    for(;;);
#endif
    return 0;
}
