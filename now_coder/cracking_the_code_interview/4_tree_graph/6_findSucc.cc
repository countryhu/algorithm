#include <iostream>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

/**
  题目描述
  请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
  给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
  保证结点的值大于等于零, 小于等于100000且没有重复值，若不存在后继返回-1。
  -----

  题目分析
  1.
 **/

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
};

class Successor {
 public:
  int findSucc(TreeNode* root, int p) {
    bool nextFlag = false;
    return inOrderTraversal(root, p, nextFlag);
  }


 private:
  int inOrderTraversal(TreeNode* node, int p, bool& nextFlag) {
    if (node == NULL) {
      return -1;
    }

    // left
    int nextValue = inOrderTraversal(node->left, p, nextFlag);
    if (nextValue != -1) {
      return nextValue;
    }

    // node
    if (nextFlag == true) {
      cout << " return "  << node->val;
      return node->val;
    }
    if (node->val == p) {
      nextFlag = true;
    }

    // right
    nextValue = inOrderTraversal(node->right, p, nextFlag);
    if (nextValue != -1) {
      return nextValue;
    }
    return -1;
  }
};

int main() {
  TreeNode* root = new TreeNode(10);
  TreeNode* node11 = new TreeNode(5);
  TreeNode* node12 = new TreeNode(11);

  TreeNode* node21 = new TreeNode(2);
  TreeNode* node22 = new TreeNode(6);
  TreeNode* node23 = new TreeNode(20);

  Successor obj;
  cout << obj.findSucc(root, 10) << endl;

  root->left = node11;
  root->right = node12;
  cout << obj.findSucc(root, 5) << endl;


  root->left->left = node21;
  root->left->right = node22;
  root->right->right = node23;
  cout << obj.findSucc(root, 10) << endl;
  cout << obj.findSucc(root, 11) << endl;
  return 0;
}
