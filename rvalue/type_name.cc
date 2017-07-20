#include <cxxabi.h>
#include <iostream>
#include <typeinfo>

class Foo {};

int main() {
  char* name = abi::__cxa_demangle(typeid(Foo*[]).name(), nullptr, nullptr, nullptr);
  std::cout << name << std::endl;
  free(name);
  return 0;
}

