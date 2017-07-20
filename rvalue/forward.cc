#include <utility>
#include <iostream>

void PrintT(int& t) {
  std::cout << " lvalue" << std::endl;
}

void PrintT(int&& t) {
  std::cout << " rvalue" << std::endl;
}

template<typename T>
void TestForward(T && v) {
  std::cout << "PrintT(v):";
  PrintT(v);
  std::cout << "PrintT(std::forward<T>(v)):";
  PrintT(std::forward<T>(v));
  std::cout << "PrintT(std::move(v)):";
  PrintT(std::move(v));
}

int main() {
  std::cout << "TestForward(1):" << std::endl;
  TestForward(1);

  int x = 1;
  std::cout << "TestForward(x):" << std::endl;
  TestForward(x);

  std::cout << "TestForward(std::forward<int>(x)):" << std::endl;
  TestForward(std::forward<int>(x));
  return 0;
}

