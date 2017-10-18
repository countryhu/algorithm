#include <iostream>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <set>
#include <queue>
#include "util/to_string.h"

using namespace std;

/**
  题目描述
  输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
  路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
  -----

  题目分析
  1. 广度优先搜索不可以，因为中间会改路径
  2. 深度优先搜索,中间不改路径
  错题本:
  1. 从根节点， 一直到叶节点
 **/

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
};

class Solution {
 public:
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    m_findedPathes.clear();
    vector<int> visitedPath;
    dfs(root, visitedPath, expectNumber);
    return m_findedPathes;
  }

 private:
  void dfs(TreeNode* node, vector<int>& visitedPath, int expectNumber ) {
    if (node == NULL) {
      return;
    }

    // 访问当前节点
    visitedPath.push_back(node->val);
    if (node->left == NULL && node->right == NULL && CurTotalPathNumber(visitedPath) == expectNumber) {
      m_findedPathes.push_back(visitedPath);
    }

    if (node->left != NULL) {
      dfs(node->left, visitedPath, expectNumber);
      visitedPath.pop_back();
    }

    if (node->right != NULL) {
      dfs(node->right, visitedPath, expectNumber);
      visitedPath.pop_back();
    }
  }

  int CurTotalPathNumber(const vector<int>& visitedPath) {
    int curTotalPathNumber = 0;
    for (auto& val : visitedPath)  {
      curTotalPathNumber += val;
    }
    return curTotalPathNumber;
  }

 private:
  vector<vector<int> > m_findedPathes;
};

int main() {
  TreeNode* root = new TreeNode(10);
  TreeNode* node11 = new TreeNode(5);
  TreeNode* node12 = new TreeNode(11);
  TreeNode* node21 = new TreeNode(-5);
  TreeNode* node22 = new TreeNode(6);
  TreeNode* node23 = new TreeNode(20);
  TreeNode* node24 = new TreeNode(-11);

  Solution obj;
  cout << util::ToString(obj.FindPath(root, 10)) << endl;
  cout << util::ToString(obj.FindPath(root, 9)) << endl;

  root->left = node11;
  root->right = node12;
  cout << util::ToString(obj.FindPath(root, 15)) << endl;
  cout << util::ToString(obj.FindPath(root, 5)) << endl;


  root->left->left = node21;
  root->left->right = node22;
  root->right->left = node23;
  root->right->right = node24;
  cout << util::ToString(obj.FindPath(root, 15)) << endl;
  cout << util::ToString(obj.FindPath(root, 10)) << endl;
  cout << util::ToString(obj.FindPath(root, 21)) << endl;
  return 0;
}
