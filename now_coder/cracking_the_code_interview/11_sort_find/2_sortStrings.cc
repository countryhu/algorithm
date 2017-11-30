#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

/**
  题目描述
  请编写一个方法，对一个字符串数组进行排序，将所有变位词合并，保留其字典序最小的一个串。
  这里的变位词指变换其字母顺序所构成的新的词或短语。
  例如"triangle"和"integral"就是变位词。
  给定一个string的数组str和数组大小int n，
  请返回排序合并后的数组。保证字符串串长小于等于20，数组大小小于等于300。
  测试样例：
  ["ab","ba","abc","cba"]
  返回：
  ["ab","abc"]

  -------
  题目分析
 **/

class SortString {
 public:
  std::vector<std::string> sortStrings(std::vector<std::string> str, int n) {
    std::cout << str.size() << std::endl;
    (void)n;
    std::unordered_map<std::string, std::string> hashMap;
    for (auto& strElement : str) {
      std::string hashStr = StrSort(strElement);
      if (hashMap[hashStr].empty() || strElement < hashMap[hashStr]) {
        hashMap[hashStr] = strElement;
        std::cout << "hashStr:" << hashStr << " strElement:" << strElement << std::endl;
      }
    }

    std::vector<std::string> rets;
    for (auto iter : hashMap) {
      rets.push_back(iter.second);
    }
    std::sort(rets.begin(), rets.end());
    return rets;
  }

 private:
  std::string StrSort(const std::string& strElement) {
    std::string str(strElement);
    std::sort(str.begin(), str.end());
    return str;
  }
};

int main() {
  // 样例
  {
    SortString obj;
    std::vector<std::string> strs = {"ab","ba","abc","cba"};
    std::vector<std::string> rets = obj.sortStrings(strs, 4);
    std::cout << "rets:" << std::endl;
    for (auto& ret : rets) {
      std::cout << ret << " ";
    }
    std::cout << "" << std::endl;
  }
  return 0;
}
