#include <iostream>
#include <string>
#include <vector>
#include "util/to_string.h"

using namespace std;
/**
  题目描述
  有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
  给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
  测试样例：
  [[1,2,3],[4,5,6],[7,8,9]],3
  返回：[[7,4,1],[8,5,2],[9,6,3]]

  -----
  题目分析
  注意点：
  1. 该题目几乎每个元素都要移动，所以最小操作时间复杂度是N*N
  2. 找到旋转公式，举例法找到公式
  错题本：

  方案一:每层遍历，按边swap
  已经是时间复杂度(O(N*N))最低的了，因为每个点都要移动。空间复杂度为O(1)只需要一个临时变量用来置换
 **/

class Transform {
 public:
  vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    // 旋转边长, 从外向内
    for (int sideLength = n; sideLength >= 2; sideLength=sideLength-2) {
      transform4Sides(mat, n, sideLength);
    }
    return mat;
  }

 private:
    void transform4Sides(vector<vector<int> >& mat, int n, int sideLength) {
      int first = (n-sideLength) / 2;
      int last = n - 1 - first;
      for (int i = first; i < last; ++i) {
        // 缓存上边(first,first), (first,last)
        int temp = mat[first][i];

        // 旋转左边->上边
        mat[first][i] = mat[n-1-i][first];

        // 旋转下边->左边
        mat[n-1-i][first] = mat[last][n-1-i];

        // 旋转右边->下边
        mat[last][n-1-i] = mat[i][last];

        // 旋转上边->右边
        mat[i][last] = temp;
      }
    }
};

static int caseN = 0;
void TestCase(vector<vector<int> > input, int n, const vector<vector<int> >& expectOutput) {
  cout << "case enter. with input:" << util::ToString(input);

  Transform obj;
  auto output = obj.transformImage(input, n);
  if (output == expectOutput) {
    cout << "case" << ++caseN << ": check ok. with input:" << util::ToString(input)
        << "\n output as expect:" << util::ToString(output) << endl;
  } else {
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
        << "case" << ++caseN << ": check failed. with input:" << util::ToString(input)
        << "\n-------------------------------\n"
        << "   expectOutput:" << util::ToString(expectOutput)
        << "\n-------------------------------\n"
        << "but actuaOutput:" << util::ToString(output)
        << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
}

int main() {
  vector<vector<int> > input = {{1,2,3}, {4,5,6}, {7,8,9}};
  vector<vector<int> > expectOutput = {{7,4,1},{8,5,2},{9,6,3}};
  // 测试用例
  TestCase(input, 3, expectOutput);

  // 特殊：偶数个
  TestCase({{1,2}, {3,4}}, 2, {{3,1}, {4,2}});

  // 特殊：一个
  TestCase({{1}}, 1, {{1}});

  // 特殊：null
  TestCase({{}}, 0, {{}});
  return 0;
}
