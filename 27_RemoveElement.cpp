#include <iostream>
#include <vector>

using namespace std;

int RemoveElement2(vector<int> &nums, int val) {
  if (nums.size() == 0) return 0;

  int i = 0, j = 0;
  for (;j < nums.size();j++) {
    if (nums[j] != val) {
      nums[i++] = nums[j];
    }
  }
  return i;
}

int RemoveElement(vector<int> &nums, int val) {
  if (nums.size() == 0) return 0;

  int len = nums.size();
  for (unsigned i = 0; i < len;) {
    if (nums[i] == val) {
      nums[i] = nums[len-1];
      len--;
    } else {
      i++;
    }
  }
  return len;
}

void test(vector<int> nums, vector<int> golden, int val) {
  int ret = RemoveElement2(nums, val);
  assert(ret == golden.size());
  cout << "golden: ";
  for (auto g : golden) {
    cout << g << " ";
  }
  cout << "\nnums: ";
  for (unsigned i = 0; i < ret; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  test({3, 2, 2, 3}, {2, 2}, 3);
  test({0,1,2,2,3,0,4,2}, {0,1,4,0,3}, 2);
  return 0;
}
