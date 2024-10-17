#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    if (s.size() == 0)
      return 0;
    unsigned res = 0;
    unsigned total = g.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (!g.empty() && !s.empty()) {
      auto gg = g.end() - 1;
      auto ss = s.end() - 1;
      if (*ss >= *gg) {
        res++;
        s.erase(ss);
        g.erase(gg);
      } else {
        g.erase(gg);
      }
    }

    return res;
  }
};

void test() {
  Solution so;
  vector<int> g = {1, 2, 3};
  vector<int> s = {1, 1};
  auto res = so.findContentChildren(g, s);
  cout << res << endl;
}

void test2() {
  Solution so;
  vector<int> g = {10, 9, 8, 7};
  vector<int> s = {10, 9, 8, 7};
  auto res = so.findContentChildren(g, s);
  cout << res << endl;
}
int main() {
  test();
  test2();
  return 0;
}
