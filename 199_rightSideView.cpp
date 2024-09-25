#include "Utils/BinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> que;
    vector<int> ret;

    if (root == nullptr)
      return {};

    que.push(root);
    while (!que.empty()) {
      size_t size = que.size();
      for (unsigned i = 0; i < size; i++) {
        auto *p = que.front();
        if (i == size - 1) {
          ret.push_back(p->val);
        }
        if (p->left) {
          que.push(p->left);
        }
        if (p->right) {
          que.push(p->right);
        }
        que.pop();
      }
    }
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> input = {1, 2, 3, 4, 0, 6, 7, 8};
  auto bt = BinaryTree(input);
  auto *root = bt.getRoot();
  auto ret = so.rightSideView(root);

  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test1(); }
