#include "printable.hpp"
#include "serializable.hpp"
#include <cstdio>
#include <fstream>
#include <string>
#include <type_traits>

int main(int argc, char *argv[]) {
#if SERIALIZE
    boost::property_tree::ptree tree;
#endif
    for (const Printable *p : *Printable::getPrintables()) {
        p->print();
#if SERIALIZE
        if (argc == 2) {
            if (const Serializable *s = dynamic_cast<const Serializable *>(p))
                s->serialize(tree);
        }
#endif
    }

#if SERIALIZE
    if (argc == 2)
        boost::property_tree::write_json(argv[1], tree);
#endif
    return 0;
}
