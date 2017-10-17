#include <iostream>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

/**
  题目描述
  请实现一个函数，检查一棵二叉树是否为二叉查找树。
  给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
  -----

  题目分析
 **/

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
};

class Checker {
 public:
  bool checkBST(TreeNode* root) {
    if (root == NULL) {
      return true;
    }

    if (root->left != NULL && maxValue(root->left) > root->val) {
      return false;
    }

    if (root->right != NULL && minValue(root->right) < root->val) {
      return false;
    }

    return checkBST(root->left) && checkBST(root->right);
  }

 private:
  int minValue(TreeNode* node) {
    if (node == NULL) {
      return std::numeric_limits<int>::max();
    }
    int minValue = node->val;
    while (node != NULL) {
      if (node->left != NULL && node->left->val < minValue) {
        minValue = node->left->val;
      }
      node = node->left;
    }
    return minValue;
  }

  int maxValue(TreeNode* node) {
    if (node == NULL) {
      return std::numeric_limits<int>::min();
    }
    int maxValue = node->val;
    while (node != NULL) {
      if (node->right != NULL && node->right->val > maxValue) {
        maxValue = node->right->val;
      }
      node = node->right;
    }
    return maxValue;
  }
};

int main() {
  TreeNode* root = new TreeNode(10);
  TreeNode* node11 = new TreeNode(5);
  TreeNode* node12 = new TreeNode(11);
  TreeNode* node13 = new TreeNode(10);

  TreeNode* node21 = new TreeNode(2);
  TreeNode* node22 = new TreeNode(6);
  TreeNode* node23 = new TreeNode(20);

  Checker obj;
  cout << obj.checkBST(root) << endl;

  root->left = node11;
  root->right = node12;
  cout << obj.checkBST(root) << endl;

  root->right = node13;
  cout << obj.checkBST(root) << endl;

  root->left->left = node21;
  root->left->right = node22;
  root->left->right = node23;
  cout << obj.checkBST(root) << endl;

  return 0;
}
