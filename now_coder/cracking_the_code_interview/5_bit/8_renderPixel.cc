#include <iostream>
#include <string.h>
#include <bitset>
#include <stdio.h>

using namespace std;

/**
  题目描述
有一个单色屏幕储存在一维数组中，其中数组的每个元素代表连续的8位的像素的值，请实现一个函数，将第x到第y个像素涂上颜色(像素标号从零开始)，并尝试尽量使用最快的办法。
给定表示屏幕的数组screen(数组中的每个元素代表连续的8个像素，且从左至右的像素分别对应元素的二进制的从低到高位)，以及int x,int y，意义如题意所述，保证输入数据合法。请返回涂色后的新的屏幕数组。
测试样例：
[0,0,0,0,0,0],0,47
返回：[255,255,255,255,255,255]
  -----

  题目分析
  1.先取出奇数位，进行右移
 **/

class Render {
public:
    vector<int> renderPixel(vector<int> screen, int x, int y) {
        // write code here
    }
};

int main() {
  cout << sizeof(int) << endl;
  Finder obj;
  int ret = obj.exchangeOddEven(711908);
  cout << bitset<32>(711908) << endl;
  cout << bitset<32>(ret) << endl;
  cout << bitset<32>(388312) << endl;
  return 0;
}
