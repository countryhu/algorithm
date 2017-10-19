// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <assert.h>
#include <algorithm>
#include <iostream>

class BubbleSort {
 public:
  static int* bubbleSort(int* A, int n) {
    // 每次遍历: 比较并交换相邻的两个元素，让最大值冒泡到最顶上
    for (int i = n-1; i >- 0; --i) {
      // 从0到i冒泡出最大值
      for (int j = 0; j < i; ++j) {
        if (A[j] > A[j+1]) {
          std::swap(A[j], A[j+1]);
        }
      }
    }
    return A;
  }
};

void TestCase(int A[], int array_len) {
  // int array_len = sizeof(A) / sizeof(int);
  std::cout << std::endl << "Pre sort sizeof(A):" << sizeof(A)
    << " sizeof(int):" << sizeof(int)
    << " array_len:" << array_len << ":";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  A = BubbleSort::bubbleSort(A, array_len);

  for (int i = 0; i < array_len - 1; ++i) {
    assert((A[i] <= A[i+1]));
  }
  std::cout << "sort check OK:";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "sizeof(int):" << sizeof(int) << std::endl;

  int a[] = {};
  TestCase(a, sizeof(a)/sizeof(int));

  int a1[] = {1};
  TestCase(a1, sizeof(a1)/sizeof(int));

  int a2[] = {1,1};
  TestCase(a2, sizeof(a2)/sizeof(int));

  int a3[] = {1,1,2,0};
  TestCase(a3, sizeof(a3)/sizeof(int));

  int a4[] = {1,1,2,0, 8, 1000, 9, 2, 433, 234, 5, 234};
  TestCase(a4, sizeof(a4)/sizeof(int));
}
