// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <assert.h>
#include <iostream>
#include <vector>

class MergeSort {
 public:
  int* mergeSort(int A[], int n) {
    if (A == NULL || n <= 1) {
      return A;
    }

    MyMergeSort(A, 0, n-1);
    return A;
  }

  void MyMergeSort(int A[], size_t start_index, size_t end_index) {
    assert(A != NULL);
    assert(start_index <= end_index);

    // 一个元素，认为是已经排好序的
    if (start_index == end_index) {
      return;
    }

    size_t mid_index = (start_index + end_index) / 2;
    MyMergeSort(A, start_index, mid_index);
    MyMergeSort(A, mid_index + 1, end_index);
    Merge(A, start_index, mid_index, end_index);
  }

  void Merge(int A[], size_t start_index, size_t mid_index, size_t end_index) {
    assert(start_index <= mid_index);
    assert(mid_index <= end_index);

    size_t total_count = end_index - start_index + 1;

    std::vector<int> merged_vec;
    merged_vec.reserve(total_count);

    size_t left = start_index;
    size_t right = mid_index + 1;
    while (total_count--) {
      // 两个桶都还有数据
      if (left <= mid_index && right <= end_index) {
        if (A[left] <= A[right]) {
          merged_vec.push_back(A[left]);
          left++;
        } else {
          merged_vec.push_back(A[right]);
          right++;
        }
        continue;
      }

      // 只有左侧桶有数据
      if (left <= mid_index) {
        merged_vec.push_back(A[left]);
        left++;
        continue;
      }

      // 只有右侧桶有数据
      if (right <= end_index) {
        merged_vec.push_back(A[right]);
        right++;
        continue;
      }
    }

    for (size_t i = start_index; i <= end_index; ++i) {
      A[i] = merged_vec[i-start_index];
    }
  }
};

void TestCase(int A[], int array_len) {
  std::cout << std::endl << "Pre sort:";
  for (int i = 0; i < array_len; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  MergeSort sort;
  A = sort.mergeSort(A, array_len);

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
