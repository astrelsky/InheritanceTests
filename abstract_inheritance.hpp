#include <iostream>
#include "main.hpp"
using namespace std;

#ifndef __ABSTRACT_INHERITANCE__
#define __ABSTRACT_INHERITANCE__

namespace AbstractInheritance {

    class F {
        protected:
            F(int dataValue) : f_data(dataValue) {}
            F(){}
            virtual ~F(){}
        public:
            virtual void f_foo() {}
            virtual string getName() = 0;
            virtual int getData() { return f_data; }
            virtual size_t getSize() = 0;
            virtual string getParentName() { return "F"; }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }

            ostream& print(ostream& os){
                os << getName() << " size: " << getSize() << endl;
                os << getName() << " data: " << getData() << endl;
                return os;
            }

            int f_data;
    };

    class G : virtual public F {
        public:
            G(int dataValue) : F(dataValue) {}
            virtual ~G(){}
            virtual void g_foo() {}
            virtual string getParentName() { return "G & "+ F::getParentName(); }
            virtual string getName() { return "G"; }
            virtual size_t getSize() { return sizeof(G); }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, G& g){
                g.print(os);
                os << "g.g_data: " << g.offset_of(g.g_data) << endl;
                os << "super_F: " << offset_of_base<F, G>(g) << endl;
                os << "g.f_data: " << g.offset_of(g.f_data) << endl;
                return os;
            }

            int g_data;
    };

    class H : public F {
        public:
            H(int dataValue) : F(dataValue) {}
            virtual ~H(){}
            virtual void h_foo() {}
            virtual string getParentName() { return "H & "+ F::getParentName(); }
            virtual string getName() { return "H"; }
            virtual size_t getSize() { return sizeof(H); }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            friend ostream& operator<< (ostream& os, H& h){
                h.print(os);
                os << "h.h_data: " << h.offset_of(h.h_data) << endl;
                os << "super_F: " << offset_of_base<F, H>(h) << endl;
                os << "h.h_data: " << h.offset_of(h.f_data) << endl;
                return os;
            }

            int h_data;
    };

    class I : public G, public H {
        public:
            I(int dataValue) : G(dataValue), H(dataValue) {}
            virtual ~I(){}
            virtual void i_foo() {}
            virtual size_t getSize() { return sizeof(I); }
            virtual string getName() { return "I"; }
            virtual string getParentName() { return G::getParentName()+" & "+H::getParentName(); }
            ptrdiff_t offset_of(int &data) { return abs((ptrdiff_t)this - (ptrdiff_t)&data); }
            ostream& print(ostream& os) { return G::print(os); }
            friend ostream& operator<< (ostream& os, I& i){
                i.print(os);
                os << "i.i_data: " << i.offset_of(i.i_data) << endl;
                os << *((G *)&i);
                os << *((H *)&i);
                os << "super_G: " << offset_of_base<G, I>(i) << endl;
                os << "i.g_data: " << i.offset_of(i.g_data) << endl;
                os << "super_H: " << offset_of_base<H, I>(i) << endl;
                os << "i.h_data: " << i.offset_of(i.h_data) << endl;
                return os;
            }

            int i_data;
    };

    static G g = G(1);
    static H h = H(2);
    static I i = I(3);

    void printTitle() {
        string name = " AbstractInheritance ";
        int len = (SEPARATOR.length() - (name.length())) / 2;
        string block = string(len, '-');
        string title = block+name+block;
        if (title.length() < SEPARATOR.length()) {
            title += string(SEPARATOR.length() - title.length(), '-');
        }
        cout << SEPARATOR << endl;
        cout << title << endl;
        cout << SEPARATOR << endl;
    }

    void print() {
        printTitle();
        cout << g << endl;
        cout << h << endl;
        cout << i;
    }

}

#endif // __ABSTRACT_INHERITANCE__
