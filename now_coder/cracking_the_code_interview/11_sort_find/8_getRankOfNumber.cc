#include <iostream>
#include <vector>

/**
  题目描述
  现在我们要读入一串数，同时要求在读入每个数的时候算出它的秩，
  即在当前数组中小于等于它的数的个数(不包括它自身)，
  请设计一个高效的数据结构和算法来实现这个功能。
  给定一个int数组A，同时给定它的大小n，
  请返回一个int数组，元素为每次加入的数的秩。保证数组大小小于等于5000。
  测试样例：
  [1,2,3,4,5,6,7],7
  返回：
  [0,1,2,3,4,5,6]

  -------
  题目分析
 **/

class Rank {
 public:
  std::vector<int> getRankOfNumber(std::vector<int> A, int n) {
    // write code here
  }
};

int main() {
  // 样例
  {
    Rank obj;
    // std::cout << "obj.getResult(5, 3)=4:" << obj.getResult(5, 3) << std::endl;
  }
  return 0;
}
