#pragma once

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

class BinaryTree {
public:
  // input data vector is layer ordered traversal
  BinaryTree(std::vector<int> &values) : root(nullptr) {
    if (values.size() == 0)
      return;
    root = new TreeNode();
    TreeNode *p = root;
    std::queue<TreeNode *> q;
    q.push(root);

    for (auto i = 0; i < values.size(); i++) {
      auto v = values[i];
      if (v == 0) {
        q.pop();
        continue;
      }
      auto *p = q.front();
      p->val = v;
      unsigned leftIndex = 2 * (i + 1) - 1;
      if (leftIndex < values.size() && values[leftIndex] != 0)
        p->left = new TreeNode();
      else
        p->left = nullptr;
      unsigned rightIndex = 2 * (i + 1);
      if (rightIndex < values.size() && values[rightIndex] != 0)
        p->right = new TreeNode();
      else
        p->right = nullptr;
      q.push(p->left);
      q.push(p->right);
      q.pop();
    }
  }

  ~BinaryTree() {
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto *p = q.front();
      if (p != nullptr) {
        q.push(p->left);
        q.push(p->right);
        delete p;
      }
      q.pop();
    }
  }

  // output order is layer traversal order
  void print() const {
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto *p = q.front();
      if (p != nullptr) {
        std::cout << "node val: " << p->val;
        if (p->left != nullptr) {
          std::cout << ", left child-node val: " << p->left->val;
          q.push(p->left);
        } else {
          std::cout << ", left child-node empty";
        }
        if (p->right != nullptr) {
          std::cout << ", right child-node val: " << p->right->val;
          q.push(p->right);
        } else {
          std::cout << ", right child-node empty";
        }
      }
      q.pop();
      std::cout << std::endl;
    }
  }

  TreeNode *getRoot() const { return root; }

private:
  TreeNode *root;
};
