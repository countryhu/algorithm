#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
  给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
  测试样例：
  {1,2,3},{3,2,1}
  返回：{4,4,4}

  -----
  题目分析

 **/

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
 public:
  ListNode* plusAB(ListNode* a, ListNode* b) {
    int flag = 0;
    ListNode* retListBegin = NULL;
    ListNode* retListEnd = NULL;
    while (a != NULL || b != NULL || flag != 0) {
      // 确定新一位的ab值j:wa
      int valA = 0;
      if (a != NULL) {
        valA = a->val;
        a = a->next;
      }
      int valB = 0;
      if (b != NULL) {
        valB = b->val;
        b = b->next;
      }

      // 构建新的节点
      int newVal = (valA + valB + flag)%10;
      flag = (valA + valB + flag)/10;
      ListNode* newNode = new ListNode(newVal);

      // 追加到retList上
      if (retListBegin == NULL) {
        retListBegin = newNode;
        retListEnd = retListBegin;
      } else {
        retListEnd->next = newNode;
        retListEnd = retListEnd->next;
      }
    }
    return retListBegin;
  }
};

int main() {
  ListNode* listBegin = new ListNode(6);
  ListNode* listEnd = listBegin;
  for (int i = 7; i < 10; ++i) {
    ListNode* p = new ListNode(i);
    listEnd->next = p;
    listEnd = p;
  }

  ListNode* p = listBegin;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;


  ListNode* bListBegin = new ListNode(6);
  ListNode* bListEnd = bListBegin;
  for (int i = 1; i < 6; ++i) {
    ListNode* p = new ListNode(i);
    bListEnd->next = p;
    bListEnd = p;
  }
  p = bListBegin;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  Plus obj;
  ListNode* ret = obj.plusAB(listBegin, bListBegin);
  while (ret != NULL) {
    cout << ret->val << " ";
    ret = ret->next;
  }
}
