#include "Utils/BinaryTree.h"
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> que;
    que.push(root);
    int layer = 0;
    int max_layer = 0;
    int leap_layer_count = 0;
    while (!que.empty()) {
      layer++;
      size_t size = que.size();
      if (max_layer != 0 && layer == max_layer + 1) {
        leap_layer_count = size;
        break;
      }
      for (int i = 0; i < size; i++) {
        auto *node = que.front();
        if (i == 0) {
          if (node->left == nullptr || node->left->left == nullptr) {
            max_layer = layer;
          }
        }
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
        que.pop();
      }
    }

    return (2 << (max_layer - 1)) - 1 + leap_layer_count;
  }
  int countNodes_1(TreeNode *root) {
    if (root == nullptr)
      return 0;
    countNode(root);
    return count;
  }
  void countNode(TreeNode *node) {
    if (node == nullptr)
      return;
    count++;
    if (node->left)
      countNode(node->left);
    if (node->right)
      countNode(node->right);
  }
  int count = 0;
};

void test(vector<int> &input, int golden) {
  Solution so;
  BinaryTree bt(input);
  auto res = so.countNodes(bt);
  cout << "count: " << res << endl;
  assert(res == golden);
}

int main() {
  vector<int> input1 = {1, 2, 3, 4, 5, 6};
  test(input1, 6);
  vector<int> input2 = {1};
  test(input2, 1);
  return 0;
}
