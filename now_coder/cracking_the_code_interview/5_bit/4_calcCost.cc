#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/**
  题目描述
  编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
  给定两个整数int A，int B。请返回需要改变的数位个数。
  测试样例：
  10,5
  返回：4
  -----

  题目分析
  1. 取异或之后，计算二进制1的个数
  2. 可以向有移位
  3. 可以每次-1，然后与 少一个1
 **/

class Transform {
 public:
  // int calcCost(int A, int B) {
    // int num = A ^ B;
    // int oneCount = 0;
    // while (num != 0) {
      // oneCount += num & 1;
      // num = num >> 1;
      // cout << num << endl;
    // }
    // return oneCount;
  // }

  int calcCost(int A, int B) {
    int num = A ^ B;
    int oneCount = 0;
    while (num != 0) {
      oneCount++;
      num = num & (num-1);
      cout << num << endl;
    }
    return oneCount;
  }
};

int main() {
  Transform obj;
  cout << "obj.calcCost(10, 5):" << obj.calcCost(10, 5) << endl;
  cout << "obj.calcCost(2, 0):" << obj.calcCost(2, 0) << endl;
  return 0;
}
