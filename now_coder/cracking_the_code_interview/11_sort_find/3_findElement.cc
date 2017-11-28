#include <iostream>
#include <vector>

/**
  题目描述
  有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
  例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],
  现在对于移位后的数组，需要查找某个元素的位置。
  请设计一个复杂度为log级别的算法完成这个任务。
  给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，
  请返回x的位置(位置从零开始)。保证数组中元素互异。

  测试样例：
  [6,1,2,3,4,5],6,6

  返回：
  0

  -------
  题目分析
 **/

class Finder {
public:
    int findElement(std::vector<int> A, int n, int x) {
        // write code here
    }
};

int main() {
  // 样例
  {
    Finder obj;
    // std::cout << "obj.getResult(5, 3)=4:" << obj.getResult(5, 3) << std::endl;
  }
  return 0;
}
