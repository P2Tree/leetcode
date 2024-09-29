#pragma once

#include <iostream>
#include <iterator>
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
  class Iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = TreeNode *;
    using pointer = TreeNode **;
    using reference = const TreeNode *;
    using difference_type = std::ptrdiff_t;

  public:
    Iterator(pointer p) : ptr(p) {}
    Iterator(const Iterator &iter) : ptr(iter.ptr) {}
    bool operator==(const Iterator &iter) { return iter.ptr == ptr; }
    bool operator!=(const Iterator &iter) { return !operator==(iter); }
    Iterator &operator++() {
      ptr++;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tempIter(ptr);
      ptr++;
      return tempIter;
    }
    Iterator &operator--() {
      ptr--;
      return *this;
    }
    Iterator operator--(int) {
      Iterator tempIter(ptr);
      ptr--;
      return tempIter;
    }
    value_type &operator*() { return *ptr; }

  private:
    pointer ptr;
  };
  Iterator begin() { return Iterator(&children[0]); }
  Iterator end() { return Iterator(&children[0] + children.size()); }

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
