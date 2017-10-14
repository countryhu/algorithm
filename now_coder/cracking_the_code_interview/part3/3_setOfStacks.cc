#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。
  该数据结构应支持与普通栈相同的push和pop操作。
  给定一个操作序列int[][2] ope(C++为vector&ltvector&ltint>>)，每个操作的第一个数代表操作类型，
  若为1，则为push操作，后一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
  请返回一个int[][](C++为vector&ltvector&ltint>>)，为完成所有操作后的SetOfStacks，顺序应为从下到上，
  默认初始的SetOfStacks为空。保证数据合法。
  -----

  题目分析
  1.注意最顶上的栈空或者满的情况
 **/

class Stacks {
 public:
  explicit Stacks(size_t size) : stackSize_(size) {
  }

  void Push(int val) {
    if (stacks_.empty() || stacks_.back().size() >= stackSize_) {
      stacks_.push_back(std::vector<int>());
    }
    stacks_.back().push_back(val);
  }

  void Pop() {
    stacks_.back().pop_back();
    if (stacks_.back().empty()) {
      stacks_.pop_back();
    }
  }

  std::vector<std::vector<int> > GetStacks() {
    return stacks_;
  }
 private:
  size_t stackSize_;

  std::vector<std::vector<int> > stacks_;
};

class SetOfStacks {
 public:
  vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
    Stacks stacks(size);
    for (auto& oneOpe : ope) {
      if (oneOpe[0] == 1) {
        stacks.Push(oneOpe[1]);
      } else if (oneOpe[0] == 2) {
        stacks.Pop();
      }
    }
    return stacks.GetStacks();
  }
};
