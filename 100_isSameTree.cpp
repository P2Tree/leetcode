#include "Utils/BinaryTree.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    vector<int> layerOfP = layerTraversal(p);
    cout << "======" << endl;
    return layerTraversalWithCheck(q, layerOfP);
  }

  vector<int> layerTraversal(TreeNode *root) {
    if (root == nullptr)
      return vector<int>{};

    queue<TreeNode *> que;
    que.push(root);
    vector<int> res;

    while (!que.empty()) {
      auto node = que.front();
      if (node == nullptr) {
        res.push_back(INT_MAX);
        que.pop();
        continue;
      }
      res.push_back(node->val);
      que.push(node->left);
      que.push(node->right);
      que.pop();
    }
    return res;
  }
  bool layerTraversalWithCheck(TreeNode *root, vector<int> &ref) {
    if (root == nullptr) {
      if (ref.size() == 0)
        return true;
      else
        return false;
    }

    queue<TreeNode *> que;
    que.push(root);

    unsigned int index = 0;
    while (!que.empty()) {
      auto node = que.front();
      if (node == nullptr) {
        if (index < ref.size() && ref[index] != INT_MAX) {
          return false;
        }
        if (index >= ref.size())
          return false;
        index++;
        que.pop();
        continue;
      }
      if (index < ref.size() && node->val != ref[index]) {
        return false;
      }
      if (index >= ref.size())
        return false;
      index++;
      que.push(node->left);
      que.push(node->right);
      que.pop();
    }
    if (index == ref.size())
      return true;
    return false;
  }
};

void test(vector<int> &input1, vector<int> &input2, bool golden) {
  Solution so;
  BinaryTree bt1(input1);
  BinaryTree bt2(input2);
  auto res = so.isSameTree(bt1, bt2);
  cout << (res == true ? "is same" : "not same") << endl;
  assert(res == golden);
}

int main() {
  vector<int> input1 = {1, 2, 3};
  test(input1, input1, true);

  vector<int> input2 = {1, 2};
  vector<int> input2r = {1, 0, 2};
  test(input2, input2r, false);
}
