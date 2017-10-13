#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  输入一个链表，输出该链表中倒数第k个结点。

  -----
  题目分析

  方案一: 1. 链表问题, 快慢指针
 **/

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {
  }
};

class Solution {
 public:
  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    // 第一个元素遍历
    ListNode* p1 = pListHead;
    for (unsigned int i = 0; i < k; ++i) {
      // 元素总数小于K
      if (p1 == NULL) {
        return NULL;
      }
      p1 = p1->next;
    }

    ListNode* p2 = pListHead;
    while (p1 != NULL) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p2;
  }
};

