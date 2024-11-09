#include "Utils/BinaryTree.h"
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> que;
    que.push(root);
    int layer = 0;
    while (!que.empty()) {
      size_t size = que.size();
      layer++;
      for (int i = 0; i < size; i++) {
        auto *node = que.front();
        if (node->left == nullptr && node->right == nullptr)
          return layer;
        if (node->left != nullptr) {
          que.push(node->left);
        }
        if (node->right != nullptr) {
          que.push(node->right);
        }
        que.pop();
      }
    }
    return layer;
  }
};

void test(vector<int> &input, int golden) {
  Solution so;
  BinaryTree bt(input);
  auto res = so.minDepth(bt);
  assert(res == golden);
  cout << "min depth is: " << res << endl;
}

int main() {
  vector<int> input1 = {3, 9, 20, 0, 0, 15, 7};
  test(input1, 2);

  return 0;
}
