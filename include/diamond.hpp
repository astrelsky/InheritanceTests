#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include <cstddef>
#include <iosfwd>

namespace diamond {

class A {
    public:
        virtual ~A() = default;
        virtual void a_foo();
        virtual void set_a_data(int data);
        virtual int get_a_data() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const A& a);

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
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const B& b);

    protected:
        int b_data;
};

class C : virtual public A {
    public:
        virtual ~C() = default;
        virtual void c_foo();
        virtual void set_c_data(int data);
        virtual int get_c_data() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const C& c);

    protected:
        int c_data;
};

class D : public B, public C {
    public:
        virtual ~D() = default;
        virtual void d_foo();
        virtual void set_d_data(int data);
        virtual int get_d_data() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const D& d);

    protected:
        int d_data;
};

} // diamond

#endif // DIAMOND_HPP
