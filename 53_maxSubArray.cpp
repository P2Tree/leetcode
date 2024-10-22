#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    int begin = 0, end = nums.size() - 1;
    int count = 0;
    int max = INT_MIN;
    // -1 -2
    for (int i = 0; i < nums.size(); i++) {
      count += nums[i];
      if (count > max) {
        max = count;
      }
      if (count < 0) {
        count = 0;
      }
    }
    return max;
  }
};

void test(vector<int> &nums, int golden) {
  Solution so;
  cout << "input: ";
  for (auto n : nums) {
    cout << n << ", ";
  }
  cout << endl;
  auto res = so.maxSubArray(nums);
  cout << "the length of max sub-array is: " << res << endl;
  assert(res == golden);
}

int main() {
  vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  test(nums1, 6);
  vector<int> nums2 = {1};
  test(nums2, 1);
  vector<int> nums3 = {5, 4, -1, 7, 8};
  test(nums3, 23);
  vector<int> nums4 = {0};
  test(nums4, 0);
  vector<int> nums5 = {-2, 1};
  test(nums5, 1);
  vector<int> nums6 = {-1, -2};
  test(nums6, -1);
  vector<int> nums7 = {-2, -1};
  test(nums7, -1);
  vector<int> nums8 = {1, 2, -1, -2, 2, 1, -2, 1};
  test(nums8, 3);

  return 0;
}
