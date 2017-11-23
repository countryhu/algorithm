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
    int coins[4] = {1,5,10,25};
    int dp[100001] = {0};
    dp[0]=1;
    for(int i = 0; i < 4; i++) {
      for(int j = coins[i]; j <= n; j++) {
        dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
      }
    }
    return dp[n];
  }
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
