#include "Utils/BinaryTree.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  // Recursion
  vector<int> inorderTraversal_1(TreeNode *root) {
    vector<int> ret;
    traversal(root, ret);
    return ret;
  }
  void traversal(TreeNode *node, vector<int> &ret) {
    if (node == nullptr)
      return;
    traversal(node->left, ret);
    ret.push_back(node->val);
    traversal(node->right, ret);
  }
  // Iteration
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> st;
    if (root == nullptr)
      return {};
    TreeNode *cur = root;
    while (!st.empty() || cur != nullptr) {
      if (cur != nullptr) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        ret.push_back(cur->val);
        st.pop();
        cur = cur->right;
      }
    }
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> treeNodes = {1, 2, 3, 4, 0, 6, 7, 8};
  auto bt = BinaryTree(treeNodes);
  auto *root = bt.getRoot();

  auto ret = so.inorderTraversal(root);
  cout << ret.size() << endl;
  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test1(); }
