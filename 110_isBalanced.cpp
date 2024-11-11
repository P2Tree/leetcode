#include "Utils/BinaryTree.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr)
      return true;
    check(root);
    return IsBalanced;
  }

  int check(TreeNode *node) {
    if (node == nullptr)
      return 0;
    auto left_depth = check(node->left);
    auto right_depth = check(node->right);
    if (std::abs(left_depth - right_depth) > 1) {
      IsBalanced = false;
    }
    return std::max(left_depth, right_depth) + 1;
  }
  bool IsBalanced = true;
};

void test(vector<int> &input, bool golden) {
  Solution so;
  BinaryTree bt(input);
  auto res = so.isBalanced(bt);
  cout << (res ? "Yes" : "No") << endl;
  assert(res == golden);
}

int main() {
  vector<int> input = {3, 9, 20, 0, 0, 15, 7};
  test(input, true);
  vector<int> input2 = {1, 2, 2, 3, 3, 0, 0, 4, 4};
  test(input2, false);
}
