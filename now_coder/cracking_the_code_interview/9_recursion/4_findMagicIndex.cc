#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
  题目描述
  在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
  给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。
  请思考一种复杂度优于o(n)的方法。

  给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。

  测试样例：
  [1,2,3,4,5]
  返回：
  false

  -------
  题目分析
  1. 明显的二分搜索法

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
    if (A[mid] == mid) {
      return true;
    } else if (A[mid] > mid) {
      // 以后都大，寻找之前的
      return myFindMagicIndex(A, start_index, mid - 1);
    } else { // A[mid] < mid
      // 以前都小，寻找之后的
      return myFindMagicIndex(A, mid + 1, end_index);
    }
  }
};

int main() {
  // 样例
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
