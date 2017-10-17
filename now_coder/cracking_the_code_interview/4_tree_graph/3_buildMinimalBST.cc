#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

/**
  题目描述
  对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
  给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
  -----

  题目分析
  1. 递归 用二分+左右发缩小范围,用两边相等决定停止递归
  2. 注意为空的情况。
  3. 注意size_t类型做减法
 **/

class MinimalBST {
 public:
  int buildMinimalBST(vector<int> vals) {
    if (vals.empty()) {
      return 0;
    }
    return minimalBSTHeight(0, vals.size() - 1);
  }

 private:
  int minimalBSTHeight(int startIndex, int endIndex) {
    if (startIndex > endIndex) {
      return 0;
    }
    if (startIndex == endIndex) {
      return 1;
    }

    int addIndex = (endIndex + startIndex) / 2;
    return max(minimalBSTHeight(startIndex, addIndex - 1), minimalBSTHeight(addIndex + 1, endIndex)) + 1;
  }
};

int main() {
  MinimalBST obj;
  vector<int> case1{1, 2, 3, 4, 5};
  cout << obj.buildMinimalBST(case1) << endl;


  vector<int> case2{1};
  cout << obj.buildMinimalBST(case2) << endl;

  vector<int> case3{};
  cout << obj.buildMinimalBST(case3) << endl;
}
