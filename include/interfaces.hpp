#ifndef INTERFACES_HPP
#define INTERFACES_HPP

namespace interfaces {

struct A {
    virtual void aFoo() const = 0;
};

struct B {
    virtual void bFoo() const = 0;
};

struct C {
    virtual void cFoo() const = 0;
};

struct D {
    virtual void dFoo() const = 0;
};

struct E : public A, public B, public C, public D {
    void aFoo() const;
    void bFoo() const;
    void cFoo() const;
    void dFoo() const;
};

struct F : public A, public B, public C, public D {
    void aFoo() const;
    void bFoo() const;
    void cFoo() const;
    void dFoo() const;
};

} // interfaces

#endif // INTERFACES_HPP
