#include <iostream>

using namespace std;

/**
  题目描述
  请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
  给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，
  0为求a ／ b，-1为求a － b。请返回计算的结果，保证数据合法且结果一定在int范围内。
  测试样例：
  1,2,1
  返回：2

  -------
  题目分析

 **/

class AddSubstitution {
 public:
  int calc(int a, int b, int type) {
    if (type == 1) {
      return multiply(a, b);
    } else if (type == 0) {
      return divide(a, b);
    } else if (type == -1) {
      return subtract(a, b);
    }
    return 0;
  }

 private:
  int multiply(int a, int b) {
    // 为了接下来循环次数少点
    if (abs(a) < abs(b)) {
      return multiply(b, a);
    }

    int num = 0;
    // 循环相加
    for (int i = 0; i < abs(b); ++i) {
      num += a;
    }

    if (b < 0) {
      num = negtive(num);
    }
    return num;
  }

  int divide(int a, int b) {
    int ret = 0;
    int num = 0;
    int absA = abs(a);
    int absB = abs(b);
    while (absA >= num) {
      num += absB;
      ret ++;
    }
    ret --;

    if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
      ret = negtive(ret);
    }
    return ret;
  }

  int subtract(int a, int b) {
    return a + negtive(b);
  }

  int negtive(int a) {
    int b = a > 0 ? -1 : 1;
    int num = 0;
    while (a != 0) {
      num += b;
      a += b;
    }
    return num;
  }

  int abs(int a) {
    return a > 0 ? a : negtive(a);
  }
};

int main() {
  AddSubstitution obj;
  // 样例 乘 1 * 2 = 2
  cout << "obj.calc(1, 2, 1) = 2:" << obj.calc(1, 2, 1) << endl;
  // 乘 -3 * -5 = 15
  cout << "obj.calc(-3, -5, 1) = 15:" << obj.calc(-3, -5, 1) << endl;
  // 乘 -5 * 1 = -5
  cout << "obj.calc(-5, 1, 1) = -5:" << obj.calc(-5, 1, 1) << endl;

  // 除 2 / 1 = 2
  cout << "obj.calc(2, 1, 0) = 2:" << obj.calc(2, 1, 0) << endl;
  // 除 2 / -1 = -2
  cout << "obj.calc(2, -1, 0) = -2:" << obj.calc(2, -1, 0) << endl;

  // 减 -1 - -2 = 1
  cout << "obj.calc(-1, -2, -1) = 1:" << obj.calc(-1, -2, -1) << endl;
  // 减 1 - 2 = -1
  cout << "obj.calc(1, 2, -1) = -1:" << obj.calc(1, 2, -1) << endl;
  return 0;
}
