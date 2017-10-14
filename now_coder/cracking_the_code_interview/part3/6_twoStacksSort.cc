#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，
  但不得将元素复制到别的数据结构中。
  给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，
  意味着排序过程中你只能访问到第一个元素。
  测试样例：
  [1,2,3,4,5]
  返回：[5,4,3,2,1]
  -----

  题目分析
  1.倒来倒去
 **/

class TwoStacks {
 public:
  vector<int> twoStacksSort(vector<int> numbers) {
    vector<int> sortedVec;
    while (!numbers.empty()) {
      int val = numbers.back();
      numbers.pop_back();

      PrepareSortedVec(sortedVec, val, numbers);

      sortedVec.push_back(val);
    }
    return sortedVec;
  }

 private:
    void PrepareSortedVec(vector<int>& sortedVec, int val, vector<int>& numbers) {
      while (!sortedVec.empty()) {
        // 大于等于val的元素转移回numbers
        int sortedVal = sortedVec.back();
        if (sortedVal >= val) {
          return;
        }
        numbers.push_back(sortedVal);
        sortedVec.pop_back();
      }
    }
};
