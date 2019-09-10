#include <iostream>
#include <typeinfo>
#include "main.hpp"
#include "abstract_inheritance.hpp"
using namespace std;

#ifndef __FUNDAMENTAL_TYPES__
#define __FUNDAMENTAL_TYPES__

namespace FundamentalTypes {

    /*
        It appears that it may be possible to analyze and track these instances.
        Could potentially be done by tracking created pointers to the single type instance.
        However, their usage is likely so rare that it may not even be worth it.
        Also, the __enum_type_info hold absolutely no useful information regarding the enum.
    */

    enum NUMBER { ZERO, ONE, TWO, THREE };

    static int intArray[] = {10, 11};
    static int intValue = 10;
    static NUMBER enumValue = ZERO;
    static size_t (AbstractInheritance::G::*pointerToMemberFunction)();
    static const type_info& intType = typeid(intValue);
    static const type_info& arrayType = typeid(intArray);
    static const type_info& pointerType = typeid(&intValue);
    static const type_info& enumType = typeid(enumValue);
    static const type_info& classType = typeid(AbstractInheritance::g);
    static const type_info& pointerToMemberType = typeid(pointerToMemberFunction);
    static const type_info& functionType = typeid(printTitle);

    void print() {
        printTitle(" FundamentalTypes ");
        cout << intType.name() << endl;
        cout << arrayType.name() << endl;
        cout << pointerType.name() << endl;
        cout << enumType.name() << endl;
        cout << classType.name() << endl;
        cout << pointerToMemberType.name() << endl;
        cout << functionType.name() << endl;
    }

}

#endif // __FUNDAMENTAL_TYPES__
