// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <iostream>

#include <assert.h>
#include <stdlib.h>
#include <vector>

class QuickSort {
 public:
  int* quickSort(int A[], int n) {
    if (A == NULL || n <= 1) {
      return A;
    }

    MyQuickSort(A, 0, n-1);
    return A;
  }

  void MyQuickSort(int A[], int start_index, int end_index) {
    assert(A != NULL);


    // 一个元素，认为是已经排好序的
    if (start_index >= end_index) {
      return;
    }

    int random_index = start_index + rand() % (end_index - start_index + 1);
    std::swap(A[random_index], A[end_index]);

    // pivot_index 左侧元素小于A[pivot_index], pivot_index右侧都大于A[pivot_index]
    int pivot_index = Partition(A, start_index, end_index);

    // 再分治发排序pivot_index左侧和右侧
    MyQuickSort(A, start_index, pivot_index - 1);
    MyQuickSort(A, pivot_index + 1, end_index);
  }

  int Partition(int A[], int start_index, int end_index) {
    int pivot = start_index - 1; // 基数初始化为
    int index = start_index;
    for (; index <= end_index - 1; ++index) {
      if (A[index] < A[end_index]) {
        std::swap(A[++pivot], A[index]);
      }
    }
    std::swap(A[++pivot], A[end_index]);

    return pivot;
  }
};

void TestCase(int A[], int array_len) {
  std::cout << std::endl << "Pre sort:";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  QuickSort sort;
  A = sort.quickSort(A, array_len);

  std::cout << std::endl << "Aft sort:";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < array_len - 1; ++i) {
    assert((A[i] <= A[i+1]));
  }
  std::cout << "sort check OK.";
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
