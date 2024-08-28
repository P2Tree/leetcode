#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
  if (nums.size() == 1) return {nums[0] * nums[0]};

  int i = 0, j = 0, s;
  for (s = 0; s < nums.size(); s++) {
    if (nums[s] >= 0) break;
  }
  i=s-1;
  j=s;
  cout << i << " " << j << endl;

  vector<int> ret;
  for (;i >= 0 && j != nums.size();) {
    int ii = nums[i] * nums[i];
    int jj = nums[j] * nums[j];
    if (ii > jj) {
      ret.emplace_back(jj);
      j++;
    } else {
      ret.emplace_back(ii);
      i--;
    }
  }
  cout << i << " " << j << endl;
  if (i < 0 && j != nums.size()) {
    for (;j != nums.size(); j++) {
      ret.emplace_back(nums[j] * nums[j]);
    }
  } else if (i >= 0 && j == nums.size()) {
    for (;i >=0; i--) {
      ret.emplace_back(nums[i] * nums[i]);
    }
  }
  return ret;
}

int main() {
  // vector<int> nums = {-4, -1, 0, 3, 10};
  // vector<int> golden = {0, 1, 9, 16, 100};
  // vector<int> nums = {-7,-3,2,3,11};
  // vector<int> golden = {4,9,9,49,121};
  // vector<int> nums = {1};
  // vector<int> golden = {1};
  // vector<int> nums = {-5,-3,-2,-1};
  // vector<int> golden = {1,4,9,25};
  // vector<int> nums = {-10, 0, 0, 10};
  // vector<int> golden = {0, 0, 100, 100};
  vector<int> nums = {-10000,-9999, -7, -5, 0, 0, 10000};
  vector<int> golden = {0, 0, 25, 49, 99980001, 100000000, 100000000};

  vector<int> output = sortedSquares(nums);
  bool notMatch = false;
  cout << "golden: ";
  for (unsigned i = 0; i < golden.size(); i++) {
    if (golden[i] != output[i]) notMatch = true;
    cout << golden[i] << " ";
  }
  cout << endl;
  cout << "output: ";
  for (auto o : output) {
    cout << o << " ";
  }
  cout << endl;
  if (notMatch) {
    cout << "Don't match" << endl;
  }

  return 0;
}
