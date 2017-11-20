#include <iostream>
#include <list>
#include <map>

using namespace std;

/**
  题目描述
  有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
  给定一个数int k，请返回第k个数。保证k小于等于100。
  测试样例：
  3
  返回：7

  -------
  题目分析
  1. 分多队列放素因子abc。防止a*b<c的题目
 **/

class KthNumber {
 public:
  int findKth(int k) {
    std::map<int, std::list<int> > waitMap;
    waitMap[3].push_back(3);
    waitMap[5].push_back(5);
    waitMap[7].push_back(7);

    int kTh = 1;
    while (k--) {
      int minHeaderListKey = GetMinHeaderList(waitMap);
      if (minHeaderListKey == 3) {
        kTh = waitMap[3].front();
        waitMap[3].pop_front();

        waitMap[3].push_back(kTh * 3);
        waitMap[5].push_back(kTh * 5);
        waitMap[7].push_back(kTh * 7);
      } else if (minHeaderListKey == 5) {
        kTh = waitMap[5].front();
        waitMap[5].pop_front();

        waitMap[5].push_back(kTh * 5);
        waitMap[7].push_back(kTh * 7);
      } else if (minHeaderListKey == 7) {
        kTh = waitMap[7].front();
        waitMap[7].pop_front();

        waitMap[7].push_back(kTh * 7);
      }
    }
    return kTh;
  }

 private:
  int GetMinHeaderList(const std::map<int, std::list<int> >& waitMap) {
    int minValue = 0;
    int minKey = 0;
    for (auto iter : waitMap) {
      auto& waitList = iter.second;
      if (!waitList.empty() ) {
        if (minValue == 0 || waitList.front() < minValue) {
          minValue = waitList.front();
          minKey = iter.first;
        }
      }
    }
    return minKey;
  }
};

int main() {
  // 样例
  KthNumber obj;
  cout << "obj.findKth(1)=3:" << obj.findKth(1) << endl;
  cout << "obj.findKth(2)=5:" << obj.findKth(2) << endl;
  cout << "obj.findKth(3)=7:" << obj.findKth(3) << endl;
  cout << "obj.findKth(4)=9:" << obj.findKth(4) << endl;
  cout << "obj.findKth(5):" << obj.findKth(5) << endl;
  cout << "obj.findKth(6):" << obj.findKth(6) << endl;
  cout << "obj.findKth(7):" << obj.findKth(7) << endl;
  cout << "obj.findKth(8):" << obj.findKth(8) << endl;
  cout << "obj.findKth(9):" << obj.findKth(9) << endl;
  cout << "obj.findKth(10):" << obj.findKth(10) << endl;
  cout << "obj.findKth(11):" << obj.findKth(11) << endl;
  cout << "obj.findKth(12):" << obj.findKth(12) << endl;
  cout << "obj.findKth(100):" << obj.findKth(100) << endl;
  return 0;
}
