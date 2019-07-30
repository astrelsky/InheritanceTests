#include <stdint.h>

#ifndef __MAIN__
#define __MAIN__
template <typename Parent, typename Child>
inline ptrdiff_t offset_of_base(Child &child) {
  return abs((ptrdiff_t)&child - (ptrdiff_t)((Parent *)&child));
}
#endif // __MAIN__