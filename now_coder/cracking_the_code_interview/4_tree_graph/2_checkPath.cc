#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

/**
  题目描述
  对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
  给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b(请不要在意数据类型，图是有向图),
  请返回一个bool，代表两点之间是否存在一条路径(a到b或b到a)。
  -----

  题目分析
  1. 广度优先搜索大概率适合查找最短路径。
  2. 深度优先搜索适合刨根问底。
  3. 注意从a到b 或 从b到a
 **/

struct UndirectedGraphNode {
  int label;
  vector<struct UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {}
};

class Path {
 public:
  bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
    bool a2bOk = isConnect(a, b);
    visitNodes.clear();
    bool b2aOk = isConnect(b, a);
    return a2bOk || b2aOk;
  }

 private:
  bool isConnect(UndirectedGraphNode* a, UndirectedGraphNode* b) {
    if (a == NULL || b == NULL) {
      return false;
    }

    if (a->label == b->label) {
      return true;
    }

    queue<UndirectedGraphNode*> queue;
    queue.push(a); // 第一个入队
    visitNodes[a->label] = true;

    while (!queue.empty()) {
      UndirectedGraphNode* node = queue.front();
      queue.pop();

      for (auto& neighborNode : node->neighbors) {
        if (!visitNodes[neighborNode->label]) {
          if (neighborNode->label == b->label) {
            return true;
          }
          visitNodes[neighborNode->label] = true;
          queue.push(neighborNode);
        }
      }
    }
    return false;
  }

 private:
  map<int, bool> visitNodes;
};

