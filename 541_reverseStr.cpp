#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    size_t len = s.size();
    if (len <= k) {
      std::reverse(s.begin(), s.end());
      return s;
    }
    int i = 2 * k;
    auto start = s.begin();
    while (i <= len) {
      std::reverse(start, start + k);
      i += 2 * k;
      start = start + 2 * k;
    }
    i -= 2 * k;
    int remain = len - i;
    // start = start - 2 * k;
    if (remain < k) {
      std::reverse(start, s.end());
      return s;
    }
    std::reverse(start, start + k);
    return s;
  }

  string reverseStr_broken(string s, int k) {
    size_t len = s.size();
    if (len <= k) {
      std::reverse(s.begin(), s.end());
      return s;
    }
    auto a = s.begin();
    int i = 0;
    bool open = true;
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
      if (i != 0 && open && i % k == 0) {
        std::reverse(a, iter);
        open = false;
      }
      if (i % (2 * k) == 0) {
        open = true;
        a = iter;
      }
      ++i;
    }
    return s;
  }
};

void test1() {
  Solution so;
  string s = "abcdefg";
  int i = 2;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "bacdfeg");
}

void test2() {
  Solution so;
  string s = "abcd";
  int i = 2;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "bacd");
}

void test3() {
  Solution so;
  string s = "abc";
  int i = 4;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "cba");
}

void test4() {
  Solution so;
  string s = "a";
  int i = 1;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "a");
}

void test5() {
  Solution so;
  string s = "abcd";
  int i = 4;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "dcba");
}

void test6() {
  Solution so;
  string s = "abcdefg";
  int i = 8;
  cout << "in: " << s << ", index: " << i << endl;
  auto ret = so.reverseStr(s, i);
  cout << "out: " << ret << endl;
  assert(ret == "gfedcba");
}
int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
}
