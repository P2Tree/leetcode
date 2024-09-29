#include "Utils/Tree.h"
#include <iostream>
#include <queue>

using namespace std;
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> st;
    int depth = 0;
    st.push(root);
    while (!st.empty()) {
      size_t len = st.size();
      for (unsigned i = 0; i < len; ++i) {
        auto *p = st.front();
        for (auto iter : *p) {
          st.push(iter);
        }
        st.pop();
      }
      depth++;
    }
    return depth;
  }
};

void test() {
  Solution so;
  vector<int> input = {1, 2, 3, 0, 0, 6, 7};
  auto bt = Tree(input);
  auto ret = so.maxDepth(bt);
  cout << ret << endl;
}

int main() {
  test();
  return 0;
}
