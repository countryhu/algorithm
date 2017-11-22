#include <iostream>
#include <map>
#include <deque>

using namespace std;

/**
  题目描述
  有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
  给定一个int n，请返回n分有几种表示法。保证n小于等于100000，为了防止溢出，请将答案Mod 1000000007。
  测试样例：
  6
  返回：
  2

  -------
  题目分析
 **/

class Coins {
 public:
  int countWays(int n) {
    std::deque<int> couinKinds{25, 10, 5, 1};
    return myCountWays(n, couinKinds);
  }

 private:
  int myCountWays(int n, const std::deque<int>& coinKinds) {
    // std::cout << "n:" << n << " coinKinds.size:" << coinKinds.size() << std::endl;
    if (coinKinds.size() == 1) {
      return 1; // uniqueCoinKind有一种组合正好凑齐n
    }

    int bigestCoinKind = coinKinds.front();

    if (cacheMap_.find(bigestCoinKind) != cacheMap_.end() && cacheMap_[bigestCoinKind].find(n) != cacheMap_[bigestCoinKind].end()) {
      return cacheMap_[bigestCoinKind][n];
    }

    // 遍历最大面值硬币有多少个
    int maxBigCoinCount = n / bigestCoinKind;
    std::deque<int> excludedCoinKinds(coinKinds);
    excludedCoinKinds.pop_front();

    int ways = 0;
    for (int i = maxBigCoinCount; i >= 0; --i) {
      ways += myCountWays(n - i * bigestCoinKind, excludedCoinKinds) % 1000000007;
      ways %= 1000000007;
    }

    cacheMap_[bigestCoinKind][n] = ways;

    // std::cout << "n:" << n << " ways:" << ways << std::endl;
    return ways;
  }

 private:
  std::map<int, std::map<int, int> > cacheMap_;

};

int main() {
  // 样例
  {
    Coins obj;
    std::cout << "obj.countWays(6)=2:" << obj.countWays(6) << std::endl;
  }

  {
    Coins obj;
    std::cout << "obj.countWays(1)=1:" << obj.countWays(1) << std::endl;
  }

  {
    Coins obj;
    std::cout << "obj.countWays(100):" << obj.countWays(100) << std::endl;
  }
  {
    Coins obj;
    std::cout << "obj.countWays(1000):" << obj.countWays(1000) << std::endl;
  }

  {
    Coins obj;
    std::cout << "obj.countWays(10000):" << obj.countWays(10000) << std::endl;
  }

  {
    Coins obj;
    std::cout << "obj.countWays(100000):" << obj.countWays(100000) << std::endl;
  }
  return 0;
}
