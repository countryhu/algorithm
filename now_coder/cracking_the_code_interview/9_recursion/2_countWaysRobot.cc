#include <iostream>
#include <map>

using namespace std;

/**
  题目描述
  有一个XxY的网格，一个机器人只能走格点且只能\向右或向下\走，要从左上角走到右下角。
  请设计一个算法，计算机器人有多少种走法。
  给定两个正整数int x,int y，请返回机器人的走法数目。
  保证x＋y\小于等于12\。

  测试样例：
  2,2
  返回：2

  -------
  题目分析
 **/

class Robot {
 public:
  Robot() {
    ways[1][1] = 0;
    ways[2][1] = 1;
    ways[1][2] = 1;
  }

  int countWays(int x, int y) {
    if (x < 1 || y < 1) {
      std::cerr << "invalid param x:" << x << " y:" << y << std::endl;
      return 0;
    }

    if (ways.find(x) != ways.end() && ways[x].find(y) != ways[x].end()) {
      return ways[x][y];
    }

    int waysFromUp = 0;
    if (x - 1 >= 1) {
      waysFromUp= countWays(x - 1 , y); // 最后一步可能是从上面格子向下走的
    }
    int waysFromLeft = 0;
    if (y - 1 >= 1) {
      waysFromLeft = countWays(x, y - 1); // 最后一步可能是从左侧格子向右走的
    }

    ways[x][y] = waysFromUp + waysFromLeft;
    // std::cout << x << ":" << y << " total:" << ways[x][y] << " waysFromUp:" << waysFromUp << " waysFromLeft:" << waysFromLeft << std::endl;
    return ways[x][y];
  }

 private:
  std::map<int, std::map<int, int> > ways;
};

int main() {
  // 样例
  {
    Robot obj;
    cout << "obj.countWays(2, 2)=2:" << obj.countWays(2, 2) << endl;
  }

  {
    Robot obj;
    cout << "obj.countWays(1, 2):" << obj.countWays(1, 2) << endl;
  }

  {
    Robot obj;
    cout << "obj.countWays(3, 3):" << obj.countWays(3, 3) << endl;
  }
  return 0;
}
