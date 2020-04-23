#ifndef ABSTRACT_INHERITANCE_HPP
#define ABSTRACT_INHERITANCE_HPP

#include <iosfwd>
#include <cstddef>
#include <string>

namespace abstract_inheritance {

class F {

    protected:
        F(int dataValue);
        F() = default;
        virtual ~F() = default;
        int f_data;

    public:
        virtual void f_foo();
        virtual std::string getName() const = 0;
        virtual int getData() const;
        virtual size_t getSize() const = 0;
        virtual std::string getParentName() const;
        std::ptrdiff_t offset_of(const int &data) const;

        friend std::ostream& operator<< (std::ostream& os, const F& f);
};

class G : virtual public F {
    public:
        G(int dataValue);
        virtual ~G() = default;
        virtual void g_foo();
        virtual std::string getParentName() const;
        virtual std::string getName() const;
        virtual size_t getSize() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const G& g);

    protected:
        int g_data;
};

class H : public F {

    public:
        H(int dataValue);
        virtual ~H() = default;
        virtual void h_foo();
        virtual std::string getParentName() const;
        virtual std::string getName() const;
        virtual size_t getSize() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const H& h);

    protected:
        int h_data;
};

class I : public G, public H {
    public:
        I(int dataValue);
        virtual ~I() = default;
        virtual void i_foo();
        virtual size_t getSize() const;
        virtual std::string getName() const;
        virtual std::string getParentName() const;
        std::ptrdiff_t offset_of(const int &data) const;
        friend std::ostream& operator<< (std::ostream& os, const I& i);

    protected:
        int i_data;
};

extern G g;

void print();

} // abstract_inheritance

#endif // ABSTRACT_INHERITANCE_HPP
