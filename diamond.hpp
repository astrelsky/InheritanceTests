#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __DIAMOND__
#define __DIAMOND__

namespace Diamond {
    class A {
        public:
            virtual ~A(){}
            virtual void a_foo() {}
            virtual void set_a_data(int data) { hidden_a_data = data; }
            virtual int get_a_data() { return hidden_a_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, A& a){
                os << "A size: " << sizeof(A) << endl;
                os << "a.a_data: " << a.offset_of(a.a_data) << endl;
                return os;
            }

            int a_data;
        private:
            int hidden_a_data;
    };

    class B : virtual public A {
        public:
            virtual ~B(){}
            virtual void b_foo() {}
            virtual void set_b_data(int data) { b_data = data; }
            virtual int get_b_data() { return b_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, B& b){
                os << "B size: " << sizeof(B) << endl;
                os << "b.b_data: " << b.offset_of(b.b_data) << endl;
                os << "super_A: " << offset_of_base<A, B>(b) << endl;
                os << "b.a_data: " << b.offset_of(b.a_data) << endl;
                return os;
            }

            int b_data;
    };

    class C : virtual public A {
        public:
            virtual ~C(){}
            virtual void c_foo() {}
            virtual void set_c_data(int data) { c_data = data; }
            virtual int get_c_data() { return c_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, C& c){
                os << "C size: " << sizeof(B) << endl;
                os << "c.c_data: " << c.offset_of(c.c_data) << endl;
                os << "super_A: " << offset_of_base<A, C>(c) << endl;
                os << "c.a_data: " << c.offset_of(c.a_data) << endl;
                return os;
            }

            int c_data;
    };

    class D : public B, public C {
        public:
            virtual ~D(){}
            virtual void d_foo() {}
            virtual void set_d_data(int data) { d_data = data; }
            virtual int get_d_data() { return d_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, D& d){
                os << "D size: " << sizeof(D) << endl;
                os << "d.d_data: " << d.offset_of(d.d_data) << endl;
                os << "super_B: " << offset_of_base<B, D>(d) << endl;
                os << "d.b_data: " << d.offset_of(d.b_data) << endl;
                os << "super_A: " << offset_of_base<A, D>(d) << endl;
                os << "d.a_data: " << d.offset_of(d.a_data) << endl;
                os << "super_C: " << offset_of_base<C, D>(d) << endl;
                os << "d.c_data: " << d.offset_of(d.c_data) << endl;
                return os;
            }

            int d_data;
    };

    static A a = A();
    static B b = B();
    static C c = C();
    static D d = D();

    void print() {
        printTitle(" Diamond ");
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d;
    }
}

#endif // __DIAMOND__
