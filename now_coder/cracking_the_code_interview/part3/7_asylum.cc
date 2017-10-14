#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

/**
  题目描述
  有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，
  第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。
  给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。若第一个元素为1，则代表有动物进入收容所，
  第二个元素为动物的编号，正数代表狗，负数代表猫；若第一个元素为2，则代表有人收养动物，第二个元素若为0，则采取第一种收养方式，
  若为1，则指定收养狗，若为-1则指定收养猫。请按顺序返回收养的序列。若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。
  测试样例：
  [[1,1],[1,-1],[2,0],[2,-1]]
  返回：[1,-1]
  -----

  题目分析
  1. 领养所有的时候别忘了,cat队列也pop
  2. 如何判断有其他动物进收养所？
 **/


class CatDogAsylum {
 public:
  CatDogAsylum() : index_(0) {
  }

  struct Animal {
    int index;
    int id;
    Animal(int indexI, int idI) {
      index = indexI;
      id = idI;
    }
  };

  vector<int> asylum(vector<vector<int> > ope) {
    queue<Animal> catQueue;
    queue<Animal> dogQueue;
    vector<int> retVec;
    for (auto& op : ope) {
      // 进收养所
      if (op[0] == 1) {
        if (op[1] > 0) { // dog in
          dogQueue.push(Animal(++index_, op[1]));
        } else if (op[1] < 0) { // cat in
          catQueue.push(Animal(++index_, op[1]));
        }
      }

      // 出收养所
      if (op[0] == 2) {
        if (op[1] == 0) { // 收养所有最先
          if (dogQueue.empty() && !catQueue.empty()) {
            retVec.push_back(catQueue.front().id);
            catQueue.pop();
          } else if (!dogQueue.empty() && catQueue.empty()) {
            retVec.push_back(dogQueue.front().id);
            dogQueue.pop();
          } else if (!dogQueue.empty() && !catQueue.empty()) {
            if (dogQueue.front().index < catQueue.front().index) {
              retVec.push_back(dogQueue.front().id);
              dogQueue.pop();
            } else {
              retVec.push_back(catQueue.front().id);
              catQueue.pop();
            }
          }
        } else if (op[1] == 1) { // dog out
          if (!dogQueue.empty()) {
            retVec.push_back(dogQueue.front().id);
            dogQueue.pop();
          }
        } else if (op[1] == -1) { // cat out
          if (!catQueue.empty()) {
            retVec.push_back(catQueue.front().id);
            catQueue.pop();
          }
        }
      }
    }
    return retVec;
  }

 private:
  int index_;
};
