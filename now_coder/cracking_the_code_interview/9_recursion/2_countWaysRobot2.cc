#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
  题目描述
  有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。
  请设计一个算法，计算机器人有多少种走法。注意这次的网格中有些障碍点是不能走的。
  给定一个int[][] map(C++ 中为vector >),表示网格图，若map[i][j]为1则说明该点不是障碍点，
  否则则为障碍。另外给定int x,int y，表示网格的大小。
  请返回机器人从(0,0)走到(x - 1,y - 1)的走法数，为了防止溢出，请将结果Mod 1000000007。
  保证x和y均小于等于50

  -------
  题目分析
  1. 注意起点和终点就是 障碍点。。。
 **/

class Robot {
 public:
  Robot() {
  }

  int countWays(vector<vector<int> > map, int x, int y) {
    if (map[0][0] != 1 || map[x-1][y-1] != 1) {
      return 0;
    }
    ways[1][1] = 0;
    return myCountWays(map, x, y);
  }

 private:
  int myCountWays(const vector<vector<int> >& map, int x, int y) {
    if (x < 1 || y < 1) {
      return 0;
    }
    if (x == 2 && y == 1) {
      return map[1][0] == 1 ? 1 : 0;
    }
    if (x == 1 && y == 2) {
      return map[0][1] == 1 ? 1 : 0;
    }

    if (ways.find(x) != ways.end() && ways[x].find(y) != ways[x].end()) {
      return ways[x][y];
    }

    int waysFromUp = 0;
    if (x - 1 >= 1 && map[x-1-1][y-1] == 1) {
      waysFromUp= myCountWays(map, x - 1 , y); // 最后一步可能是从上面格子向下走的
    }
    int waysFromLeft = 0;
    if (y - 1 >= 1 && map[x-1][y-1-1] == 1) {
      waysFromLeft = myCountWays(map, x, y - 1); // 最后一步可能是从左侧格子向右走的
    }

    ways[x][y] = (waysFromUp % 1000000007 + waysFromLeft % 1000000007) % 1000000007;
    // std::cout << x << ":" << y << " total:" << ways[x][y] << " waysFromUp:" << waysFromUp << " waysFromLeft:" << waysFromLeft << std::endl;
    return ways[x][y];
  }

 private:
  std::map<int, std::map<int, long long> > ways;
};

int main() {
  // 样例
  {
    Robot obj;
   vector<vector<int> > map {{1,1,1}, {1,1,1},{1,1,1}};
    cout << "obj.countWays(3, 3):" << obj.countWays(map, 3, 3) << endl;
  }

  {
    Robot obj;
    vector<vector<int> > map {{1,0,1}, {1,1,1},{1,1,1}};
    cout << "obj.countWays(3, 3):" << obj.countWays(map, 3, 3) << endl;
  }

  {
    Robot obj;
    vector<vector<int> > map = {
      {0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
      {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
      {0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
      {0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
      {0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
      {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,1,0},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
      {1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1}};
    cout << "obj.countWays(17, 19):" << obj.countWays(map, 17, 19) << endl;
  }
  return 0;
}
