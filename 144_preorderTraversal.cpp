#include "Utils/BinaryTree.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  // Recursion
  vector<int> preorderTraversal_1(TreeNode *root) {
    vector<int> ret;
    traversal(root, ret);
    return ret;
  }
  void traversal(TreeNode *node, vector<int> &ret) {
    if (node == nullptr)
      return;
    ret.push_back(node->val);
    traversal(node->left, ret);
    traversal(node->right, ret);
  }
  // Iteration
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> st;
    if (root == nullptr)
      return {};
    st.push(root);
    while (!st.empty()) {
      auto *p = st.top();
      ret.push_back(p->val);
      st.pop();
      if (p->right != nullptr)
        st.push(p->right);
      if (p->left != nullptr)
        st.push(p->left);
    }
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> treeNodes = {1, 2, 3, 4, 0, 6, 7, 8};
  auto bt = BinaryTree(treeNodes);
  auto *root = bt.getRoot();

  auto ret = so.preorderTraversal(root);
  cout << ret.size() << endl;
  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test1(); }
