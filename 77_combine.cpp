#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void findit1(vector<int> data, vector<int> current, vector<vector<int>> &ret,
               int k) {
    if (current.size() >= k) {
      ret.push_back(current);
      return;
    }

    for (auto iter = data.begin(); iter != data.end(); iter++) {
      int val = *iter;
      current.push_back(val);
      auto datacopy = vector(iter + 1, data.end());
      findit1(datacopy, current, ret, k);
      current.erase(current.end() - 1);
    }
  }
  vector<vector<int>> combine1(int n, int k) {
    vector<int> data;
    data.reserve(n);
    for (int i = 1; i <= n; i++) {
      data.push_back(i);
    }
    vector<int> current;
    vector<vector<int>> ret;
    findit1(data, current, ret, k);
    return ret;
  }

  // reference:
  void backtracing(int s, int n, int k, vector<int> &current,
                   vector<vector<int>> &result) {
    if (current.size() == k) {
      result.emplace_back(current);
      return;
    }

    for (int i = s; i <= n - (k - current.size()) + 1; i++) {
      current.emplace_back(i);
      backtracing(i + 1, n, k, current, result);
      current.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> current;
    vector<vector<int>> result;
    backtracing(1, n, k, current, result);
    return result;
  }
};

void test1() {
  Solution so;
  int n = 4;
  int k = 2;
  auto ret = so.combine(n, k);
  cout << "n=" << n << ", k=" << k << endl;
  for (auto &r : ret) {
    cout << "[";
    for (auto &rr : r) {
      cout << rr << ", ";
    }
    cout << "]" << endl;
  }
}

void test2() {
  Solution so;
  int n = 1;
  int k = 1;
  auto ret = so.combine(n, k);
  cout << "n=" << n << ", k=" << k << endl;
  for (auto &r : ret) {
    cout << "[";
    for (auto &rr : r) {
      cout << rr << ", ";
    }
    cout << "]" << endl;
  }
}

int main() {
  test1();
  test2();
  return 0;
}
