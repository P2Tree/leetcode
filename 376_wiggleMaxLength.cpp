#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    const size_t numsSize = nums.size();
    if (numsSize == 0 || numsSize == 1)
      return numsSize;
    if (numsSize == 2) {
      if (nums[0] != nums[1]) {
        return numsSize;
      } else {
        return 1;
      }
    }

    int res = 0;
    vector<int> diff;
    for (int i = 0; i < nums.size() - 1; i++) {
      diff.push_back(nums[i + 1] - nums[i]);
    }

    int previous = INT_MAX;
    for (auto d : diff) {
      if (d == 0) {
        continue;
      }
      if (previous == INT_MAX) {
        res++;
        previous = d; // 0
      }
      if ((previous >= 0 && d < 0) || (previous < 0 && d >= 0)) {
        res++;
        previous = d;
      }
    }
    return res + 1;
  }
};

void test(vector<int> &nums, int golden) {
  Solution so;
  cout << "nums: [";
  for (auto n : nums) {
    cout << n << " ";
  }
  cout << "]" << endl;
  auto res = so.wiggleMaxLength(nums);
  cout << "max length: " << res << endl;
  assert(res == golden);
}

int main() {
  vector<int> nums1 = {1, 7, 4, 9, 2, 5};
  test(nums1, 6);
  vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  test(nums2, 7);
  vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  test(nums3, 2);
  vector<int> nums4 = {1};
  test(nums4, 1);
  vector<int> nums5 = {1, 2};
  test(nums5, 2);
  vector<int> nums6 = {1, 1};
  test(nums6, 1);
  vector<int> nums7 = {1, 1, 1, 1, 1};
  test(nums7, 1);
  vector<int> nums8 = {0, 0};
  test(nums8, 1);
  vector<int> nums9 = {3, 3, 3, 2, 5};
  test(nums9, 3);
  vector<int> nums10 = {1, 2, 2, 2, 1};
  test(nums10, 3);
  vector<int> nums11 = {1, 1, 7, 4, 9, 2, 5};
  test(nums11, 6);
  return 0;
}
