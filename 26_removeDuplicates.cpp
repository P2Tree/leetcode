#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 1)
      return 1;
    int i = 1, j = 1;

    int c = nums[0];
    for (; j < nums.size(); j++) {
      if (nums[j] != c) {
        nums[i] = nums[j];
        c = nums[i];
        i++;
      }
    }
    return i;
  }
};

void test1() {
  Solution so;
  vector<int> nums = {1, 1, 2, 3, 3};
  auto ret = so.removeDuplicates(nums);
  for (auto n : nums)
    cout << n << endl;
  assert(ret == 3);
}

int main() { test1(); }
