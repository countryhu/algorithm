#include <iostream>
#include <vector>

/**
  题目描述
  约瑟夫问题是一个非常著名的趣题，
  即由n个人坐成一圈，按顺时针由1开始给他们编号。
  然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。
  给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
  测试样例：
  5 3
  返回：
  4

  -------
  题目分析
 **/

class Joseph {
 public:
  int getResult(int n, int m) {
    // write code here
  }
};

int main() {
  // 样例
  {
    Joseph obj;
    std::cout << "obj.getResult(5, 3)=4:" << obj.getResult(5, 3) << std::endl;
  }
  return 0;
}
