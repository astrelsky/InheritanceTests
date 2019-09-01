#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __LARGE_INHERITANCE__
#define __LARGE_INHERITANCE__

namespace LargeInheritance {
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
                os << "C size: " << sizeof(C) << endl;
                os << "C.c_data: " << c.offset_of(c.c_data) << endl;
                os << "super_A: " << offset_of_base<A, C>(c) << endl;
                os << "C.a_data: " << c.offset_of(c.a_data) << endl;
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
                os << "super_A: " << offset_of_base<A, D>(d) << endl;
                os << "d.a_data: " << d.offset_of(d.a_data) << endl;
                os << "super_B: " << offset_of_base<B, D>(d) << endl;
                os << "d.b_data: " << d.offset_of(d.b_data) << endl;
                os << "super_C: " << offset_of_base<C, D>(d) << endl;
                os << "d.c_data: " << d.offset_of(d.c_data) << endl;
                os << "d.d_data: " << d.offset_of(d.d_data) << endl;
                return os;
            }

            int d_data;
    };

    class Z {
        public:
            virtual ~Z(){}
            virtual void z_foo() {}
            virtual void set_z_data(int data) { z_data = data; }
            virtual int get_z_data() { return z_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, Z& z){
                os << "Z size: " << sizeof(Z) << endl;
                os << "z.z_data: " << z.offset_of(z.z_data) << endl;
                return os;
            }

            int z_data;
    };

    class U {
        public:
            virtual ~U(){}
            virtual void y_foo() {}
            virtual void set_y_data(int data) { y_data = data; }
            virtual int get_y_data() { return y_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, U& y){
                os << "U size: " << sizeof(U) << endl;
                os << "y.y_data: " << y.offset_of(y.y_data) << endl;
                return os;
            }

            int y_data;
    };

    class Y : virtual public U {
        public:
            virtual ~Y(){}
            virtual void y_foo() {}
            virtual void set_y_data(int data) { y_data = data; }
            virtual int get_y_data() { return y_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, Y& y){
                os << "Y size: " << sizeof(Y) << endl;
                os << "y.y_data: " << y.offset_of(y.y_data) << endl;
                os << "super_U: " << offset_of_base<U, Y>(y) << endl;
                os << "y.y_data: " << y.offset_of(y.y_data) << endl;
                return os;
            }

            int y_data;
    };

    class X {
        public:
            virtual ~X(){}
            virtual void x_foo() {}
            virtual void set_x_data(int data) { x_data = data; }
            virtual int get_x_data() { return x_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, X& x){
                os << "X size: " << sizeof(X) << endl;
                os << "x.x_data: " << x.offset_of(x.x_data) << endl;
                return os;
            }

            int x_data;
    };

    class W : virtual public B, public Y, virtual public C, public Z, public X {
        public:
            virtual ~W(){}
            virtual void w_foo() {}
            virtual void z_foo() {}
            virtual void set_w_data(int data) { w_data = data; }
            virtual int get_w_data() { return w_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, W& w){
                os << "W size: " << sizeof(W) << endl;
                os << "w.w_data: " << w.offset_of(w.w_data) << endl;
                os << "super_C: " << offset_of_base<C, W>(w) << endl;
                os << "w.c_data: " << w.offset_of(w.c_data) << endl;
                os << "super_A: " << offset_of_base<A, W>(w) << endl;
                os << "w.a_data: " << w.offset_of(w.a_data) << endl;
                os << "super_B: " << offset_of_base<B, W>(w) << endl;
                os << "w.b_data: " << w.offset_of(w.b_data) << endl;
                os << "super_Z: " << offset_of_base<Z, W>(w) << endl;
                os << "w.z_data: " << w.offset_of(w.z_data) << endl;
                os << "super_Y: " << offset_of_base<Y, W>(w) << endl;
                os << "w.y_data: " << w.offset_of(w.y_data) << endl;
                os << "super_X: " << offset_of_base<X, W>(w) << endl;
                os << "w.x_data: " << w.offset_of(w.x_data) << endl;
                os << "super_U: " << offset_of_base<U, W>(w) << endl;
                os << "w.y_data: " << w.offset_of(w.y_data) << endl;
                return os;
            }

            int w_data;
    };

    class V : public Z, public Y, public X, public A {
        public:
            virtual ~V(){}
            virtual void v_foo() {}
            virtual void z_foo() {}
            virtual void y_foo() {}
            virtual void x_foo() {}
            virtual void a_foo() {}
            virtual void set_v_data(int data) { v_data = data; }
            virtual int get_v_data() { return v_data; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, V& v){
                os << "V size: " << sizeof(V) << endl;
                os << "v.v_data: " << v.offset_of(v.v_data) << endl;
                os << "super_Z: " << offset_of_base<Z, V>(v) << endl;
                os << "v.z_data: " << v.offset_of(v.z_data) << endl;
                os << "super_Y: " << offset_of_base<Y, V>(v) << endl;
                os << "v.y_data: " << v.offset_of(v.y_data) << endl;
                os << "super_X: " << offset_of_base<X, V>(v) << endl;
                os << "v.x_data: " << v.offset_of(v.x_data) << endl;
                os << "super_A: " << offset_of_base<A, V>(v) << endl;
                os << "v.a_data: " << v.offset_of(v.a_data) << endl;
                return os;
            }

            int v_data;
    };

    static A a = A();
    static B b = B();
    static C c = C();
    static D d = D();
    static U u = U();
    static V v = V();
    static W w = W();
    static X x = X();
    static Y y = Y();
    static Z z = Z();

    void print() {
        printTitle(" LargeInheritance ");
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
        cout << u << endl;
        cout << v << endl;
        cout << w << endl;
        cout << x << endl;
        cout << y << endl;
        cout << z;
    }
}

#endif // __LARGE_INHERITANCE__
