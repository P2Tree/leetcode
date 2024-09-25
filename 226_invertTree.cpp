#include "Utils/BinaryTree.h"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *invertTree1(TreeNode *root) {
    invert1(root);
    return root;
  }
  void invert1(TreeNode *node) {
    if (node == nullptr)
      return;
    if (node->left && node->right) {
      std::swap(node->left, node->right);
    } else if (node->left == nullptr && node->right) {
      node->left = node->right;
      node->right = nullptr;
    } else if (node->right == nullptr && node->left) {
      node->right = node->left;
      node->left = nullptr;
    }
    invert(node->left);
    invert(node->right);
    return;
  }
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      size_t size = que.size();
      for (unsigned i = 0; i < size; i++) {
        auto *p = que.front();
        invert(p);
        if (p->left) {
          que.push(p->left);
        }
        if (p->right) {
          que.push(p->right);
        }
        que.pop();
      }
    }
    return root;
  }
  void invert(TreeNode *node) {
    if (node == nullptr)
      return;
    std::swap(node->left, node->right);
  }
};

void test1() {
  //           1
  //        2     3
  //      4  5  6   7
  //           1
  //        3     2
  //      7  6  5   4
  Solution so;
  vector<int> input = {1, 2, 3, 4, 5, 6, 7};
  auto bt = BinaryTree(input);
  auto *root = bt.getRoot();
  auto ret = so.invertTree(root);

  auto newBt = BinaryTree(ret);
  newBt.layerOrderTraverse();
}
void test2() {
  //           1
  //        n     2
  //           1
  //        2     n
  Solution so;
  vector<int> input = {1, 0, 2};
  auto bt = BinaryTree(input);
  auto *root = bt.getRoot();
  auto ret = so.invertTree(root);

  auto newBt = BinaryTree(ret);
  newBt.layerOrderTraverse();
}

int main() { test1(); }
