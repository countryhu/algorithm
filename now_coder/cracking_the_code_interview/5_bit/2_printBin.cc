#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/**
  题目描述
  有一个介于0和1之间的实数，类型为double，返回它的二进制表示。
  如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
  给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
  测试样例：
  0.625
  返回：0.101

  -----

  题目分析
  1.
 **/

class BinDecimal {
 public:
  string printBin(double num) {
    if (num - 0.0 > -0.0000001 && num - 0.0 < 0.0000001) {
      return "0";
    }

    if (num - 1.0 > -0.0000001 && num - 1.0 < 0.0000001) {
      return "1";
    }

    string binaryDouble = "0.";
    for (int i = 1; i < 32; ++i) {
      num *= 2;
      if (num - 1.0 > -0.0000001 && num - 1.0 < 0.0000001) {
        num -= 1.0;
        binaryDouble.append(string(1, '1'));
        break;
      } else if (num - 1.0 > -0.0000001) {
        num -= 1.0;
        binaryDouble.append(string(1, '1'));
      } else {
        binaryDouble.append(string(1, '0'));
      }
    }

    if (num - 0.0 > 0.000001 || num - 0.0 < -0.0000001) {
      return "Error";
    } else {
      return binaryDouble;
    }
  }
};

int main() {
  BinDecimal obj;
  cout << "obj.printBin(0)" << obj.printBin(0) << endl; 
  cout << "obj.printBin(0.625)" << obj.printBin(0.625) << endl; 
  cout << "obj.printBin(0.5)" << obj.printBin(0.5) << endl; 
  cout << "obj.printBin(0.1)" << obj.printBin(0.1) << endl; 
  return 0;
}
