#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // O(m*n)
  int strStr1(string haystack, string needle) {
    auto h_iter = haystack.begin();
    const auto h_end = haystack.end();
    auto n_iter = needle.begin();
    const auto n_end = needle.end();
    while (h_iter != h_end) {
      if (*h_iter == *n_iter) {
        if (n_iter + 1 == n_end) {
          return h_iter - haystack.begin() + 1 - needle.size();
        }
        n_iter++;
        h_iter++;
      } else {
        while (n_iter != needle.begin()) {
          n_iter--;
          h_iter--;
        }
        h_iter++;
      }
    }
    return -1;
  }

  // KMP, O(n+m)
  vector<int> make_next(string needle) {
    vector<int> next(needle.size());
    next[0] = -1;
    int i = 0;
    int j = -1;

    while (i < (int)needle.size()) {
      if (j == -1 || needle[i] == needle[j]) {
        i++;
        j++;
        next[i] = j;
      } else {
        j = next[j];
      }
    }
    return next;
  }

  int strStr(string haystack, string needle) {
    int i = 0;
    int j = 0;

    auto next = make_next(needle);

    while (i < (int)haystack.size() && j < (int)needle.size()) {
      if (j == -1 || haystack[i] == needle[j]) {
        i++;
        j++;
      } else {
        j = next[j];
      }
    }
    if (j == (int)needle.size()) {
      return i - j;
    } else {
      return -1;
    }
  }
};

void test1() {
  Solution so;
  string h = "abcdef";
  string n = "bc";
  auto index = so.strStr(h, n);
  cout << n << " in " << h << ": " << index << endl;
  assert(index == 1);
}

void test2() {
  Solution so;
  string h = "leetcode";
  string n = "let";
  auto index = so.strStr(h, n);
  cout << n << " in " << h << ": " << index << endl;
  assert(index == -1);
}

void test3() {
  Solution so;
  string h = "sadbutsad";
  string n = "sad";
  auto index = so.strStr(h, n);
  cout << n << " in " << h << ": " << index << endl;
  assert(index == 0);
}

int main() {
  test1();
  test2();
  test3();
}
