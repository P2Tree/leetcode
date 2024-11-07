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
        q.push(nullptr);
        q.push(nullptr);
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
  BinaryTree(TreeNode *r) : root(nullptr) {
    if (r == nullptr)
      return;
    root = new TreeNode(r->val);
    std::queue<TreeNode *> in, out;
    in.push(r);
    out.push(root);
    while (!in.empty()) {
      auto *i = in.front();
      auto *o = out.front();
      if (i->left) {
        o->left = new TreeNode(i->left->val);
        in.push(i->left);
        out.push(o->left);
      }
      if (i->right) {
        o->right = new TreeNode(i->right->val);
        in.push(i->right);
        out.push(o->right);
      }
      in.pop();
      out.pop();
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
  std::vector<int> layerOrderTraverse() const {
    std::queue<TreeNode *> q;
    q.push(root);
    std::vector<int> order;
    while (!q.empty()) {
      auto *p = q.front();
      if (p != nullptr) {
        std::cout << "node val: " << p->val;
        order.push_back(p->val);
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
    return order;
  }

  std::vector<int> preOrderTraverse() {
    std::vector<int> order;
    preOrder(root, order);
    return order;
  }
  std::vector<int> inOrderTraverse() {
    std::vector<int> order;
    inOrder(root, order);
    return order;
  }
  std::vector<int> postOrderTraverse() {
    std::vector<int> order;
    postOrder(root, order);
    return order;
  }

  TreeNode *getRoot() const { return root; }

  operator TreeNode *() const { return root; }

private:
  void preOrder(TreeNode *node, std::vector<int> &order) {
    if (node == nullptr)
      return;
    std::cout << "node val: " << node->val;
    order.push_back(node->val);
    if (node->left != nullptr) {
      std::cout << ", left child-node val: " << node->left->val;
    } else {
      std::cout << ", left child-node empty";
    }
    if (node->right != nullptr) {
      std::cout << ", right child-node val: " << node->right->val;
    } else {
      std::cout << ", right child-node empty";
    }
    std::cout << std::endl;

    preOrder(node->left, order);
    preOrder(node->right, order);
  }
  void inOrder(TreeNode *node, std::vector<int> &order) {
    if (node == nullptr)
      return;
    inOrder(node->left, order);

    std::cout << "node val: " << node->val;
    order.push_back(node->val);
    if (node->left != nullptr) {
      std::cout << ", left child-node val: " << node->left->val;
    } else {
      std::cout << ", left child-node empty";
    }
    if (node->right != nullptr) {
      std::cout << ", right child-node val: " << node->right->val;
    } else {
      std::cout << ", right child-node empty";
    }
    std::cout << std::endl;

    inOrder(node->right, order);
  }
  void postOrder(TreeNode *node, std::vector<int> &order) {
    if (node == nullptr)
      return;
    postOrder(node->left, order);
    postOrder(node->right, order);

    std::cout << "node val: " << node->val;
    order.push_back(node->val);
    if (node->left != nullptr) {
      std::cout << ", left child-node val: " << node->left->val;
    } else {
      std::cout << ", left child-node empty";
    }
    if (node->right != nullptr) {
      std::cout << ", right child-node val: " << node->right->val;
    } else {
      std::cout << ", right child-node empty";
    }
    std::cout << std::endl;
  }

private:
  TreeNode *root;
};
