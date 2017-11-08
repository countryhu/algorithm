#include <iostream>
#include <string.h>
#include <bitset>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  有一个单色屏幕储存在一维数组中，其中数组的每个元素代表连续的8位的像素的值，
  请实现一个函数，将第x到第y个像素涂上颜色(像素标号从零开始)，并尝试尽量使用最快的办法。
  给定表示屏幕的数组screen(数组中的每个元素代表连续的8个像素，
  且从左至右的像素分别对应元素的二进制的从低到高位)，
  以及int x,int y，意义如题意所述，保证输入数据合法。请返回涂色后的新的屏幕数组。
  测试样例：
  [0,0,0,0,0,0],0,47
  返回：[255,255,255,255,255,255]

  -----

  题目分析
  错题分析
  1. 从左至右的像素分别对应元素的二进制的从低到高位,不要着急。慢慢读好题再做。
 **/

class Render {
 public:
  vector<int> renderPixel(vector<int> screen, int x, int y) {
    for (int i = x; i <= y; ++i) {
      RenderBit(i, &screen);
    }
    return screen;
  }

 private:
  void RenderBit(int i, vector<int>* screen) {
    int mark = 1 << (i % 8);
    (*screen)[i / 8] |= mark;
  }
};

int main() {
  vector<int> screen{0,0,0,0,0,0};
  Render obj;
  vector<int> ret = obj.renderPixel(screen, 0, 47);
  cout << "ret:";
  for (auto val : ret) {
    cout << val << " ";
  }
  cout << endl;

  ret = obj.renderPixel(screen, 1, 15);
  cout << "ret:";
  for (auto val : ret) {
    cout << val << " ";
  }
  cout << endl;

  ret = obj.renderPixel(screen, 1, 1);
  cout << "ret:";
  for (auto val : ret) {
    cout << val << " ";
  }
  cout << endl;

  vector<int> screen1{0,0};
  ret = obj.renderPixel(screen1, 7, 7);
  cout << "ret:";
  for (auto val : ret) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
