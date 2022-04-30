#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#if SERIALIZE
#if __has_include(<boost/property_tree/ptree.hpp>)
#include <boost/bind/bind.hpp>

// boost insist on importing this and generating a warning
// even though we have done what it warns about
#define BOOST_BIND_HPP_INCLUDED

using namespace boost::placeholders;
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class Serializable {

  protected:
    Serializable() = default;
    virtual ~Serializable() = default;

  public:
    virtual void serialize(boost::property_tree::ptree &tree) const = 0;
};

#else
#undef SERIALIZE
#define SERIALIZE 0

class Serializable {};

#endif // __has_include(<boost/property_tree/ptree.hpp>)

#endif // SERIALIZE

#endif // SERIALIZABLE_HPP
