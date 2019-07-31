#ifndef __MAIN__
#define __MAIN__
template <typename Parent, typename Child>
inline __PTRDIFF_TYPE__ offset_of_base(Child &child) {
  return abs((__PTRDIFF_TYPE__)&child - (__PTRDIFF_TYPE__)((Parent *)&child));
}
const static std::string SEPARATOR = "------------------------------------------";
#endif // __MAIN__
