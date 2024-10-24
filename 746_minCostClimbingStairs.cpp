#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    const size_t floors = cost.size();
    // if has 0 or 1 or 2's floor
    if (floors == 0 || floors == 1)
      return 0;

    int res = 0;
    vector<int> dp;
    dp.assign(2, 0);
    for (int i = 2; i <= floors; i++) {
      int r = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
      dp.push_back(r);
    }
    cout << "dp: ";
    for (auto &d : dp) {
      cout << d << ", ";
    }
    cout << endl;
    res = dp[dp.size() - 1];

    return res;
  }
};

void test(vector<int> &cost, int golden) {
  Solution so;
  cout << "cost array: ";
  for (auto &c : cost) {
    cout << c << ", ";
  }
  cout << endl;
  auto res = so.minCostClimbingStairs(cost);
  cout << "cost is: " << res << endl;
  assert(res == golden);
}

// step 1: dp[i] is 如果有 i 节台阶，最省成本的爬法
// step 2: dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
// step 3: dp[0] = 0, dp[1] = 0
// step 4: order is 0 to larger
// step 5:
// floor: 0,  1,  2,  top
// cost:  10, 15, 20
// dp:    0,  0,  10, 15
int main() {
  vector<int> cost1 = {10, 15, 20};
  test(cost1, 15);
  vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  test(cost2, 6);
  vector<int> cost3 = {1, 100};
  test(cost3, 1);
}
