#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() == 0 || nums2.size() == 0)
      return {};
    stack<int> st;
    unordered_map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums2.size(); i++) {
      if (st.empty()) {
        st.push(i);
        continue;
      }
      int current = nums2[i];
      while (!st.empty() && current > nums2[st.top()]) {
        int n = st.top();
        m.insert(std::make_pair(nums2[n], current));
        st.pop();
      }
      st.push(i);
    }
    // cout << endl << "map: ";
    // for (auto mm : m) {
    //   cout << mm.first << ": " << mm.second << ", ";
    // }
    // cout << endl;

    for (auto j : nums1) {
      if (m.find(j) != m.end()) {
        res.push_back(m[j]);
      } else {
        res.push_back(-1);
      }
    }
    return res;
  }
};

void test() {
  Solution so;
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  // -1, 3, -1
  auto res = so.nextGreaterElement(nums1, nums2);
  for (auto r : res) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() {
  test();
  return 0;
}
