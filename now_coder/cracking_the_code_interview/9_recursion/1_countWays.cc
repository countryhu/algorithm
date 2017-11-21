#include <iostream>
#include <map>

using namespace std;

/**
  题目描述
  有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。
  请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
  给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
  测试样例：
  1
  返回：1

  -------
  题目分析
 **/

class GoUpstairs {
 public:
  GoUpstairs() {
    ways[1] = 1;
    ways[2] = 2;
    ways[3] = 4;
  }

  int countWays(int n) {
    if (ways.find(n) != ways.end()) {
        return ways[n];
    }
    ways[n] = ((countWays(n-1) % 1000000007 + countWays(n-2) % 1000000007) % 1000000007
               + countWays(n-3) % 1000000007)  % 1000000007;
    // std::cout << "n:" << n << ":" << ways[n] << std::endl;
    return ways[n];
  }

 private:
    std::map<int, long long> ways;
};

int main() {
  // 样例
  {
    GoUpstairs obj;
    cout << "obj.countWays(1)=1:" << obj.countWays(1) << endl;
  }

  {
    GoUpstairs obj;
    cout << "obj.countWays(4)=7:" << obj.countWays(4) << endl;
  }

  {
    GoUpstairs obj;
    cout << "obj.countWays(7):" << obj.countWays(7) << endl;
  }

  {
    GoUpstairs obj;
    cout << "obj.countWays(70):" << obj.countWays(70) << endl;
  }

  {
    GoUpstairs obj;
    cout << "obj.countWays(7000):" << obj.countWays(7000) << endl;
  }
  return 0;
}
