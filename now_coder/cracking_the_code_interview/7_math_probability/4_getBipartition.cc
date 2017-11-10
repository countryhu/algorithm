#include <iostream>
#include <vector>

using namespace std;

/**
  题目描述
  在二维平面上，有两个正方形，请找出一条直线，能够将这两个正方形对半分。
  假定正方形的上下两条边与x轴平行。
  给定两个vecotrA和B，分别为两个正方形的四个顶点。
  请返回一个vector，代表所求的平分直线的斜率和截距，保证斜率存在。
  测试样例：
  [(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]
  返回：
  [0.0，0.5]

  -------
  题目分析
 **/

struct Point {
  int x;
  int y;
  Point() :
      x(0), y(0) {
      }
  Point(int xx, int yy) {
    x = xx;
    y = yy;
  }
};

class Bipartition {
 public:
  vector<double> getBipartition(vector<Point> A, vector<Point> B) {
    vector<double> rets;
    double p1x = (A[0].x + A[1].x + A[2].x + A[3].x) / 4.0;
    double p1y = (A[0].y + A[1].y + A[2].y + A[3].y) / 4.0;
    double p2x = (B[0].x + B[1].x + B[2].x + B[3].x) / 4.0;
    double p2y = (B[0].y + B[1].y + B[2].y + B[3].y) / 4.0;

    double xielv = (p1y - p2y) / (p1x - p2x);
    double jieju = p1y - p1x * xielv;
    rets.push_back(xielv);
    rets.push_back(jieju);
    return rets;
  }
};

int main() {
  vector<Point> rect1{{0,0},{0,1},{1,1},{1,0}};
  vector<Point> rect2{{1,0},{1,1},{2,0},{2,1}};
  // 样例
  Bipartition obj;
  auto ret = obj.getBipartition(rect1, rect2);
  cout << ret[0] << ":" << ret[1] << endl;
  return 0;
}
