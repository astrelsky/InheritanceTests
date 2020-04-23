#ifndef INTERFACES_HPP
#define INTERFACES_HPP

namespace interfaces {

struct A {
    virtual void aFoo() = 0;
};

struct B {
    virtual void bFoo() = 0;
};

struct C {
    virtual void cFoo() = 0;
};

struct D {
    virtual void dFoo() = 0;
};

struct E : public A, public B, public C, public D {
    void aFoo();
    void bFoo();
    void cFoo();
    void dFoo();
    void print();
};

void print();

} // interfaces

#endif // INTERFACES_HPP
