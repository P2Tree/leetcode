#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1 || n == 2)
      return n;
    int a = 1, b = 2;
    int res = 0;
    for (int i = 3; i <= n; i++) {
      res = a + b;
      a = b;
      b = res;
    }
    return res;
  }
};

void test(int n, int golden) {
  Solution so;
  auto res = so.climbStairs(n);
  cout << "input: " << n << ", output: " << res << endl;
  assert(res == golden);
}

int main() {
  // step 1: dp[i] is 如果有 i 节台阶，有多少种爬法
  // step 2: dp[i] = dp[i-1] + dp[i-2];
  // step 3: dp[0] = 0, dp[1] = 1, dp[2] = 2
  // step 4: order is 0 to larger
  // step 5:
  // 0 1 2 3 4 5 6 7
  // 0 1 2 3 5
  test(2, 2);
  test(3, 3);
}
