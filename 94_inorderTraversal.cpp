#include "Utils/BinaryTree.h"
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
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
