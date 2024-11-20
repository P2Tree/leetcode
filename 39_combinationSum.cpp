#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> array;
    std::sort(candidates.begin(), candidates.end());
    search(0, array, candidates, target, 0);
    vector<vector<int>> sumSet;
    for (auto r : res) {
      sumSet.push_back(r);
    }
    return sumSet;
  }
  void search(int sum, vector<int> &array, vector<int> &input, int target,
              int start) {
    if (sum == target) {
      res.insert(array);
      return;
    }

    for (int i = start; i < input.size() && (sum + input[i] <= target); i++) {
      array.push_back(input[i]);
      search(sum + input[i], array, input, target, i);
      array.pop_back();
    }
  }

private:
  set<vector<int>> res;
};

void test(vector<int> &input, int target) {
  Solution so;
  auto res = so.combinationSum(input, target);
  for (auto &r : res) {
    for (auto i : r) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<int> input = {2, 3, 6, 7};
  test(input, 7);
  vector<int> input2 = {2, 3, 5};
  test(input2, 8);
}
