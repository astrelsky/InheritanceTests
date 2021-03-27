#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstddef>
#include <cstdlib>

template <typename Parent, typename Child>
inline std::ptrdiff_t offset_of_base(const Child &child) {
    std::ptrdiff_t childPtr = reinterpret_cast<std::ptrdiff_t>(&child);
    const Parent *parent = static_cast<const Parent *>(&child);
    return std::abs(childPtr - reinterpret_cast<std::ptrdiff_t>(parent));
}

template <typename T>
inline std::ptrdiff_t offset_of(const T *type, const int &data) {
    std::ptrdiff_t typePtr = reinterpret_cast<std::ptrdiff_t>(type);
    return std::abs(typePtr - reinterpret_cast<std::ptrdiff_t>(&data));
}

#endif // MAIN_HPP
