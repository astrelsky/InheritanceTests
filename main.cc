#include <iostream>
#include "main.hpp"
#include "diamond.hpp"
#include "non_diamond.hpp"
#include "large_inheritance.hpp"
#include "abstract_inheritance.hpp"
using namespace std;

int main() {
    Diamond::print();
    NonDiamond::print();
    LargeInheritance::print();
    AbstractInheritance::print();
#ifdef _EE
    for(;;);
#endif
    return 0;
}
