#include "Utils/BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
  int maxDepth1(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> st;
    int depth = 0;
    st.push(root);
    while (!st.empty()) {
      size_t len = st.size();
      for (unsigned i = 0; i < len; ++i) {
        auto *p = st.front();
        if (p->left) {
          st.push(p->left);
        }
        if (p->right) {
          st.push(p->right);
        }
        st.pop();
      }
      depth++;
    }
    return depth;
  }
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    auto leftDepth = maxDepth(root->left);
    auto rightDepth = maxDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
  }
};

void test() {
  Solution so;
  vector<int> input = {1, 2, 3, 0, 0, 6, 7};
  auto bt = BinaryTree(input);
  auto ret = so.maxDepth(bt);
  cout << ret << endl;
}

int main() {
  test();
  return 0;
}
