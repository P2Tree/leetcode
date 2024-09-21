#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() == 0 || nums2.size() == 0)
      return vector<int>();
    unordered_set<int> s;
    for (auto n : nums1) {
      s.insert(n);
    }
    unordered_set<int> rets;
    for (auto n : nums2) {
      if (s.find(n) != s.end()) {
        rets.insert(n);
      }
    }
    vector<int> ret;
    for (auto n : rets)
      ret.push_back(n);
    return ret;
  }
};

void test1() {
  Solution so;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 3};
  cout << "nums1: ";
  for (auto n : nums1) {
    cout << n << ", ";
  }
  cout << endl << "nums2: ";
  for (auto n : nums2) {
    cout << n << ", ";
  }
  cout << endl;
  auto ret = so.intersection(nums1, nums2);
  cout << "ret: ";
  for (auto n : ret) {
    cout << n << ", ";
  }
  cout << endl;
}

void test2() {
  Solution so;
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  cout << "nums1: ";
  for (auto n : nums1) {
    cout << n << ", ";
  }
  cout << endl << "nums2: ";
  for (auto n : nums2) {
    cout << n << ", ";
  }
  cout << endl;
  auto ret = so.intersection(nums1, nums2);
  cout << "ret: ";
  for (auto n : ret) {
    cout << n << ", ";
  }
  cout << endl;
}

int main() {
  test1();
  test2();
}
