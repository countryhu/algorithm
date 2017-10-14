#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "util/to_string.h"

using namespace std;
/**
  题目描述
  请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
  给定一个N阶方阵int{}{}(C++中为vector<vector><int>>)mat和矩阵的阶数n，请返回完成操作后的int{}{}方阵(C++中为vector<vector><int>>)，
  保证n小于等于300，矩阵中的元素为int范围内。</int></vector></int></vector>
  测试样例：
  {{1,2,3},{0,1,2},{0,0,1}}
  返回：{{0,0,3},{0,0,0},{0,0,0}}

  -----
  题目分析
  注意点：
  1. 某个元素为零，不代表只有一个元素为0. 所以需要遍历完
  2. 由于行列数区间都是{0, 300} 可以用数组缓存相关数据。

  方案一 : 遍历数组，记下哪些行哪些列有0出现过。然后遍历这个两个缓存数组,发现需要清零的行/列直接循环删除
  优点: 存储空间比较小O(n), 时间复杂度O(n)只需要两次遍历。
  改进点: 可以考虑按位存储，空间可以变成原来1/8
 **/

class Clearer {
 public:
  vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
    bool zeroRows[300];
    memset(zeroRows, 0, 300);
    bool zeroColumns[300];
    memset(zeroColumns, 0, 300);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          zeroRows[i] = true;
          zeroColumns[j] = true;
        }
      }
    }

    // 清零行
    for (int row = 0; row < n; ++row) {
      if (zeroRows[row]) {
        for (int col = 0; col < n; ++col) {
          mat[row][col] = 0;
        }
      }
    }

    // 清零列
    for (int col = 0; col < n; ++col) {
      if (zeroColumns[col]) {
        for (int row = 0; row < n; ++row) {
          mat[row][col] = 0;
        }
      }
    }

    return mat;
  }
};

static int caseN = 0;
void TestCase(vector<vector<int> > input, int n, const vector<vector<int> >& expectOutput) {
  cout << "case enter. with input:" << util::ToString(input);

  Clearer obj;
  auto output = obj.clearZero(input, n);
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
  // 测试用例
  TestCase({{1,2,3},{0,1,2},{0,0,1}}, 3, {{0,0,3},{0,0,0},{0,0,0}});

  // 特殊：偶数个
  TestCase({{1,2}, {3,4}}, 2, {{1,2}, {3,4}});

  // 特殊：一个
  TestCase({{0}}, 1, {{0}});

  // 特殊：null
  TestCase({{}}, 0, {{}});
  return 0;
}
