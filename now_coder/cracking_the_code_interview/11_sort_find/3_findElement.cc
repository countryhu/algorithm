#include <iostream>
#include <vector>

/**
  题目描述
  有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
  例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],
  现在对于移位后的数组，需要查找某个元素的位置。
  请设计一个复杂度为log级别的算法完成这个任务。
  给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，
  请返回x的位置(位置从零开始)。保证数组中元素互异。

  测试样例：
  [6,1,2,3,4,5],6,6

  返回：
  0

  -------
  题目分析
 **/

class Finder {
 public:
  int findElement(std::vector<int> A, int n, int x) {
    return myFindElement(A, 0, n-1, x);
  }

 private:
  int myFindElement(std::vector<int> A, int left, int right, int x) {
    int mid = (left + right) / 2;
    if (A[mid] == x) {
      return mid;
    }
    if (mid >= right) {
      return -1;
    }

    if (A[mid] < A[right]) { // 右侧升序
      if (A[mid] < x && A[right] >= x) {
        return myFindElement(A, mid + 1, right, x);
      } else {
        return myFindElement(A, left, mid - 1, x);
      }
    } else if (A[left] < A[mid]) { // 左侧升序
      if (A[left] <= x && A[mid] > x) {
        return myFindElement(A, left, mid - 1, x);
      } else {
        return myFindElement(A, mid + 1, right, x);
      }
    } else {
      int leftRet = myFindElement(A, left, mid - 1, x);
      if (leftRet != -1) {
        return leftRet;
      }
      return myFindElement(A, mid + 1, right, x);
    }
  }
};

int main() {
  // 样例
  {
    Finder obj;
    std::vector<int> A = {6,1,2,3,4,5};
    std::cout << obj.findElement(A, 6, 6) << std::endl;
    std::cout << obj.findElement(A, 6, 3) << std::endl;
  }

  {
    Finder obj;
    std::vector<int> A = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,1,2,3,4,5,6,7,8,9};
    std::cout << obj.findElement(A, 80,6) << std::endl;
  }

  return 0;
}
