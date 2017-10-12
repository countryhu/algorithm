#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
题目描述:
  给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
  给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
测试样例:
"This is nowcoder","is This nowcoder"
返回：true
"Here you are","Are you here"
返回：false

解题思路：
重点条件：大小写敏感，字符重排，考虑空格，长度小于5000

方案一：统计每个字符出现的次数.
优点：O(n)的时间复杂度
缺点：O(n)的空间复杂度
方案二：排序
优点：不需要额外的空间（快排，归并等）
缺点：时间复杂度O(nlogn)
方案三：每个字符两个字符串循环遍历统计次数
优点：实现简单，空间复杂度较低O(k)
缺点：时间复杂度O(n2)
**/

class Same {
 public:
  bool checkSam(string stringA, string stringB) {
    if (stringA.size() != stringB.size())
      return false;

    std::map<char, int> charNums;
    for (size_t i = 0; i < stringA.size(); ++i) {
      charNums[stringA[i]] ++;
    }

    for (size_t i = 0; i < stringB.size(); ++i) {
      if (--charNums[stringB[i]] < 0) {
        return false;
      }
    }

    for (auto iter : charNums) {
      if (iter.second != 0)
        return false;
    }

    return true;
  }
};

int main() {
  Same obj;
  // ok
  if (obj.checkSam("This is nowcoder", "is This nowcoder")) {
    cout << "\"This is nowcoder\", \"is This nowcoder\" check ok" << endl;
  }
  // 大小写
  if (!obj.checkSam("Here you are", "Are you here")) {
    cout << "\"Here you are\" check ok" << endl;
  }
  // 特殊：空
  if (obj.checkSam("", "")) {
    cout << "null check ok" << endl;
  }
  // 特殊：1
  if (obj.checkSam("1", "1")) {
    cout << "1 check ok" << endl;
  }
  // 特殊：false
  if (!obj.checkSam("1", "2")) {
    cout << "1 vs 2 check ok" << endl;
  }
  // 特殊：false
  if (!obj.checkSam("1 ", "12")) {
    cout << "1 vs 12 check ok" << endl;
  }
  // 特殊：false
  if (!obj.checkSam("12", "1")) {
    cout << "12 vs 2 check ok" << endl;
  }
  // 特殊：false
  if (!obj.checkSam("1 ", "1")) {
    cout << "1space vs 1 check ok" << endl;
  }
  return 0;
}
