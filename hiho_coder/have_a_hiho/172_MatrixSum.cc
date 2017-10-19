#include <iostream>
#include <string.h>
#include <bitset>
#include <stdio.h>

using namespace std;

/**
  题目1 : Matrix Sum
  时间限制:10000ms
  单点时限:1000ms
  内存限制:256MB
  描述
  You are given an N × N matrix. At the beginning every element is 0. Write a program supporting 2 operations:

  1. Add x y value: Add value to the element Axy. (Subscripts starts from 0

  2. Sum x1 y1 x2 y2: Return the sum of every element Axy for x1 ≤ x ≤ x2, y1 ≤ y ≤ y2.

  输入
  The first line contains 2 integers N and M, the size of the matrix and the number of operations.

  Each of the following M line contains an operation.

  1 ≤ N ≤ 1000, 1 ≤ M ≤ 100000

  For each Add operation: 0 ≤ x < N, 0 ≤ y < N, -1000000 ≤ value ≤ 1000000

  For each Sum operation: 0 ≤ x1 ≤ x2 < N, 0 ≤ y1 ≤ y2 < N

  输出
  For each Sum operation output a non-negative number denoting the sum modulo 109+7.

  样例输入
  5 8
  Add 0 0 1
  Sum 0 0 1 1
  Add 1 1 1
  Sum 0 0 1 1
  Add 2 2 1
  Add 3 3 1
  Add 4 4 -1
  Sum 0 0 4 4
  样例输出
  1
  2
  3
  -----

  题目分析
 **/


int main() {
  cout << sizeof(int) << endl;
  Finder obj;
  int ret = obj.exchangeOddEven(711908);
  cout << bitset<32>(711908) << endl;
  cout << bitset<32>(ret) << endl;
  cout << bitset<32>(388312) << endl;
  return 0;
}
