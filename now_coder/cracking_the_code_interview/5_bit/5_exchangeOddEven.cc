#include <iostream>
#include <string.h>
#include <bitset>
#include <stdio.h>

using namespace std;

/**
  题目描述
  请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
  给定一个int x，请返回交换后的数int。
  测试样例：
  10
  返回：5
  -----

  题目分析
  1.先取出奇数位，进行右移
  2.再取出偶数位, 进行左移
  3.两个数取或即可。
  错题本：
  1.32位16进制应该是多少算清楚，不要浮躁
 **/

class Exchange {
 public:
  int exchangeOddEven(int x) {
    int oodNum = x & 0x2AAAAAAA;  // 00101010101010101010101010101010
    int evenNum = x & 0x55555555; // 01010101010101010101010101010101

    return oodNum >> 1 | evenNum << 1;
  }
};

// int main() {
  // cout << sizeof(int) << endl;
  // Exchange obj;
  // int ret = obj.exchangeOddEven(711908);
  // cout << bitset<32>(711908) << endl;
  // cout << bitset<32>(ret) << endl;
  // cout << bitset<32>(388312) << endl;
  // return 0;
// }
