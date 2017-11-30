#include <iostream>
#include <vector>

/**
  题目描述
  有一个排过序的字符串数组，但是其中有插入了一些空字符串，
  请设计一个算法，找出给定字符串的位置。算法的查找部分的复杂度应该为log级别。
  给定一个string数组str,同时给定数组大小n和需要查找的string x，
  请返回该串的位置(位置从零开始)。

  测试样例：
  ["a","b","","c","","d"],6,"c"
  返回：
  3

  -------
  题目分析
 **/

class Finder {
 public:
  int findString(std::vector<std::string> str, int n, std::string x) {
    // 特殊情况:""
    if (x.empty()) {
      for (int i = 0; i < (int)str.size(); ++i) {
        if (str[i].empty()) {
          return i;
        }
      }
    }
    return myFindString(str, 0, n -1, x);
  }

 private:
  int myFindString(const std::vector<std::string>& str, int start, int end, const std::string& x) {
    while (str[start].empty() && start <= end) {
      start ++;
    }
    while (str[end].empty() && start <= end) {
      end --;
    }
    if (start > end) {
      return -1;
    }

    int mid = (start + end) / 2;
    while (str[mid].empty() && mid <= end) {
      mid ++;
    }

    if (str[mid] == x) {
      return mid;
    }

    if (str[mid] < x) {
      return myFindString(str, mid + 1, end, x);
    } else {
      return myFindString(str, start, mid - 1, x);
    }
  }
};

int main() {
  // 样例
  {
    Finder obj;
    std::vector<std::string> str = {"a","b","","c","","d"};
    std::cout << obj.findString(str, 6, "c") << std::endl;
    std::cout << obj.findString(str, 6, "") << std::endl;
  }

  // 样例
  {
    Finder obj;
    std::vector<std::string> str = {"a","b","","c","","d"};
    std::cout << obj.findString(str, 6, "d") << std::endl;
  }
  return 0;
}
