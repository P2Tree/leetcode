#include "Utils/BinaryTree.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  // Recursion
  vector<int> postorderTraversal_1(TreeNode *root) {
    vector<int> ret;
    traversal(root, ret);
    return ret;
  }
  void traversal(TreeNode *node, vector<int> &ret) {
    if (node == nullptr)
      return;
    traversal(node->left, ret);
    traversal(node->right, ret);
    ret.push_back(node->val);
  }
  // Iteration
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> ret;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      auto *cur = st.top();
      ret.push_back(cur->val);
      st.pop();
      if (cur->left)
        st.push(cur->left);
      if (cur->right)
        st.push(cur->right);
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> treeNodes = {1, 2, 3, 4, 0, 6, 7, 8};
  auto bt = BinaryTree(treeNodes);
  auto *root = bt.getRoot();

  auto ret = so.postorderTraversal(root);
  cout << ret.size() << endl;
  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test1(); }
