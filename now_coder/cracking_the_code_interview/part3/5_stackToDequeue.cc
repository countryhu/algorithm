#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>

using namespace std;

/**
  题目描述
  用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
  -----

  题目分析
  1. push -> stack1
  2. pop的时候，如果stack2全部为空，需要使stack1一次性全部从stack1转移到stack2
 **/

class Solution
{
 public:
  void push(int node) {
    stack1.push(node);
  }

  int pop() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    int val = stack2.top();
    stack2.pop();
    return val;
  }

 private:
  stack<int> stack1;
  stack<int> stack2;
};
