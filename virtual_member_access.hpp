#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __VIRTUAL_MEMBER_ACCESS__
#define __VIRTUAL_MEMBER_ACCESS__

/*
    These are for determining how to appropriatly decompile the accessing of
    virtual members.
*/

namespace VirtualMemberAccess {
    class AbstractA {
        protected:
            AbstractA() {}
            virtual ~AbstractA(){}
        
        public:
            virtual void abstract_a_foo() = 0;
            virtual int access() {
                abstract_a_data = 1;
                return abstract_a_data;
            }

            int abstract_a_data;
    };

    class A {
        public:
            A() {}
            virtual ~A() {}
            virtual int access() {
                a_data = 1;
                return a_data;
            }
            
            int a_data;
    };

    class B : virtual public A {
        public:
            B() {}
            virtual ~B() {}
            virtual int access() {
                a_data = 1;
                b_data = 2;
                a_data = A::access();
                return b_data;
            }

            int b_data;
    };

    class C : virtual public A {
        public:
            C() {}
            virtual ~C(){}
            virtual int access() {
                a_data = 1;
                c_data = 2;
                a_data = A::access();
                return c_data;
            }

            int c_data;
    };

    class D : public B, public C {
        public:
            D() {}
            virtual ~D(){}
            virtual int access() {
                a_data = 1;
                b_data = 2;
                c_data = 3;
                d_data = 4;
                a_data = A::access();
                b_data = B::access();
                c_data = C::access();
                return d_data;
            }

            int d_data;
    };

    class E : public AbstractA {
        public:
            E() {}
            virtual ~E() {}
            void abstract_a_foo() {}
            virtual int access() {
                abstract_a_data = 1;
                e_data = 2;
                abstract_a_data = AbstractA::access();
                return e_data;
            }

            int e_data;
    };

    class F : virtual public AbstractA {
        public:
            F() {}
            virtual ~F() {}
            void abstract_a_foo() {}
            virtual int access() {
                abstract_a_data = 1;
                f_data = 2;
                abstract_a_data = AbstractA::access();
                return f_data;
            }

            int f_data;
    };

    class G : public E, public F {
        public:
            G() {}
            virtual ~G() {}
            virtual int access() {
                E::abstract_a_data = 1;
                F::abstract_a_data = 1;
                e_data = 2;
                f_data = 3;
                g_data = 4;
                e_data = E::access();
                f_data = F::access();
                return g_data;
            }

            int g_data;
    };

    class H : public virtual E, public virtual F {
        public:
            H() {}
            virtual ~H() {}
            virtual int access() {
                E::abstract_a_data = 1;
                F::abstract_a_data = 1;
                e_data = 2;
                f_data = 3;
                h_data = 4;
                e_data = E::access();
                f_data = F::access();
                return h_data;
            }

            int h_data;
    };

    static A a = A();
    static B b = B();
    static C c = C();
    static D d = D();
    static E e = E();
    static F f = F();
    static G g = G();
    static H h = H();

    void run() {
        a.access();
        b.access();
        c.access();
        d.access();
        e.access();
        f.access();
        g.access();
        h.access();
    }
}

#endif // __VIRTUAL_MEMBER_ACCESS__
