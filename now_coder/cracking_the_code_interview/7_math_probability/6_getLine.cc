#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

/**
  题目描述
  在二维平面上，有一些点，请找出经过点数最多的那条线。
  给定一个点集vector<point>p和点集的大小n,没有两个点的横坐标相等的情况,
  请返回一个vector<double>，代表经过点数最多的那条直线的斜率和截距。

  -------
  题目分析
  1. 遍历所有2点组合，这样需要遍历很多次重复点（在同一条直线上的）。那么要怎么简化这个呢？
  2. 所以用斜率+截距作为组合 作为key 来索引 在同一条直线上的，点数。
  3. 注意double作为key判断相等逻辑,struct 判断小于 (la<ra) || (la==ra && lb<rb)
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

struct PointComp {
  bool operator() (const Point& lhs, const Point& rhs) const {
    return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y);
  }
};

struct Line {
 public:
  Line(const Point& p1, const Point& p2) {
    slope_ = double(p1.y - p2.y) / double(p1.x - p2.x);
    llSlope_ = slope_ * 10000;
    intercept_ = p1.y - slope_ * p1.x;
    llIntercept_ = intercept_ * 10000;
  }

  double slope_;
  long long llSlope_;
  double intercept_;
  long long llIntercept_;
};

struct LineComp {
  bool operator() (const Line& lhs, const Line& rhs) const {
    // attention the judge expression 
    return (lhs.llSlope_ < rhs.llSlope_)
        || (lhs.llSlope_ == rhs.llSlope_ && lhs.llIntercept_ < rhs.llIntercept_);
  }
};

class DenseLine {
 public:
  vector<double> getLine(vector<Point> points, int n) {
    std::map<Line, std::set<Point, PointComp>, LineComp> linePoints;
    (void)n;
    // (a,b) (b,a) slope intercept are same
    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        Line line(points[i], points[j]);
        linePoints[line].insert(points[i]);
        linePoints[line].insert(points[j]);
      }
    }

    // find the max pointCount line
    int maxPointCount = 0;
    Line maxPointLine = linePoints.begin()->first;
    for (auto iter : linePoints) {
      int pointCount = iter.second.size();
      if (pointCount > maxPointCount) {
        maxPointCount = pointCount;
        maxPointLine = iter.first;
      }
    }

    // push result slope and intercept
    vector<double> ret;
    ret.push_back(maxPointLine.slope_);
    ret.push_back(maxPointLine.intercept_);
    return ret;
  }
};

int main() {
  // 样例
  DenseLine obj;
  vector<Point> points{{1, 3},{2,5},{300,601},{0,0}};
  auto ret = obj.getLine(points, 4);
  cout << ret[0] << ":" << ret[1] << endl;
  return 0;
}
