#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    stack<int> st;
    int res = 0;
    int num = height.size();
    vector<int> com;
    for (int i = 0; i < num; i++) {
      if (st.empty()) {
        st.push(i);
        continue;
      }

      // st: 1 2
      int current = height[i];
      if (current < height[st.top()]) {
        st.push(i);
      } else if (current == height[st.top()]) {
        st.pop();
        st.push(i);
      } else {
        while (!st.empty() && current > height[st.top()]) {
          int mid = height[st.top()];
          st.pop();
          if (!st.empty()) {
            int left = height[st.top()];
            int low = std::min(left, current);
            int h = low - mid;
            int w = i - st.top() - 1;
            res += h * w;
          }
        }
        st.push(i);
      }
    }

    return res;
  }
};

void test() {
  Solution so;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto res = so.trap(height);
  cout << "res: " << res << endl;
  assert(res == 6);
}

int main() {
  test();
  return 0;
}
