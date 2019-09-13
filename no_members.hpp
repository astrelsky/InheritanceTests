#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __NO_MEMBERS__
#define __NO_MEMBERS__

namespace NoMembers {
    class A {
        public:
            A() {}
            ~A() = default;
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, A& a){
                os << "A size: " << sizeof(A) << endl;
                return os;
            }
    };

    class B {
        public:
            B() {}
            ~B() = default;
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, B& b){
                os << "B size: " << sizeof(B) << endl;
                return os;
            }
    };

    class C : public A, public B {
        public:
            C() {}
            ~C() = default;
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, C& c){
                os << "C size: " << sizeof(C) << endl;
                os << "super_A: " << offset_of_base<A, C>(c) << endl;
                os << "super_B: " << offset_of_base<B, C>(c) << endl;
                return os;
            }
    };

    class D : public virtual A, public virtual B {
        public:
            D() {}
            ~D() = default;
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, D& d){
                os << "D size: " << sizeof(D) << endl;
                os << "super_B: " << offset_of_base<B, D>(d) << endl;
                os << "super_A: " << offset_of_base<A, D>(d) << endl;
                return os;
            }
    };

    // this forces the generation of typeinfo for C
    class E : public virtual C {
    };

    static A a;
    static B b;
    static C c;
    static D d;
    static E e;

    void print() {
        printTitle(" NoMembers ");
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d;
    }
}
#endif // __NO_MEMBERS__
