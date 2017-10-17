#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

/**
  题目描述
  对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
  给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，
  请返回一个链表ListNode，代表该深度上所有结点的值，
  请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
  -----

  题目分析
  1. 广度优先搜索
  2. 从左往右
 **/

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
};

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
 public:
  ListNode* getTreeLevel(TreeNode* root, int dep) {
    // 存储每一层节点
    vector<queue<TreeNode*> > levels;
    levels.reserve(dep);

    for (int i = 0; i < dep; ++i) {
      levels.push_back(std::queue<TreeNode*>());
    }
    levels[0].push(root);

    // 存储第[2-dep]层节点
    for (int i = 1; i < dep; i++) {
      // 从i-1的队列拿出来，将其从左到右子节点，放到i的队列中
      while (!levels[i-1].empty()) {
        TreeNode* visitingNode = levels[i-1].front();

        if (visitingNode->left != NULL) {
          levels[i].push(visitingNode->left);
        }
        if (visitingNode->right != NULL) {
          levels[i].push(visitingNode->right);
        }
        levels[i-1].pop();
      }
    }

    // dep层存在levels[dep-1]的队列中
    if (levels[dep-1].empty()) {
      return NULL;
    }

    ListNode* beginLevelNodes = new ListNode(levels[dep-1].front()->val);
    levels[dep-1].pop();
    ListNode* endLevelNodes = beginLevelNodes;
    while (!levels[dep-1].empty()) {
      endLevelNodes->next = new ListNode(levels[dep-1].front()->val);
      levels[dep-1].pop();
      endLevelNodes = endLevelNodes->next;
    }
    return beginLevelNodes;
  }
};

void Print(ListNode* levelNodes) {
  cout << "ret:";
  while (levelNodes != NULL) {
    cout << levelNodes->val << " ";
    levelNodes = levelNodes->next;
  }
  cout << endl;
}

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* node11 = new TreeNode(11);
  TreeNode* node12 = new TreeNode(12);
  TreeNode* node21 = new TreeNode(21);
  TreeNode* node22 = new TreeNode(22);
  TreeNode* node23 = new TreeNode(23);

  TreeLevel obj;
  ListNode* levelNodes = obj.getTreeLevel(root, 1);
  Print(levelNodes);

  root->left = node11;
  levelNodes = obj.getTreeLevel(root, 2);
  Print(levelNodes);

  root->right = node12;
  levelNodes = obj.getTreeLevel(root, 2);
  Print(levelNodes);

  root->left->left = node21;
  root->left->right = node22;
  root->right->right = node23;
  levelNodes = obj.getTreeLevel(root, 1);
  Print(levelNodes);

  levelNodes = obj.getTreeLevel(root, 3);
  Print(levelNodes);

  return 0;
}
