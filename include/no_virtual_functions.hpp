#ifndef NO_VIRTUAL_FUNCTIONS_HPP
#define NO_VIRTUAL_FUNCTIONS_HPP

#include <cstddef>
#include <iosfwd>

namespace no_virtual_functions {

class A {

    public:
        A() = default;
        A(int value);
        ~A() = default;
        int getData() const;
        void setData(int value);
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const A& a);

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
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const B& b);

    protected:
        int b_data;
};

class C : public virtual B {

    public:
        C() = default;
        C(int value);
        ~C() = default;
        int getData() const;
        void setData(int value);
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const C& c);

    protected:
        int c_data;
};

class D : public B {

    public:
        D() = default;
        D(int value);
        ~D() = default;
        int getData() const;
        void setData(int value);
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const D& d);

    protected:
        int d_data;
};

} // no_virtual_functions

#endif // NO_VIRTUAL_FUNCTIONS_HPP
