#include <iostream>
#include <math.h>

using namespace std;

/**
  题目描述
  给定直角坐标系上的两条直线，确定这两条直线会不会相交。
  线段以斜率和截距的形式给出，即double s1，double s2，double y1，double y2，
  分别代表直线1和2的斜率(即s1,s2)和截距(即y1,y2)，请返回一个bool，
  代表给定的两条直线是否相交。这里两直线重合也认为相交。

  测试样例：
  3.14, 3.14, 1, 2
  返回：
  false

  -------
  题目分析
  1.审题，斜率截距对应字母
 **/

class CrossLine {
 public:
  bool checkCrossLine(double s1, double s2, double y1, double y2) {
    if (DoubleEQ(s1, s2)) { // 斜率一样
      return DoubleEQ(y1, y2);
    } else {
      return true;
    }
  }

 private:
  bool DoubleEQ(double a, double b) {
    return fabs(a - b) < 0.000001 && fabs(a - b) > -0.000001;
  }
};

int main() {
  CrossLine obj;
  // 样例(平行) false
  cout << "obj.checkCrossLine(3.14, 3.14, 1, 2):" << obj.checkCrossLine(3.14, 3.14, 1, 2) << endl;
  // 交叉 true
  cout << "obj.checkCrossLine(1, 1.5, 2, 3):" << obj.checkCrossLine(1, 1.5, 2, 3) << endl;
  // 重合 true
  cout << "obj.checkCrossLine(1, 1, 2, 2):" << obj.checkCrossLine(1, 1, 2, 2) << endl;
  return 0;
}
