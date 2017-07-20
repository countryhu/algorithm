// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <iostream>

#include "range/range.h"

void TestRange() {
  std::cout << "range(15):";
  for (int i : range(15)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;

  std::cout << "range(2, 6):";
  for (auto i : range(2, 6)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;

  const int x = 2, y = 6, z = 3;
  std::cout << "range(2, 6, 3):";
  for (auto i : range(x, y, z)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;

  std::cout << "range(-2, -6, -3):";
  for (auto i : range(-2, -6, -3)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;


  std::cout << "range(10.5, 15.5):";
  for (auto i : range(10.5, 15.5)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;


  std::cout << "range(35, 27, -1):";
  for (auto i : range(35, 27, -1)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;


  std::cout << "range(2, 8, 0.5):";
  for (auto i : range(2, 8, 0.5)) {
    std::cout << " " << i;
  }
  std::cout << std::endl;


  std::cout << "range('a', 'z'):";
  for (auto i : range('a', 'z')) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
}

int main() {
  TestRange();
  return 0;
}
