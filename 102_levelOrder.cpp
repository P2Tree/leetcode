#include "Utils/BinaryTree.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {{}};
    queue<TreeNode *> que;
    que.push(root);
    que.push(nullptr);
    vector<vector<int>> ret;
    while (!que.empty()) {
      vector<int> layer;
      auto *p = que.front();
      do {
        layer.push_back(p->val);
        if (p->left != nullptr) {
          que.push(p->left);
        }
        if (p->right != nullptr) {
          que.push(p->right);
        }
        que.pop();
        p = que.front();
      } while (p != nullptr);
      que.pop();
      if (!que.empty())
        que.push(nullptr);
      ret.push_back(layer);
    }
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> vec = {1, 2, 3, 4, 0, 6, 7, 8};
  auto bt = BinaryTree(vec);

  auto *root = bt.getRoot();

  auto ret = so.levelOrder(root);
  cout << "level order: " << endl;
  for (auto r : ret) {
    for (auto c : r) {
      cout << c << ", ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() { test1(); }
