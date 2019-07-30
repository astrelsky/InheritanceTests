#include <iostream>
#include "main.hpp"
#include "diamond.hpp"
#include "non_diamond.hpp"
#include "large_inheritance.hpp"
#include "abstract_inheritance.hpp"
using namespace std;

int main() {
    cout << Diamond::a;
    cout << Diamond::b;
    cout << Diamond::c;
    cout << Diamond::d;
    cout << "------------------------------------------" << endl;
    cout << NonDiamond::a;
    cout << NonDiamond::b;
    cout << NonDiamond::c;
    cout << NonDiamond::d;
    cout << "------------------------------------------" << endl;
    cout << LargeInheritance::a;
    cout << LargeInheritance::b;
    cout << LargeInheritance::c;
    cout << LargeInheritance::d;
    cout << LargeInheritance::u;
    cout << LargeInheritance::v;
    cout << LargeInheritance::w;
    cout << LargeInheritance::x;
    cout << LargeInheritance::y;
    cout << LargeInheritance::z;
    cout << "------------------------------------------" << endl;
    cout << AbstractInheritance::g;
    cout << "------------------------------------------" << endl;
    cout << AbstractInheritance::h;
    cout << "------------------------------------------" << endl;
    cout << AbstractInheritance::i;
}
