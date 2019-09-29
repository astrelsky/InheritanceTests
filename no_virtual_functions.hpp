#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __NO_VIRTUAL_FUNCTIONS__
#define __NO_VIRTUAL_FUNCTIONS__

namespace NoVirtualFunctions {
    class A {
        public:
            A() : a_data(0) {}
            A(int value) {
                setData(value);
            }
            ~A() {}
            int getData() { return a_data; }
            void setData(int value) { a_data = value; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, A& a){
                os << "A size: " << sizeof(A) << endl;
                os << "a.a_data: " << a.offset_of(a.a_data) << endl;
                return os;
            }
        
            int a_data;
    };

    class B : public virtual A {
        public:
            B() : b_data(0) {}
            B(int value) {
                setData(value);
            }
            ~B() {}
            int getData() { return b_data; }
            void setData(int value) { b_data = value; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, B& b){
                os << "B size: " << sizeof(B) << endl;
                os << "b.b_data: " << b.offset_of(b.b_data) << endl;
                return os;
            }
        
            int b_data;
    };

    class C : public virtual B {
        public:
            C() : c_data(0) {}
            C(int value) {
                setData(value);
            }
            ~C() {}
            int getData() { return c_data; }
            void setData(int value) { c_data = value; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, C& c){
                os << "C size: " << sizeof(C) << endl;
                os << "C.c_data: " << c.offset_of(c.c_data) << endl;
                os << "super_B: " << offset_of_base<B, C>(c) << endl;
                os << "C.b_data: " << c.offset_of(c.b_data) << endl;
                os << "super_A: " << offset_of_base<A, C>(c) << endl;
                os << "C.a_data: " << c.offset_of(c.a_data) << endl;
                return os;
            }
        
            int c_data;
    };

    class D : public B {
        public:
            D() : d_data(0) {}
            D(int value) {
                setData(value);
            }
            ~D() {}
            int getData() { return d_data; }
            void setData(int value) { d_data = value; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, D& d){
                os << "D size: " << sizeof(D) << endl;
                os << "d.d_data: " << d.offset_of(d.d_data) << endl;
                os << "super_B size: " << sizeof(D::B)-sizeof(B::A) << endl;
                os << "super_B: " << offset_of_base<B, D>(d) << endl;
                os << "d.b_data: " << d.offset_of(d.b_data) << endl;
                os << "super_B::A: " << offset_of_base<A, D::B>(d) << endl;
                os << "super_B.a_data: " << d.offset_of(((B *) &d)->a_data) << endl;
                return os;
            }
        
            int d_data;
    };

    static A a = A(0);
    static B b = B(1);
    static C c = C(2);
    static D d = D(3);

    void print() {
        printTitle(" NoVirtualFunctions ");
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d;
    }
}
#endif // __NO_VIRTUAL_FUNCTIONS__
