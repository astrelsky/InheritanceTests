#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#if SERIALIZE == 1
#if __has_include(<boost/property_tree/ptree.hpp>)
#include <boost/property_tree/ptree.hpp>
#endif // SERIALIZE

class Serializable {

  protected:
    Serializable() = default;
    virtual ~Serializable() = default;

  public:
    virtual void serialize(boost::property_tree::ptree &tree) const = 0;
};

#else
#define SERIALIZE 0

class Serializable {};

#endif // __has_include(<boost/property_tree/ptree.hpp>)

#endif // SERIALIZABLE_HPP
