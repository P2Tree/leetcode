#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

vector<int> retv;

// 时间复杂度过高
int minSubArrayLen1(int target, vector<int> &nums) {
  unsigned win_size = 1;
  for (; win_size <= nums.size(); win_size++) {
    unsigned point = 0;
    for (; point + win_size <= nums.size(); point++) {
      unsigned sum = 0;
      for (unsigned s = point; s < win_size + point; s++) {
        sum += nums[s];
        retv.push_back(nums[s]);
        if (sum >= target) {
          return win_size;
        }
      }
      for (auto r : retv) {
        cout << r << " ";
      }
      cout << endl;
      retv.clear();
      retv.resize(0);
    }
  }
  return 0;
}

list<int> retl;

int minSubArrayLen(int target, vector<int> &nums) {
  if (nums.size() == 1) {
    if (nums[0] >= target) return 1;
    else return 0;
  }

  int i = 0, j = 0;
  unsigned sum = 0;
  unsigned ret = nums.size() + 1;
  for (; j < nums.size(); j++) {
    sum += nums[j];
    retl.push_back(nums[j]);
    while (sum >= target) {
      unsigned len = j - i + 1;
      ret = ret > len ? len : ret;
      sum -= nums[i++];
      for (auto &r : retl) {
        cout << r << " ";
      }
      cout << endl;
      retl.pop_front();
    }
  }
  if (ret == nums.size() + 1) return 0;
  return ret;
}

int main() {
  // vector<int> nums = { 2, 3, 1, 2, 4, 3 };
  // int target_golden[2] = { 7, 2 };
  // vector<int> nums = { 1, 4, 4 };
  // int target_golden[2] = { 4, 1 };
  // vector<int> nums = { 1, 1, 1, 1, 1 };
  // int target_golden[2] = { 10, 0 };
  vector<int> nums = { 8 };
  int target_golden[2] = { 7, 1 };
  int ret = minSubArrayLen(target_golden[0], nums);
  cout << "return: ";
  for (auto r : retl) {
    cout << r << " ";
  }
  cout << endl;
  cout << "Got return: " << to_string(ret) << endl;
  assert(ret == target_golden[1]);
  return 0;
}
