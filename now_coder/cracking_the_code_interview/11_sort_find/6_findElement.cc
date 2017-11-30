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
    return myFindElement(mat, 0, 0, n - 1, m - 1, x);
  }

 private:
  std::vector<int> myFindElement(std::vector<std::vector<int> > mat, int startX, int startY, int endX, int endY, int x) {
    std::cout << " startX:" << startX << " startY:" << startY << " endX:" << endX << " endY:" << endY << std::endl;
    if (startX > endX || startY > endY) {
      std::cout << "err startX:" << startX << " startY:" << startY << " endX:" << endX << " endY:" << endY << std::endl;
      return std::vector<int>();
    }

    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;
    if (mat[midX][midY] == x) {
      return {midX, midY};
    }

    if (mat[midX][midY] > x) { // 左上
      return myFindElement(mat, startX, startY, midX, midY, x);
    } else if (mat[midX][endY] >= x) { // 右上
      return myFindElement(mat, startX, midY + 1, midX, endY, x);
    } else if (mat[endX][midY] >= x) { // 左下
      return myFindElement(mat, midX + 1, startY, endX, midY, x);
    } else { // 右下
      return myFindElement(mat, midX + 1, midY + 1, endX, endY, x);
    }
  }
};

int main() {
  // 样例
  {
    Finder obj;
    std::vector<std::vector<int> > mat = {{1,2,3}, {4,5,6}};
    auto ret = obj.findElement(mat, 2, 3, 1);
    for (auto val : ret) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
