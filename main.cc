#include <iostream>
#include "main.hpp"
#include "diamond.hpp"
#include "non_diamond.hpp"
#include "large_inheritance.hpp"
#include "abstract_inheritance.hpp"
#include "fundamental_types.hpp"
#include "no_virtual_functions.hpp"
using namespace std;

int main() {
    Diamond::print();
    NonDiamond::print();
    LargeInheritance::print();
    AbstractInheritance::print();
    NoVirtualFunctions::print();
    FundamentalTypes::print();
#ifdef _EE
    for(;;);
#endif
    return 0;
}
