#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
  题目描述
  编写一个方法，确定某字符串的所有排列组合。
  给定一个string A和一个int n,代表字符串和其长度，
  请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，
  排列中的字符串按字典序从大到小排序。(不合并重复字符串)
  测试样例：
  "ABC"
  返回：
  ["CBA","CAB","BCA","BAC","ACB","ABC"]

  -------
  题目分析

 **/

class Permutation {
 public:
  vector<std::string> getPermutation(string A) {
    vector<std::string> permutations;
    myGetPermutation(A, &permutations);

    std::sort(permutations.begin(), permutations.end(), [](const std::string& lhs, const std::string& rhs) {
        return lhs > rhs;
              });
    return permutations;
  }

 private:
  void myGetPermutation(const std::string& A, vector<std::string>* permutations) {
    permutations->clear();
    if (A.empty()) {
      permutations->push_back(A);
      return;
    }

    vector<string> littlePermutations;
    myGetPermutation(A.substr(0, A.size() - 1), &littlePermutations);
    for (size_t i = 0; i < littlePermutations.size(); ++i) {
      auto& permutation = littlePermutations[i];
      for (size_t j = 0; j <= permutation.size(); ++j) {
        std::string newPermutation;
        newPermutation.append(permutation.substr(0, j));
        newPermutation.push_back(A[A.size() - 1]);
        newPermutation.append(permutation.substr(j, permutation.size() - j));
        permutations->push_back(newPermutation);
      }
    }
  }
};

int main() {
  // 样例
  {
    Permutation obj;
    vector<std::string> ret = obj.getPermutation("ABC");
    for (auto& val : ret) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  {
    Permutation obj;
    vector<std::string> ret = obj.getPermutation("");
    for (auto& val : ret) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  {
    Permutation obj;
    vector<std::string> ret = obj.getPermutation("A");
    for (auto& val : ret) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
