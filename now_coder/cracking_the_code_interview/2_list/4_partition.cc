#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  题目描述
  编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
  给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
  注意：分割以后保持原来的数据顺序不变。

  -----
  题目分析
  1. 维护两个变量lessEndNode, largeEndNode
  2. 注意任何点是否有可能是NULL的特殊情况
  3. 遍历整个链表，如果节点值小于x，则从源节点删除，插入到lessEndNode后面。
  如果大于等于x则不动
 **/

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
 public:
  ListNode* partition(ListNode* pHead, int x) {
    // 1. 判断非法输入
    if (pHead == NULL) {
      return NULL;
    }
    // 2. 只有一个节点
    if (pHead->next == NULL) {
      return pHead;
    }

    // 将小于x的节点放在leftList链表上边
    // 将大于等于x的节点放在right链表上边
    ListNode* p = pHead;
    ListNode* leftBeginList = NULL;
    ListNode* leftEndList = NULL;
    ListNode* rightBeginList = NULL;
    ListNode* rightEndList = NULL;
    while (p != NULL) {
      ListNode* next = p->next;
      p->next = NULL;
      if (p->val < x) {
        if (leftBeginList == NULL) {
          leftBeginList = p;
          leftEndList = p;
        } else {
          leftEndList->next = p;
          leftEndList = p;
        }
      } else {
        if (rightBeginList == NULL) {
          rightBeginList = p;
          rightEndList = p;
        } else {
          rightEndList->next = p;
          rightEndList = p;
        }
      }
      p = next;
    }

    // 合并左右分支
    if (leftBeginList == NULL) {
      return rightBeginList;
    }

    // 左右合并
    leftEndList->next = rightBeginList;

    return leftBeginList;
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

  for (int i = 1; i < 6; ++i) {
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

  Partition obj;
  ListNode* ret = obj.partition(listBegin, 6);
  while (ret != NULL) {
    cout << ret->val << " ";
    ret = ret->next;
  }
}

