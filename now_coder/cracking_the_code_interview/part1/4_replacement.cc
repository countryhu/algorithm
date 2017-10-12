#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
  题目描述
  请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，
  并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
  给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
  测试样例：
  "Mr John Smith”,13
  返回："Mr%20John%20Smith"
  ”Hello  World”,12
  返回：”Hello%20%20World”

  -----
  题目分析
  1. 空格-》%20 字符变长 2. 原数组预留了足够的空间存储变长后的字符串
  3. 由大小写英文字母组成 没有其他特殊字符，可能提示可以考虑散列表
  4. 算法5模式匹配 枚举法，模式匹配法，基本法，数据结构头脑风暴法
  5. 如果iniString和length参数是输入输出,那就可以直接在initString基础上操作，无需额外空间

  方案一: 第一遍遍历，找到总的空格数量。第二遍从后往前遍历，每个非空格放到剩余未编码空格数量*3的位置上。
  优点：无需额外的空间
  缺点：需要遍历两次
  方案二：新建一个iniString, capacity的数组。一次便利拷贝到新的数组里面。
  优点：只需要一次遍历，不会改动initString
  缺点：空间复杂度较高O(n)
 **/

class Replacement {
 public:
  string replaceSpace(string iniString, int length) {
    cout << iniString << endl;
    iniString.resize(3*length);

    // 找到空格数量
    int spaceNum = 0;
    for (int i = 0; i < length; ++i) {
      if (iniString.at(i) == ' ') {
        ++spaceNum;
      }
    }

    iniString[length+spaceNum*2+1-1] = '\0';
    // 从后往前遍历iniString,大挪移
    int end = length - 1;
    for (; end >= 0; --end) {
      if (iniString[end] != ' ') {
        iniString[end+spaceNum*2] = iniString[end];
      } else {
        iniString[end+spaceNum*2] = '0';
        iniString[end+spaceNum*2-1] = '2';
        iniString[end+spaceNum*2-2] = '%';
        --spaceNum;
      }
    }
    cout << iniString << endl;
    return iniString;
  }
};

int main() {
  Replacement obj;
  // 测试样例1
  if (obj.replaceSpace("Mr John Smith", 13) == "Mr%20John%20Smith") { // TODO(xf) 此处进不到if里面，如何判断带%的字符串相等
    cout << "case1: " << "\"Mr John Smith\" check ok" << endl;
  }

  // 测试样例2
  if (obj.replaceSpace("Hello  World", 12) == "Hello%20%20World") {
    cout << "case2: " << "\"Hello  World\" check ok" << endl;
  }

  // 特殊：空
  if (obj.replaceSpace("", 0) == "") {
    cout << "case3: " << "null check ok" << endl;
  }

  // 特殊：1
  if (obj.replaceSpace("1", 1) == "1") {
    cout << "case4: " << "1 check ok" << endl;
  }

  // 特殊：空格结尾
  if (obj.replaceSpace("1 ", 2) == "1%20") {
    cout << "case5: " << "\"1 \" check ok" << endl;
  }

  // 特殊：空格开头
  if (obj.replaceSpace(" 11", 3) == "%2011") {
    cout << "case6: " << "\" 11\" check ok" << endl;
  }

  // 特殊：一个空格
  if (obj.replaceSpace(" ", 1) == "%20") {
    cout << "case7: " << "\" \" check ok" << endl;
  }

  // 特殊：多个空格
  if (obj.replaceSpace("   ", 3) == "%20%20%20") {
    cout << "case8: " << "\"   \" check ok" << endl;
  }

  return 0;
}
