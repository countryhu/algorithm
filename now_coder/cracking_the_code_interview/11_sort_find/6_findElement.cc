#include <iostream>
#include <vector>

/**
  题目描述
  有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。
  请设计一个高效的查找算法，查找矩阵中元素x的位置。
  给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，
  请返回一个二元数组，代表该元素的行号和列号(均从零开始)。保证元素互异。
  测试样例：
  [[1,2,3],[4,5,6]],2,3,6
  返回：
  [1,2]

  -------
  题目分析
 **/

class Finder {
 public:
  std::vector<int> findElement(std::vector<std::vector<int> > mat, int n, int m, int x) {
    int row = n - 1;
    int col = 0;
    while (row >= 0 && col <= m - 1) {
      if (mat[row][col] == x) {
        return {row, col};
      } else if (mat[row][col] < x) {
        col ++;
      } else {
        row --;
      }
    }
    return {-1, -1};
  }
};

int main() {
  // 样例
  {
    Finder obj;
    std::vector<std::vector<int> > mat = {{1,2,3}, {4,5,6}};
    auto ret = obj.findElement(mat, 2, 3, 5);
    for (auto val : ret) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
