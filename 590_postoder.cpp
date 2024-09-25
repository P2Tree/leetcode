#include "Utils/Tree.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  using Node = TreeNode;
  vector<int> postorder(Node *root) {
    vector<int> ret;
    if (root == nullptr)
      return {};
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
      auto *p = st.top();
      st.pop();
      ret.push_back(p->val);
      for (int i = 0; i < p->children.size(); i++) {
        st.push(p->children[i]);
      }
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};

void test() {
  Solution so;
  vector<int> input = {1, 0, 2, 3, 4, 0, 5, 6};

  auto t = Tree(input);
  t.layerTraversal();

  auto ret = so.postorder(t);
  for (auto r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() { test(); }
