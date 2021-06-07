#ifndef VIRTUAL_MEMBER_ACCESS_HPP
#define VIRTUAL_MEMBER_ACCESS_HPP

/*
    These are for determining how to appropriatly decompile the accessing of
    virtual members.
*/

namespace virtual_member_access {

class AbstractA {
  protected:
    int abstract_a_data;

    AbstractA() = default;
    virtual ~AbstractA() = default;

  public:
    virtual void abstract_a_foo() = 0;
    virtual int access();
};

class A {

  protected:
    int a_data;

  public:
    A() = default;
    virtual ~A() = default;
    virtual int access();
};

class B : virtual public A {

  protected:
    int b_data;

  public:
    B() = default;
    virtual ~B() = default;
    virtual int access() override;
};

class C : virtual public A {

  protected:
    int c_data;

  public:
    C() = default;
    virtual ~C() = default;
    virtual int access() override;
};

class D : public B, public C {

  protected:
    int d_data;

  public:
    D() = default;
    virtual ~D() = default;
    virtual int access() override;
};

class E : public AbstractA {

  protected:
    int e_data;

  public:
    E() = default;
    virtual ~E() = default;
    void abstract_a_foo() override;
    virtual int access() override;
};

class F : virtual public AbstractA {

  protected:
    int f_data;

  public:
    F() = default;
    virtual ~F() = default;
    void abstract_a_foo() override;
    virtual int access() override;
};

class G final : public E, public F {

  protected:
    int g_data;

  public:
    G() = default;
    virtual ~G() = default;
    virtual int access() override;
};

class H final : public virtual E, public virtual F {

  protected:
    int h_data;

  public:
    H() = default;
    virtual ~H() = default;
    virtual int access() override;
};

void run();

} // namespace virtual_member_access

#endif // VIRTUAL_MEMBER_ACCESS_HPP
