#ifndef __MAIN__
#define __MAIN__
#ifdef _MSC_VER
#define __PTRDIFF_TYPE__ ptrdiff_t
#include <string>
#endif

using namespace std;

const static std::string SEPARATOR = "------------------------------------------";

template <typename Parent, typename Child>
inline __PTRDIFF_TYPE__ offset_of_base(Child &child) {
  return abs((__PTRDIFF_TYPE__)&child - (__PTRDIFF_TYPE__)((Parent *)&child));
}

void printTitle(string name) {
        size_t len = (SEPARATOR.length() - (name.length())) / 2;
        string block = string(len, '-');
        string title = block+name+block;
        if (title.length() < SEPARATOR.length()) {
            title += string(SEPARATOR.length() - title.length(), '-');
        }
        cout << SEPARATOR << endl;
        cout << title << endl;
        cout << SEPARATOR << endl;
}
#endif // __MAIN__
