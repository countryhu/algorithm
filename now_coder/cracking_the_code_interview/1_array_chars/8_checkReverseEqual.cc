#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;
/**
  题目描述
  假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，
  请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
  给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
  测试样例：
  "Hello world","worldhello "
  返回：false
  "waterbottle","erbottlewat"
  返回：true

  -----
  题目分析
  1. 已经存在高效函数std::string::find()

  方案一 : s1s1应该包含s2，表明s2是s1旋转而成的
  优点: 逻辑简单
  缺点: 需要额外s1的空间
 **/

class ReverseEqual {
 public:
  bool checkReverseEqual(string s1, string s2) {
    // s1s1应该包含s2
    if (s1.size() != s2.size())
      return false;
    string s1s1 = s1.append(s1);
    return s1s1.find(s2) != string::npos;
  }
};

static int caseN = 0;
void TestCase(string input, string input2, bool expectOutput) {
  cout << "case enter. with input:" << input << " input2:" << input2;

  ReverseEqual obj;
  auto output = obj.checkReverseEqual(input, input2);
  if (output == expectOutput) {
    cout << "case" << ++caseN << ": check ok. with input:" << input
        << "\n output as expect:" << output << endl;
  } else {
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
        << "case" << ++caseN << ": check failed. with input:" << input
        << "\n-------------------------------\n"
        << "   expectOutput:" << expectOutput
        << "\n-------------------------------\n"
        << "but actuaOutput:" << output
        << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
}

int main() {
  // 测试用例
  TestCase("Hello world","worldhello ", false);

  // 测试用例
  TestCase("waterbottle", "erbottlewat",true);

  TestCase("1", "1",true);

  TestCase("", "",true);

  TestCase("12", "21",true);

  TestCase("1 ", "1", false);

  TestCase(" ", "  ", false);
  return 0;
}
