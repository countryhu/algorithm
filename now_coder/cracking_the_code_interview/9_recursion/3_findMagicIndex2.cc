#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
  题目描述
  在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
  给定一个不下降序列，元素值可能相同，编写一个方法，判断在数组A中是否存在魔术索引。
  请思考一种复杂度优于o(n)的方法。
  给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。

  测试样例：
  [1,1,3,4,5]

  返回：
  true

  -------
  题目分析

 **/

class MagicIndex {
 public:
  bool findMagicIndex(vector<int> A, int n) {
    return myFindMagicIndex(A, 0, n-1);
  }

 public:
  bool myFindMagicIndex(const vector<int>& A, int start_index, int end_index) {
    if (start_index > end_index) {
      return false;
    }

    int mid = (start_index + end_index) / 2;
    // std::cout << " start_index: A[" << start_index << "]=" << A[start_index]
        // << " end_index A[" << end_index << "]=" << A[end_index]
        // << " mid A[" << mid << "]=" << A[mid] << std::endl;
    if (A[mid] == mid) {
      return true;
    } else if (A[mid] > mid) {
      // A[5] = 7
      bool ret = myFindMagicIndex(A, start_index, mid - 1)
          || myFindMagicIndex(A, mid + (A[mid] - mid), end_index);
      return ret;
    } else { // A[mid] < mid
      // A[5] = 3
      bool ret = myFindMagicIndex(A, start_index, mid - (mid - A[mid]))
          || myFindMagicIndex(A, mid + 1, end_index);
      return ret;
    }
  }
};

int main() {
  // 样例
  {
    MagicIndex obj;
    vector<int> A{1,1,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=true:" << obj.findMagicIndex(A, 5) << endl;
  }

  {
    MagicIndex obj;
    vector<int> A{1,2,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=false:" << obj.findMagicIndex(A, 5) << endl;
  }

  // 不存在:跨
  {
    MagicIndex obj;
    vector<int> A{-3,2,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=false:" << obj.findMagicIndex(A, 5) << endl;
  }

  // 存在:正常
  {
    MagicIndex obj;
    vector<int> A{-3,1,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=true:" << obj.findMagicIndex(A, 5) << endl;
  }

  // 存在:边界
  {
    MagicIndex obj;
    vector<int> A{0,2,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=true:" << obj.findMagicIndex(A, 5) << endl;
  }

  // 存在:多值
  {
    MagicIndex obj;
    vector<int> A{0,1,3,4,5};
    cout << "obj.findMagicIndex(A, 5)=true:" << obj.findMagicIndex(A, 5) << endl;
  }


  // 存在:边界
  {
    MagicIndex obj;
    vector<int> A{-2,-1,1,2,4};
    cout << "obj.findMagicIndex(A, 5)=true:" << obj.findMagicIndex(A, 5) << endl;
  }
  return 0;
}
