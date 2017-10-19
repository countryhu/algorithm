// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <assert.h>
#include <algorithm>
#include <iostream>


class SelectionSort {
 public:

  int FindMinValueIndex(int A[], int start_index, int end_index) {
    int curr_min_value_index = start_index;
    for (int i = start_index + 1; i <= end_index; ++i) {
      if (A[i] < A[curr_min_value_index]) {
        curr_min_value_index = i;
      }
    }
    return curr_min_value_index;
  }

  void swap(int A[], int index1, int index2) {
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
  }

  int* selectionSort(int A[], int n) {
    for (int i = 0; i <= n - 1; ++i) {
      // 每次遍历[i, n-1] 找到此区间最小的元素所在位置，然后跟i交换
      int min_value_index = FindMinValueIndex(A, i, n-1);

      // 将最小值 放在本该在的位置
      swap(A, i, min_value_index);
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

  SelectionSort sort;
  A = sort.selectionSort(A, array_len);

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
