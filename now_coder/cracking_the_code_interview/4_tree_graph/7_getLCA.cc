#include <iostream>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <set>
#include <queue>

using namespace std;

/**
  题目描述
  有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。
  现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
  给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
  测试样例：
  2，3
  返回：1
  -----

  题目分析
  1.
 **/

class LCA {
 public:
  int getLCA(int a, int b) {
    set<int> flags;
    flags.insert(a);
    while(a > 1) {
      int parent = a / 2;
      flags.insert(parent);
      a = parent;
    }

    while (b >= 1) {
      if (flags.find(b) != flags.end()) {
        return b;
      }
      b = b / 2;
    }

    return 1;
  }
};

int main() {
  LCA obj;
  cout << "getLCA(2, 3):" << obj.getLCA(2, 3) << endl;
  cout << "getLCA(5, 9):" << obj.getLCA(5, 9) << endl;
  cout << "getLCA(5, 15):" << obj.getLCA(5, 15) << endl;
  cout << "getLCA(1, 1):" << obj.getLCA(1, 1) << endl;
  cout << "getLCA(3, 15):" << obj.getLCA(3, 15) << endl;
  return 0;
}

