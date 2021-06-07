#ifndef LARGE_INHERITANCE_HPP
#define LARGE_INHERITANCE_HPP

#include "serializable.hpp"
#include <cstddef>
#include <iosfwd>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace large_inheritance {

class A {
  public:
    virtual ~A() = default;
    virtual void a_foo();
    virtual void set_a_data(int data);
    virtual int get_a_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const A& a);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int a_data;

  private:
    int hidden_a_data;
};

class B : virtual public A {
  public:
    virtual ~B() = default;
    virtual void b_foo();
    virtual void set_b_data(int data);
    virtual int get_b_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const B& b);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int b_data;
};

class C : virtual public A {
  public:
    virtual ~C() = default;
    virtual void c_foo();
    virtual void set_c_data(int data);
    virtual int get_c_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const C& c);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int c_data;
};

class D : public B, public C {
  public:
    virtual ~D() = default;
    virtual void d_foo();
    virtual void set_d_data(int data);
    virtual int get_d_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const D& d);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int d_data;
};

class Z {
  public:
    virtual ~Z() = default;
    virtual void z_foo();
    virtual void set_z_data(int data);
    virtual int get_z_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const Z& z);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int z_data;
};

class U {
  public:
    virtual ~U() = default;
    virtual void u_foo();
    virtual void set_u_data(int data);
    virtual int get_u_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const U& u);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int u_data;
};

class Y : virtual public U {
  public:
    virtual ~Y() = default;
    virtual void y_foo();
    virtual void set_y_data(int data);
    virtual int get_y_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const Y& y);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int y_data;
};

class X {
  public:
    virtual ~X() = default;
    virtual void x_foo();
    virtual void set_x_data(int data);
    virtual int get_x_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const X& x);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int x_data;
};

class W final : virtual public B, virtual public A, public Y, virtual public C, public Z, public X {
  public:
    W();
    virtual ~W();
    virtual void w_foo();
    virtual void z_foo() override;
    virtual void set_w_data(int data);
    virtual int get_w_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const W& w);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int w_data;
};

class V : public Z, public Y, public X, public A {
  public:
    virtual ~V() {
    }
    virtual void v_foo();
    virtual void z_foo() override;
    virtual void y_foo() override;
    virtual void x_foo() override;
    virtual void a_foo() override;
    virtual void set_v_data(int data);
    virtual int get_v_data() const;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const V& v);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int v_data;
};

} // namespace large_inheritance

#endif // LARGE_INHERITANCE_HPP
