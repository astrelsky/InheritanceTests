#ifndef EXTERNAL_HPP
#define EXTERNAL_HPP

#include <exception>

namespace external {

class DummyException : public std::exception {

    public:
        DummyException() = default;
        virtual ~DummyException() = default;
        const char *what() const throw();
};

} // external

#endif // EXTERNAL_HPP
