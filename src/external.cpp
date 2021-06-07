#include "external.hpp"
#include "main.hpp"
#include "printable.hpp"
#include <exception>
#include <iostream>

namespace external {

const char *DummyException::what() const throw() {
    return "This is a dummy exception";
}

static void dummyThrower() {
    throw DummyException();
}

static class : public Printable {

    void print() const override {
        printTitle(" External ");
        try {
            dummyThrower();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
} printer;

} // namespace external
