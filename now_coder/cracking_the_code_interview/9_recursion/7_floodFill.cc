#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <map>

/**
  题目描述
  在一个nxm矩阵形状的城市里爆发了洪水，洪水从(0,0)的格子流到这个城市，
  在这个矩阵中有的格子有一些建筑，洪水只能在没有建筑的格子流动。
  请返回洪水流到(n - 1,m - 1)的最早时间(洪水只能从一个格子流到其相邻的格子且洪水单位时间能从一个格子流到相邻格子)。
  给定一个矩阵map表示城市，其中map[i][j]表示坐标为(i,j)的格子，值为1代表该格子有建筑，0代表没有建筑。
  同时给定矩阵的大小n和m(n和m均小于等于100)，请返回流到(n - 1,m - 1)的最早时间。保证洪水一定能流到终点。

  -------
  题目分析
 **/

class Flood {
 public:
  int floodFill(std::vector<std::vector<int> > map, int n, int m) {
    return myFloodFill(map, n, m);
  }

 private:
  int myFloodFill(const std::vector<std::vector<int> >& map, int n, int m) {
    // 只有一个点，起点即是终点。
    if (n == 1 && m == 1) {
      return 0;
    }

    // 初始化图访问状态
    std::map<size_t, std::map<size_t, Node*> > bfsMap_;
    for (size_t i = 0; i < map.size(); ++i) {
      for (size_t j = 0; j < map[i].size(); ++j) {
        Node* node = new Node(i, j);
        bfsMap_[i][j] = node;
      }
    }

    // bfs
    std::list<Node*> visitingList;
    visitingList.push_back(bfsMap_[0][0]); // 上
    bfsMap_[0][0]->visitState_ = Node::Visiting;

    while (!visitingList.empty()) {
      Node* node = visitingList.front();
      visitingList.pop_front();
      // std::cout << "====" << node->x_ << ":" << node->y_ << std::endl;

      // 邻点入栈: 左
      if (node->y_ - 1 >= 0 // 边界
          && map[node->x_][node->y_ - 1] == 0 // 没有阻碍物
          && bfsMap_[node->x_][node->y_ - 1]->visitState_ == Node::UnVisit) { // 未访问过
        Node* nearNode = bfsMap_[node->x_][node->y_ - 1];
        nearNode->dis_ = node->dis_ + 1;
        // 是否到达终点
        if (nearNode->x_ == n - 1 && nearNode->y_ == m - 1) {
          return nearNode->dis_;
        }
        nearNode->visitState_ = Node::Visiting;
        visitingList.push_back(nearNode);
        // std::cout << "push :"  << nearNode->x_ << ":" << nearNode->y_ << std::endl;
      }

      // 邻点入栈: 右
      if (node->y_ + 1 <= m - 1  // 边界
          && map[node->x_][node->y_ + 1] == 0 // 没有阻碍物
          && bfsMap_[node->x_][node->y_ + 1]->visitState_ == Node::UnVisit) { // 未访问过
        Node* nearNode = bfsMap_[node->x_][node->y_ + 1];
        nearNode->dis_ = node->dis_ + 1;
        // 是否到达终点
        if (nearNode->x_ == n - 1 && nearNode->y_ == m - 1) {
          return nearNode->dis_;
        }
        nearNode->visitState_ = Node::Visiting;
        visitingList.push_back(nearNode);
        // std::cout << "push :"  << nearNode->x_ << ":" << nearNode->y_ << std::endl;
      }

      // 邻点入栈: 上
      if (node->x_ - 1 >= 0 // 边界
          && map[node->x_ - 1][node->y_] == 0 // 没有阻碍物
          && bfsMap_[node->x_ - 1][node->y_]->visitState_ == Node::UnVisit) { // 未访问过
        Node* nearNode = bfsMap_[node->x_ - 1][node->y_];
        nearNode->dis_ = node->dis_ + 1;
        // 是否到达终点
        if (nearNode->x_ == n - 1 && nearNode->y_ == m - 1) {
          return nearNode->dis_;
        }
        nearNode->visitState_ = Node::Visiting;
        visitingList.push_back(nearNode);
        // std::cout << "push :"  << nearNode->x_ << ":" << nearNode->y_ << std::endl;
      }

      // 邻点入栈: 下
      if (node->x_ + 1 <= n - 1  // 边界
          && map[node->x_ + 1][node->y_] == 0 // 没有阻碍物
          && bfsMap_[node->x_ + 1][node->y_]->visitState_ == Node::UnVisit) { // 未访问过
        Node* nearNode = bfsMap_[node->x_ + 1][node->y_];
        nearNode->dis_ = node->dis_ + 1;
        // 是否到达终点
        if (nearNode->x_ == n - 1 && nearNode->y_ == m - 1) {
          return nearNode->dis_;
        }

        nearNode->visitState_ = Node::Visiting;
        visitingList.push_back(nearNode);
        // std::cout << "push :"  << nearNode->x_ << ":" << nearNode->y_ << std::endl;
      }

      // 访问完毕
      node->visitState_ = Node::Visited;
    }
    return -1; // 没找到终点
  }

  struct Node {
    Node(int x, int y) {
      x_ = x;
      y_ = y;
      dis_ = 0;
      visitState_ = UnVisit;
    }

    int x_;
    int y_;
    int dis_;
    enum VisitState {
      UnVisit,
      Visiting,
      Visited,
    };
    VisitState visitState_;
  };
};

int main() {
  // 样例
  {
    Flood obj;
    std::vector<std::vector<int> > map {{0,1,0}, {0,0,0},{0,0,0}};
    std::cout << obj.floodFill(map, 3, 3) << std::endl;
  }

  {
    Flood obj;
    std::vector<std::vector<int> > map {{0,0,0}, {1,0,1},{0,0,0}, {0,1,0}};
    std::cout << obj.floodFill(map, 4, 3) << std::endl;
  }
  return 0;
}
