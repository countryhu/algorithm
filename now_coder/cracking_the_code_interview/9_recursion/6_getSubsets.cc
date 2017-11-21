#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
  题目描述
  请编写一个方法，返回某集合的所有非空子集。
  给定一个int数组A和数组的大小int n，请返回A的所有非空子集。
  保证A的元素个数小于等于20，且元素互异。
  各子集内部从大到小排序,子集之间字典逆序排序，见样例。

  测试样例：
  [123,456,789]

  返回：
  {[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}

  -------
  题目分析

 **/

class Subset {
 public:
  vector<vector<int> > getSubsets(vector<int> A, int n) {
    vector<vector<int> > retSubsets = myGetSubsets(A, n);

    auto iter = retSubsets.begin();
    for (; iter < retSubsets.end();) {
      auto& subset = *iter;
      if (subset.empty()) {
        iter = retSubsets.erase(iter);
      } else {
        std::sort(subset.begin(), subset.end(), [](const int &lhs, const int& rhs) {
          return lhs > rhs;
          });
        iter++;
      }
    }

    std::sort(retSubsets.begin(), retSubsets.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
      for (size_t i = 0; i < lhs.size(); ++i) {
        if (i >= rhs.size()) {
          return true;
        }

        if (lhs[i] != rhs[i]) {
          return std::to_string(lhs[i]) > std::to_string(rhs[i]);
        }
      }
      return false;
      });
    return retSubsets;
  }

 private:
  vector<vector<int> > myGetSubsets(vector<int> A, int n) {
    vector<vector<int> > subsets;
    if (n == 0) {
      vector<int> subset;
      subsets.push_back(subset);
      return subsets;
    }

    vector<vector<int> > littleSubsets = myGetSubsets(A, n - 1);
    for (auto& subset : littleSubsets) {
      subsets.push_back(subset);

      vector<int> new_subset(subset);
      new_subset.push_back(A[n-1]);
      subsets.push_back(new_subset);
    }
    return subsets;
  }
};

int main() {
  // 样例
  {
    Subset obj;
    vector<int> A{123,456,789};
    auto ret = obj.getSubsets(A, 3);
    for (auto& vec : ret) {
      for (auto& val : vec) {
        cout << ", " << val;
      }
      cout << std::endl;
    }
  }

  // 样例
  {
    Subset obj;
    vector<int> A{10, 2};
    auto ret = obj.getSubsets(A, 2);
    for (auto& vec : ret) {
      for (auto& val : vec) {
        cout << ", " << val;
      }
      cout << std::endl;
    }
  }
  return 0;
}
