#include <utility>
#include <functional>
#include <iostream>

void test0() {
  std::cout << "test0";
}

int test1() {
  return 1;
}

int test2(int x) {
  return x;
}

std::string test3(const std::string& s1, const std::string& s2) {
  return s1 + s2;
}

template <typename Function, typename... Args>
inline auto FuncWrapper(Function&& f, Args&& ... args)
  -> decltype(f(std::forward<Args>(args)...)) {
  return f(std::forward<Args>(args)...);
}

int main() {
  std::cout << "FuncWrapper(test0):";
  FuncWrapper(test0);
  std::cout << std::endl;

  std::cout << "FuncWrapper(test1):" << FuncWrapper(test1) << std::endl;

  std::cout << "FuncWrapper(test2, 1):" << FuncWrapper(test2, 1) << std::endl;

  std::cout << "FuncWrapper(test3, \"aa\", \"bb\"):" << FuncWrapper(test3, "aa", "bb") << std::endl;
  return 0;
}
