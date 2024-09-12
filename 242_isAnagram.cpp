#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (auto c : s) {
      auto iter = m.find(c);
      if (iter != m.end()) {
        iter->second += 1;
      } else {
        m.insert({c, 1});
      }
    }
    // for (auto c : m) {
    //   cout << c.first << ":" << c.second << " " << endl;
    // }
    for (auto c : t) {
      auto iter = m.find(c);
      if (iter != m.end()) {
        if (iter->second == 0)
          return false;
        iter->second -= 1;
      } else {
        return false;
      }
    }
    for (auto c : m) {
      if (c.second != 0)
        return false;
    }
    return true;
  }
};

void test1() {
  Solution so;
  string s = "abcda";
  string t = "bacad";

  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  auto ret = so.isAnagram(s, t);
  cout << (ret ? "ok" : "not") << endl;
  assert(ret == true);
}

void test2() {
  Solution so;
  string s = "abcda";
  string t = "bacaa";

  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  auto ret = so.isAnagram(s, t);
  cout << (ret ? "ok" : "not") << endl;
  assert(ret == false);
}

void test3() {
  Solution so;
  string s = "a";
  string t = "ba";

  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  auto ret = so.isAnagram(s, t);
  cout << (ret ? "ok" : "not") << endl;
  assert(ret == false);
}
int main() {
  test1();
  test2();
  test3();
}
