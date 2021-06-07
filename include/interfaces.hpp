#ifndef INTERFACES_HPP
#define INTERFACES_HPP

namespace interfaces {

namespace virtual_functions {

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

struct E final : public A, public B, public C, public D {
    void aFoo() const override;
    void bFoo() const override;
    void cFoo() const override;
    void dFoo() const override;
};

struct F final : virtual public A, virtual public B, virtual public C, virtual public D {
    void aFoo() const override;
    void bFoo() const override;
    void cFoo() const override;
    void dFoo() const override;
};

} // virtual_functions

namespace non_virtual_functions {

struct A {
    void aFoo() const;
};

struct B {
    void bFoo() const;
};

struct C {
    void cFoo() const;
};

struct D {
    void dFoo() const;
};

struct E final : public A, public B, public C, public D {
    void eFoo() const;
};

struct F final : virtual public A, virtual public B, virtual public C, virtual public D {
    void fFoo() const;
};

} // non_virtual_functions

} // namespace interfaces

#endif // INTERFACES_HPP
