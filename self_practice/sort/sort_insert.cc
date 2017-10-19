// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <assert.h>
#include <iostream>

class InsertionSort {
 public:
  int* insertionSort(int* A, int n) {
    // 遍历每一个要插入的元素
    for (int i = 1; i <= n-1; ++i) {
      int insert_value = A[i];
      // 遍历[i, 0],  找到元素应该插入到的位置
      int insert_pos = i;
      while (insert_pos - 1 >= 0 && A[insert_pos-1] > insert_value) {
        A[insert_pos] = A[insert_pos-1];
        --insert_pos;
      }
      A[insert_pos] = insert_value;
    }
    return A;
  }
};

void TestCase(int A[], int array_len) {
  std::cout << std::endl << "Pre sort:";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  InsertionSort sort;
  A = sort.insertionSort(A, array_len);

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
