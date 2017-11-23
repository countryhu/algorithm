#include <cmath>
#include <iostream>
#include <vector>
#include "util/to_string.h"

using namespace std;

/**
  题目描述
  请设计一种算法，解决著名的n皇后问题。
  这里的n皇后问题指在一个nxn的棋盘上放置n个棋子，
  使得每行每列和每条对角线上都只有一个棋子，求其摆放的方法数。

  给定一个int n，请返回方法数，保证n小于等于15
  测试样例：
  1
  返回：
  1

  -------
  题目分析
 **/

class Queens {
 public:
  int nQueens(int n) {
    std::vector<int> confirmedPos;
    return myNQueens(n, confirmedPos);
  }

 private:
  int myNQueens(int n, const std::vector<int>& confirmedPos) {
    if ((int)confirmedPos.size() == n) { // 放满n个了
      // std::cout << " confirmedPos:" << util::ToString(confirmedPos) << std::endl;
      return 1;
    }

    int nQueuesWays = 0;
    for (int column = 0; column < n; column++) {
      bool ret = IsValid(confirmedPos, confirmedPos.size(), column);
      // std::cout << " confirmedPos:" << util::ToString(confirmedPos)
          // << " checkrow:" << confirmedPos.size()
          // << " checkColumn:" << column << " ret:" << ret << std::endl;
      if (ret) {
        std::vector<int> newRowPos(confirmedPos);
        newRowPos.push_back(column);
        nQueuesWays += myNQueens(n, newRowPos);
      }
    }
    return nQueuesWays;
  }

  bool IsValid(const std::vector<int>& confirmedPos, int checkRow, int checkColumn) {
    for (int i = 0; i < (int)confirmedPos.size(); ++i) {
      // 检查是否已经有同列的
      int column = confirmedPos[i];
      if (column == checkColumn) {
        return false;
      }

      // 检查是否已经有同一对角线的
      if (std::abs(checkRow - i) == std::abs(checkColumn - column)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  // 样例
  {
    Queens obj;
    std::cout << "obj.nQueens(1)=1:" << obj.nQueens(1) << std::endl;
  }
  {
    Queens obj;
    std::cout << "obj.nQueens(2)=0:" << obj.nQueens(2) << std::endl;
  }
  {
    Queens obj;
    std::cout << "obj.nQueens(3)=0:" << obj.nQueens(3) << std::endl;
  }
  {
    Queens obj;
    std::cout << "obj.nQueens(5)=?:" << obj.nQueens(5) << std::endl;
  }
  {
    Queens obj;
    std::cout << "obj.nQueens(6)=?:" << obj.nQueens(6) << std::endl;
  }
  {
    Queens obj;
    std::cout << "obj.nQueens(8)=?:" << obj.nQueens(8) << std::endl;
  }

  {
    Queens obj;
    std::cout << "obj.nQueens(15)=?:" << obj.nQueens(15) << std::endl;
  }
  return 0;
}
