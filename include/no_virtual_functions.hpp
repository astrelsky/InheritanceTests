#ifndef NO_VIRTUAL_FUNCTIONS_HPP
#define NO_VIRTUAL_FUNCTIONS_HPP

#include "serializable.hpp"
#include <cstddef>
#include <iosfwd>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

namespace no_virtual_functions {

class A {

  public:
    A() = default;
    A(int value);
    ~A() = default;
    int getData() const;
    void setData(int value);
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const A& a);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int a_data;
};

class B : public virtual A {

  public:
    B() = default;
    B(int value);
    ~B() = default;
    int getData() const;
    void setData(int value);
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const B& b);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int b_data;
};

class C final : public virtual B {

  public:
    C() = default;
    C(int value);
    ~C() = default;
    int getData() const;
    void setData(int value);
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const C& c);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int c_data;
};

class D final : public B {

  public:
    D() = default;
    D(int value);
    ~D() = default;
    int getData() const;
    void setData(int value);
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const D& d);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int d_data;
};

} // namespace no_virtual_functions

#endif // NO_VIRTUAL_FUNCTIONS_HPP
