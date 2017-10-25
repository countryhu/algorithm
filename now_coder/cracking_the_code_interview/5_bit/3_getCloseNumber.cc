#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <climits>

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
  1.x 是正整数，可以遍历
 **/

class CloseNumber {
 public:
  vector<int> getCloseNumber(int x) {
    vector<int> rets;
    int xOneBitsCount = OneBitsCount(x);

    // 找较小值
    for (int closeLess = x - 1; closeLess >= 0; --closeLess) {
      if (OneBitsCount(closeLess) == xOneBitsCount) {
        rets.push_back(closeLess);
        break;
      }
    }

    // 找较大值
    for (int closeBigger = x + 1; closeBigger <= INT_MAX; ++closeBigger) {
      if (OneBitsCount(closeBigger) == xOneBitsCount) {
        rets.push_back(closeBigger);
        break;
      }
    }
    return rets;
  }

 private:
  int OneBitsCount(int x) {
    int count = 0;
    while (x > 0) {
      x = x & (x-1);
      count ++;
    }
    return count;
  }
};

int main() {
  CloseNumber obj;
  obj.getCloseNumber(2);
  obj.getCloseNumber(2034);

  std::vector<int> rets = obj.getCloseNumber(76351);
  cout << "val c76351:" << bitset<32>(76351) << endl;

  cout << "min c76284:" << bitset<32>(rets[0]) << endl;
  cout << "min c76284:" << bitset<32>(76284) << endl;

  cout << "max c76284:" << bitset<32>(rets[1]) << endl;
  cout << "max c76383:" << bitset<32>(76383) << endl;
  return 0;
}
