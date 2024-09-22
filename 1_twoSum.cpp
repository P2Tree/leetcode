#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (auto n = 0; n < nums.size() - 1; n++) {
      for (auto m = n + 1; m < nums.size(); m++) {
        if (nums[n] + nums[m] == target) {
          return {n, m};
        }
      }
    }
    return {};
  }
};

void test1() {
  Solution so;
  vector<int> nums = {2, 7, 11, 13};
  int target = 9;
  auto ret = so.twoSum(nums, target);
  cout << target << " = " << ret[0] << " + " << ret[1] << endl;
  ;
}

int main() { test1(); }
