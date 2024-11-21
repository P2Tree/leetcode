#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> array;
    vector<bool> used(candidates.size(), false);
    std::sort(candidates.begin(), candidates.end());
    search(0, array, candidates, target, 0, used);
    vector<vector<int>> sumSet;
    for (auto r : res) {
      sumSet.push_back(r);
    }
    return sumSet;
  }
  void search(int sum, vector<int> &array, vector<int> &input, int target,
              int start, vector<bool> used) {
    if (sum == target) {
      vector<int> tmp(array);
      std::sort(tmp.begin(), tmp.end());
      res.insert(tmp);
      return;
    }

    for (int i = start; i < input.size() && (sum + input[i] <= target); i++) {
      if (i > 0 && input[i] == input[i - 1] && used[i] == true)
        continue;
      array.push_back(input[i]);
      used[i] = true;
      search(sum + input[i], array, input, target, i + 1, used);
      array.pop_back();
      used[i] = false;
    }
  }

private:
  set<vector<int>> res;
};

void test(vector<int> &input, int target) {
  Solution so;
  auto res = so.combinationSum2(input, target);
  for (auto &r : res) {
    for (auto i : r) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<int> input = {10, 1, 2, 7, 6, 1, 5};
  test(input, 8);
  // vector<int> input2 = {2, 3, 5};
  // test(input2, 8);
}
