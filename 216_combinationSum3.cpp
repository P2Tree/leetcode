#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    current.clear();
    result.clear();
    backtracing(k, n, 1);
    return result;
  }

private:
  int sum = 0;
  vector<int> current;
  vector<vector<int>> result;
  void backtracing(const int k, const int n, const int s) {
    if (current.size() == k) {
      if (sum == n) {
        result.push_back(current);
      }
      return;
    }

    for (int i = s; i <= 9; ++i) {
      current.push_back(i);
      sum += i;
      backtracing(k, n, i + 1);
      current.pop_back();
      sum -= i;
      if (sum >= n)
        break;
    }
  }
};

void test(const int k, const int n) {
  Solution so;
  auto res = so.combinationSum3(k, n);
  cout << "k=" << k << ", n=" << n << endl;
  for (auto &v : res) {
    cout << "[";
    for (auto &vv : v) {
      cout << vv << ", ";
    }
    cout << "]" << endl;
  }
}

int main() {
  test(3, 7);
  test(3, 9);
  test(4, 1);
  return 0;
}
