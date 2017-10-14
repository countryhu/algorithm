#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "util/to_string.h"

using namespace std;

/**
  题目描述
  请编写一个函数，检查链表是否为回文。
  给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
  测试样例：
  {1,2,3,2,1}
  返回：true
  {1,2,3,2,3}
  返回：false
  -----

  题目分析
  1. 此题应该有递归法，但想起来太麻烦还容易出错。从工程角度讲，用堆栈缓存，更清晰
  2. 注意奇数个元素的处理办法
 **/

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
 public:
  bool isPalindrome(ListNode* pHead) {
    if (pHead == NULL)
      return true;

    if (pHead->next == NULL)
      return true;

    // 以下至少有两个节点
    std::vector<int> firstHalfNodes;
    ListNode* slowNode = pHead;
    ListNode* fastNode = pHead->next;
    while (true) {
      // 前半部分入栈
      firstHalfNodes.push_back(slowNode->val);

      if (fastNode->next != NULL) {
        // 慢的向前走一步
        slowNode = slowNode->next;
      }

      if (fastNode->next != NULL && fastNode->next->next != NULL) {
        // 快的向前走两步
        fastNode = fastNode->next->next;
      } else {
        break;
      }
    }

    // slowNode指向开始对比的节点
    slowNode = slowNode->next;
    // 逐个跟栈上对比
    while (!firstHalfNodes.empty() || slowNode != NULL) {
      int val = firstHalfNodes.back();
      if (slowNode->val != val) {
        return false;
      }
      firstHalfNodes.pop_back();
      slowNode = slowNode->next;
    }

    // 当两者全为空，则为回文
    return firstHalfNodes.empty() && slowNode == NULL;
  }
};

void TestCase(std::vector<int> intVec, bool expectRet) {
  // 构造ListNode
  ListNode* listBegin = NULL;
  ListNode* listEnd = NULL;
  for (size_t i = 0; i < intVec.size(); ++i) {
    ListNode* p = new ListNode(intVec[i]);
    if (i == 0) {
      listBegin = p;
      listEnd = p;
      continue;
    }
    listEnd->next = p;
    listEnd = listEnd->next;
  }

  // 调用测试函数
  Palindrome obj;
  bool ret = obj.isPalindrome(listBegin);
  if (ret == expectRet) {
    cout << util::ToString(intVec) << " passed." << endl;
  } else {
    cout << util::ToString(intVec) << " failed." << endl;
  }
}

int main() {
  TestCase({1,2,3,2,1}, true);
  TestCase({1,2,3,2,3}, false);
  TestCase({}, true);
  TestCase({1}, true);
  TestCase({1,2,2,1}, true);
  TestCase({1,2,1}, true);
  TestCase({1,1}, true);
  TestCase({1,2,3,3,2,1}, true);
  TestCase({1,2,4,3,2,1}, false);
  TestCase({1,2,4,4,2}, false);
}
