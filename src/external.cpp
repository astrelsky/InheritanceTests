#include "main.hpp"
#include "external.hpp"
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

static class : Printable {

    void print() const {
        printTitle(" External ");
        try {
            dummyThrower();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
} printer;

} // external
