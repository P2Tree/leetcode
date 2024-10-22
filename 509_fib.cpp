#include <cassert>
#include <iostream>
using namespace std;

// step 1: dp[i] is the fab value of index i
// step 2: dp function is fab[i] = fab[i-2] + fab[i-1]
// step 3: dp[i] initialize is fab[0] = 0, fab[1] = 1
// step 4: traverse order is from 0 to larger index
// step 5: example dp[i] =
// 0 1 1 2 3 5 8 13
// 0 1 2 3 4 5 6 7
//
class Solution {
public:
  int fib(int n) {
    if (n == 0 || n == 1)
      return n;
    int a = 0, b = 1;
    int res = 0;
    for (int i = 2; i <= n; i++) {
      res = a + b;
      a = b;
      b = res;
    }
    return res;
  }
};

void test(int n, int golden) {
  Solution so;
  int res = so.fib(n);
  cout << "input: " << n << ", output: " << res << endl;
  assert(res == golden);
}

int main() {
  test(2, 1); // 0+1
  test(3, 2); // 1+1
  test(4, 3); // 1+2
  test(5, 5); // 2+3
  test(6, 8);
  test(7, 13);
}
