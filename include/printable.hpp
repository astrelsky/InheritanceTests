#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP

#include <set>
#include <string_view>

class Printable {

    static std::set<const Printable*> *printables;

    protected:
        Printable();
        virtual ~Printable();
        static void printTitle(std::string_view name);

    public:
        virtual void print() const = 0;
        static const std::set<const Printable*> *getPrintables();
};

#endif // PRINTABLE_HPP
