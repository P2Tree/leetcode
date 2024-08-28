#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int binary_search(vector<int> &nums, unsigned begin, unsigned end, int target) {
    if (begin >= end) {
      if (nums[begin] == target) return begin;
      return -1;
    }
    unsigned middle = (end + begin) / 2;
    int middle_item = nums[middle];
    if (middle_item == target) {
      return middle;
    } else if (middle_item > target) {
      return binary_search(nums, begin, middle-1, target);
    } else {
      return binary_search(nums, middle+1, end, target);
    }
  }

  int search(vector<int> nums, int target) {
    unsigned size = nums.size();
    if (size == 1) {
      if (nums[0] == target) return 0;
      return -1;
    } else if (size == 2) {
      if (nums[0] == target) return 0;
      else if (nums[1] == target) return 1;
      else return -1;
    }
    return binary_search(nums, 0, size-1, target);
  }

};

int main() {
  Solution S;
  vector<int> nums = { -8, -3, -1, 0, 2, 4, 7, 12, 18 };
  int target[] = { -10, -8, -2, -1, 0,  3, 4, 18, 19 };
  int golden[] = { -1,  0,  -1, 2,  3, -1, 5, 8,  -1 };
  // int target[] = { -1 };
  // int golden[] = { 2 };

  unsigned target_num = sizeof(target) / sizeof(int);
  for (unsigned i = 0; i < target_num; i++) {
    int ret = S.search(nums, target[i]);
    if (ret != golden[i]) {
      cout << "target: " << target[i] << " failed. Got: " << ret <<
        ", Expect: " << golden[i] << endl;
    }
  }

  return 0;
}
