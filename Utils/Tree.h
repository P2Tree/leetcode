#pragma once

#include <iostream>
#include <queue>
#include <vector>

class TreeNode {
public:
  TreeNode() {}

  TreeNode(int _val) { val = _val; }

  TreeNode(int _val, std::vector<TreeNode *> _children) {
    val = _val;
    children = _children;
  }

public:
  int val;
  std::vector<TreeNode *> children;
};

class Tree {
public:
  Tree(std::vector<int> input) : root(nullptr) {
    root = new TreeNode(input[0]);
    std::queue<TreeNode *> que;
    que.push(root);
    TreeNode *p = root;
    for (unsigned i = 1; i < input.size(); i++) {
      if (input[i] == 0) {
        p = que.front();
        que.pop();
      } else {
        auto *n = new TreeNode(input[i]);
        p->children.push_back(n);
        que.push(n);
      }
    }
  }

  void layerTraversal() const {
    auto que = std::queue<TreeNode *>();
    que.push(root);
    while (!que.empty()) {
      auto *p = que.front();
      std::cout << "node val: " << p->val << ", children: [";
      for (auto c : p->children) {
        std::cout << c->val << ", ";
        que.push(c);
      }
      std::cout << "]" << std::endl;
      que.pop();
    }
  }

  TreeNode *getRoot() const { return root; }

  operator TreeNode *() const { return root; }

private:
  TreeNode *root;
};
