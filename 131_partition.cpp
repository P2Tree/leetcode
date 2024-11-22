#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    if (s == "")
      return {};
    string subs("");
    vector<string> vecs;
    search(s, subs, vecs, 0);
    return res;
  }
  void search(const string &s, string subs, vector<string> vecs, int start) {
    if (start >= s.size()) {
      res.push_back(vecs);
      vecs.clear();
      return;
    }
    for (int i = start; i < s.size(); i++) {
      auto subs = s.substr(start, i - start + 1);
      if (isRotateStr(subs)) {
        vecs.push_back(subs);
      } else {
        continue;
      }
      search(s, subs, vecs, i + 1);
      vecs.pop_back();
    }
  }
  bool isRotateStr(const string &s) {
    if (s == "")
      return false;
    auto p = s.begin();
    auto q = s.end() - 1;
    while (p < q && *p == *q) {
      p++;
      q--;
    }
    if (p < q)
      return false;
    else
      return true;
  }
  vector<vector<string>> res;
};

void test(string s) {
  Solution so;
  auto res = so.partition(s);
  for (auto &vec : res) {
    for (auto &c : vec) {
      cout << c << " ";
    }
    cout << "|" << endl;
  }
  cout << "===" << endl;
}

int main() { test(string("aab")); }
