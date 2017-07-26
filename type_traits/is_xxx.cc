#include <iostream>
#include <type_traits>

template<typename T, T v>
struct integral_constant {
  static const T value = v;
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template<typename>
struct is_integral_helper : public false_type {
};

template<>
struct is_integral_helper<bool> : public true_type {
};

template<>
struct is_integral_helper<char> : public true_type {
};

template<>
struct is_integral_helper<int> : public true_type {
};


template<typename T>
struct is_integral : public is_integral_helper<typename std::remove_const<T>::type> {
};



template<typename>
struct is_array_helper : public false_type {
};

// 偏特化一维数组
template<typename T>
struct is_array_helper<T[]> : public true_type {
};

// 偏特化多维数组
template<typename T, std::size_t N>
struct is_array_helper<T[N]> : public true_type {
};

template<typename T>
struct is_array : public is_array_helper<typename std::remove_const<T>::type> {
};

int main() {
  std::cout << "is_integral:" << std::endl;
  std::cout << "is_integral<bool>::value=" << is_integral<bool>::value << std::endl;
  std::cout << "is_integral<char>::value=" << is_integral<char>::value << std::endl;
  std::cout << "is_integral<double>::value=" << is_integral<double>::value << std::endl;
  std::cout << "is_integral<const double>::value=" << is_integral<const double>::value << std::endl;
  std::cout << "is_integral<const char>::value=" << is_integral<const char>::value << std::endl;


  std::cout << "\nis_array:" << std::endl;
  std::cout << "int: " << is_array<int>::value << std::endl;
  std::cout << "const int: " << is_array<const int>::value << std::endl;
  std::cout << "int[3]: " << is_array<int[3]>::value << std::endl;
  std::cout << "const int[3]: " << is_array<const int[3]>::value << std::endl;
  std::cout << "std::string: " << is_array<std::string>::value << std::endl;
  std::cout << "string[3]: " << is_array<std::string[3]>::value << std::endl;
  std::cout << "string[3][4]: " << is_array<std::string[3][4]>::value << std::endl;
  std::cout << "const string[3][4]: " << is_array<const std::string[3][4]>::value << std::endl;
  return 0;
}
