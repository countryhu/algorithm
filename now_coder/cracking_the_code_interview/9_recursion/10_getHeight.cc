#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
  题目描述
  有一堆箱子，每个箱子宽为wi，长为di，高为hi，现在需要将箱子都堆起来，
  而且为了使堆起来的箱子不到，上面的箱子的宽度和长度必须小于下面的箱子。
  请实现一个方法，求出能堆出的最高的高度，这里的高度即堆起来的所有箱子的高度之和。
  给定三个int数组w,l,h，分别表示每个箱子宽、长和高，同时给定箱子的数目n。
  请返回能堆成的最高的高度。保证n小于等于500。

  测试样例：
  [1,1,1],[1,1,1],[1,1,1]
  返回：
  1

  -------
  题目分析
 **/

class Box {
 public:
  int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
    int maxHeight = 0;
    for (int i = 0; i < n; ++i) {
      int height = myGetHeight(w, l, h, n, i);
      if (height > maxHeight) {
        maxHeight = height;
      }
    }
    return maxHeight;
  }

 private:
  int myGetHeight(vector<int> w, vector<int> l, vector<int> h, int n, int bottom) {
    if (maxHeightMap.find(bottom) != maxHeightMap.end()) {
      return maxHeightMap[bottom];
    }

    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
      if (w[i] < w[bottom] && l[i] < l[bottom]) {
        int upperMaxHeight = myGetHeight(w, l, h, n, i);
        if (upperMaxHeight > maxHeight) {
          maxHeight = upperMaxHeight;
        }
      }
    }
    maxHeightMap[bottom] = maxHeight + h[bottom];
    return maxHeightMap[bottom];
  }

  std::map<int, int> maxHeightMap;
};

int main() {
  // 样例
  {
    Box obj;
    vector<int> w = {1,1,1};
    vector<int> l = {1,1,1};
    vector<int> h = {1,1,1};
    std::cout << "obj.getHeight()=1:" << obj.getHeight(w, l, h, 3) << std::endl;
  }

  {
    Box obj;
    vector<int> w = {3,2,1};
    vector<int> l = {3,2,1};
    vector<int> h = {1,1,1};
    std::cout << "obj.getHeight()=3:" << obj.getHeight(w, l, h, 3) << std::endl;
  }

  {
    Box obj;
    vector<int> w = {4,5,10,3};
    vector<int> l = {4,3,10,3};
    vector<int> h = {1,1,1, 3};
    std::cout << "obj.getHeight()=?:" << obj.getHeight(w, l, h, 4) << std::endl;
  }

  {
    Box obj;
    vector<int> w = {4,5,10,3};
    vector<int> l = {4,3,10,3};
    vector<int> h = {1,3,1, 1};
    std::cout << "obj.getHeight()=?:" << obj.getHeight(w, l, h, 4) << std::endl;
  }
  return 0;
}
