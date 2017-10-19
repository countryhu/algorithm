#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bitset>
#include <vector>

using namespace std;

/**
  题目描述
  有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
  给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
  测试样例：
  2
  返回：[1,4]
  -----

  题目分析
  1.
 **/

class CloseNumber {
 public:
  vector<int> getCloseNumber(int x) {
    vector<int> rets;
    // 获取略小值
    bitset<32> binNumberMin(x);
    cout << "         x:" << binNumberMin << " " << binNumberMin.to_ulong() << endl;
    int alreadeHave0Pos = FindFirstToLeft(binNumberMin, 0, 0);
    int needMove1Pos = FindFirstToLeft(binNumberMin, 1, alreadeHave0Pos + 1);
    int needMove0Pos = FindFirstToRight(binNumberMin, 0, needMove1Pos - 1);
    binNumberMin[needMove1Pos] = 0;
    binNumberMin[needMove0Pos] = 1;
    cout << "min closer:" << binNumberMin << " " << binNumberMin.to_ulong() << endl;
    rets.push_back((int)binNumberMin.to_ulong());

    // 获取略大值
    bitset<32> binNumberMax(x);
    needMove1Pos = FindFirstToLeft(binNumberMax, 1, 0);
    needMove0Pos = FindFirstToLeft(binNumberMax, 0, needMove1Pos + 1);
    binNumberMax[needMove1Pos] = 0;
    binNumberMax[needMove0Pos] = 1;
    cout << "max closer:" << binNumberMax << " " << binNumberMax.to_ulong() << endl;
    rets.push_back((int)binNumberMax.to_ulong());
    return rets;
  }

 private:
  int FindFirstToLeft(const bitset<32>& bitNum, bool findVal, int startPos) {
    for (int i = startPos; i < 32; ++i) {
      if (bitNum[i] == findVal) {
        return i;
      }
    }
    return -1;
  }
  int FindFirstToRight(const bitset<32>& bitNum, bool findVal, int startPos) {
    for (int i = startPos; i >= 0; --i) {
      if (bitNum[i] == findVal) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  CloseNumber obj;
  obj.getCloseNumber(2);
  obj.getCloseNumber(2034);
  obj.getCloseNumber(76351);

  cout << "max c76284:" << bitset<32>(76284) << endl;
  cout << "max c76383:" << bitset<32>(76383) << endl;
  return 0;
}
