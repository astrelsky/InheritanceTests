#include "printable.hpp"
#include <cstdio>
#include <fstream>
#include <string>
#include <type_traits>


int main(int argc, char *argv[]) {
    for (const Printable *p : *Printable::getPrintables()) {
        p->print();
    }
    return 0;
}
