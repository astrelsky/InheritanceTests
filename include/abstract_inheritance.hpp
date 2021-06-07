#ifndef ABSTRACT_INHERITANCE_HPP
#define ABSTRACT_INHERITANCE_HPP

#include "serializable.hpp"
#include <cstddef>
#include <iosfwd>
#include <string>

#if SERIALIZE
#include <boost/property_tree/ptree.hpp>
#endif

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
    std::ptrdiff_t offset_of(const int& data) const;

    friend std::ostream& operator<<(std::ostream& os, const F& f);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif
};

class G : virtual public F {
  public:
    G(int dataValue);
    virtual ~G() = default;
    virtual void g_foo();
    virtual std::string getParentName() const override;
    virtual std::string getName() const override;
    virtual size_t getSize() const override;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const G& g);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int g_data;
};

class H : public F {

  public:
    H(int dataValue);
    virtual ~H() = default;
    virtual void h_foo();
    virtual std::string getParentName() const override;
    virtual std::string getName() const override;
    virtual size_t getSize() const override;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const H& h);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int h_data;
};

class I final : public G, public H {
  public:
    I(int dataValue);
    virtual ~I() = default;
    virtual void i_foo();
    virtual size_t getSize() const override;
    virtual std::string getName() const override;
    virtual std::string getParentName() const override;
    std::ptrdiff_t offset_of(const int& data) const;
    friend std::ostream& operator<<(std::ostream& os, const I& i);
#if SERIALIZE
    void serialize(boost::property_tree::ptree& tree) const;
#endif

  protected:
    int i_data;
};

extern G g;

} // namespace abstract_inheritance

#endif // ABSTRACT_INHERITANCE_HPP
