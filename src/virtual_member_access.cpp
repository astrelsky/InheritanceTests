#include "main.hpp"
#include "printable.hpp"
#include "virtual_member_access.hpp"
#include <iostream>

/*
    These are for determining how to appropriatly decompile the accessing of
    members.
*/

namespace virtual_member_access {

int AbstractA::access() {
    abstract_a_data = 1;
    return abstract_a_data;
}

int A::access() {
    a_data = 1;
    return a_data;
}

int B::access() {
    a_data = 1;
    b_data = 2;
    a_data = A::access();
    return b_data;
}

int C::access() {
    a_data = 1;
    c_data = 2;
    a_data = A::access();
    return c_data;
}

int D::access() {
    a_data = 1;
    b_data = 2;
    c_data = 3;
    d_data = 4;
    a_data = A::access();
    b_data = B::access();
    c_data = C::access();
    return d_data;
}

void E::abstract_a_foo() {
}

int E::access() {
    abstract_a_data = 1;
    e_data = 2;
    abstract_a_data = AbstractA::access();
    return e_data;
}

void F::abstract_a_foo() {
}

int F::access() {
    abstract_a_data = 1;
    f_data = 2;
    abstract_a_data = AbstractA::access();
    return f_data;
}

int G::access() {
    E::abstract_a_data = 1;
    F::abstract_a_data = 1;
    e_data = 2;
    f_data = 3;
    g_data = 4;
    e_data = E::access();
    f_data = F::access();
    return g_data;
}

int H::access() {
    E::abstract_a_data = 1;
    F::abstract_a_data = 1;
    e_data = 2;
    f_data = 3;
    h_data = 4;
    e_data = E::access();
    f_data = F::access();
    return h_data;
}

static A a;
static B b;
static C c;
static D d;
static E e;
static F f;
static G g;
static H h;

static class : Printable {

    void print() const {
        run();
    }

    static void run() {
        printTitle(" VirtualMemberAccess ");
        a.access();
        b.access();
        c.access();
        d.access();
        e.access();
        f.access();
        g.access();
        h.access();
        std::cout << "members accessed" << std::endl;
    }
} accesser;

} // virtual_member_access
