#include "Utils/Tree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  using Node = TreeNode;
  vector<int> preorder(Node *root) {
    vector<int> ret;
    if (root == nullptr)
      return {};
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
      auto *p = st.top();
      st.pop();
      ret.push_back(p->val);
      for (int i = p->children.size() - 1; i >= 0; i--) {
        st.push(p->children[i]);
      }
    }
    return ret;
  }
};

void test() {
  Solution so;
  vector<int> input = {1, 0, 2, 3, 4, 0, 5, 6};

  auto t = Tree(input);
  t.layerTraversal();

  auto ret = so.preorder(t);
  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test(); }
