#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

/**
  题目描述
  实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
  给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
  -----

  题目分析
  1. 先采用递归调用法。效率问题可能通不过。需要遍历每个节点，时间复杂度为:O(nklogn)
 **/
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
};

class Balance {
 public:
  bool isBalance(TreeNode* root) {
    if (checkHeight(root) == -1) {
      return false;
    }
    return true;
  }

 private:
  int checkHeight(TreeNode* node) {
    if (node == NULL) {
      return 0;
    }

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) {
      return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return max(leftHeight, rightHeight) + 1;
  }
};
