#include "Utils/BinaryTree.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr)
      return vector<string>();
    if (root->left == nullptr && root->right == nullptr)
      return vector<string>({std::to_string(root->val)});

    string path(std::to_string(root->val));

    searchPath(root->left, path);
    searchPath(root->right, path);

    return res;
  }

  void searchPath(TreeNode *node, string path) {
    if (node == nullptr)
      return;
    path += "->";
    path += std::to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(path);
    }
    searchPath(node->left, path);
    searchPath(node->right, path);
  }

private:
  vector<string> res;
};

void test(vector<int> &input) {
  Solution so;
  BinaryTree bt(input);
  auto res = so.binaryTreePaths(bt);
  for (auto r : res) {
    cout << r << endl;
  }
  cout << "=====" << endl;
}

int main() {
  vector<int> input = {1, 2, 3, 0, 5};
  test(input);
}
