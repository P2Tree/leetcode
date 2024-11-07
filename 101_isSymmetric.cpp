#include "Utils/BinaryTree.h"
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  // traversal
  bool isSymmetric1(TreeNode *root) {
    if (root == nullptr)
      return true;

    queue<TreeNode *> que;
    int layer = 2;
    int num_of_layer = layer;
    que.push(root->left);
    que.push(root->right);

    while (!que.empty()) {
      stack<TreeNode *> st;
      for (auto i = 0; i < num_of_layer; ++i) {
        if (que.empty())
          break;
        auto p = que.front();
        if (i < num_of_layer / 2) {
          st.push(que.front());
          que.pop();
        } else {
          if ((st.top() == nullptr && que.front() == nullptr) ||
              (st.top() != nullptr && que.front() != nullptr &&
               st.top()->val == que.front()->val)) {
            st.pop();
            que.pop();
          } else {
            return false;
          }
        }
        if (p != nullptr) {
          que.push(p->left);
          que.push(p->right);
        }
      }
      layer++;
      int quesize = que.size();
      num_of_layer = std::min(num_of_layer * 2, quesize);
    }
    return true;
  }

  // recursion
  bool compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr)
      return true;
    if (left == nullptr && right != nullptr)
      return false;
    if (left != nullptr && right == nullptr)
      return false;
    if (left->val != right->val)
      return false;

    auto outer = compare(left->left, right->right);
    auto inner = compare(left->right, right->left);
    return outer == true && inner == true;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    return compare(root->left, root->right);
  }
};

void test(vector<int> &input, bool golden) {
  Solution so;
  BinaryTree tree(input);
  // tree.layerOrderTraverse();
  auto res = so.isSymmetric(tree);
  cout << (res == true ? "is symmetric" : "is not symmetric") << endl;
  assert(res == golden);
}

int main() {
  vector<int> input1 = {1, 2, 2, 3, 4, 4, 3};
  test(input1, true);
  //         1
  //      2      2
  //    n  3   n   3
  vector<int> input2 = {1, 2, 2, 0, 3, 0, 3};
  test(input2, false);
  //         1
  //      2     2
  //    n  3  3   n
  vector<int> input3 = {1, 2, 2, 0, 3, 3};
  test(input3, true);
  //                 3
  //        4                    4
  //    5       n           n          5
  //  6   n                          n    6
  vector<int> input4 = {3, 4, 4, 5, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 6};
  test(input4, true);
}
