#include "main.hpp"
#include "printable.hpp"
#include <iostream>
#include <set>
#include <string>
#include <string_view>

const static std::string SEPARATOR = "------------------------------------------";

std::set<const Printable*> *Printable::printables = nullptr;

Printable::Printable() {
    if (printables == nullptr)
        printables = new std::set<const Printable*>();
    printables->insert(this);
}

Printable::~Printable() {
    printables->erase(this);
    if (printables->empty()) {
        delete printables;
        printables = nullptr;
    }
}

const std::set<const Printable*> *Printable::getPrintables() {
    if (printables != nullptr)
        return printables;
    throw std::runtime_error("No printables have been constructed");
}

void Printable::printTitle(std::string_view name) {
    std::size_t blockLen = (SEPARATOR.length() - (name.length())) / 2;
    std::string block = std::string(blockLen, '-');
    std::size_t len = blockLen * 2 + name.length();

    std::cout << SEPARATOR << '\n';
    std::cout << block << name << block;
    if (len < SEPARATOR.length())
        std::cout << std::string(SEPARATOR.length() - len, '-');
    std::cout.put('\n');
    std::cout << SEPARATOR << std::endl;
}
