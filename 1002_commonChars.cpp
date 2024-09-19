#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    const size_t len = words.size();
    unordered_map<char, vector<int>> m;
    for (auto i = 0; i < len; i++) {
      for (auto &c : words[i]) {
        if (m.find(c) == m.end()) {
          vector<int> v(len);
          v[i] = 1;
          m[c] = v;
        } else {
          m[c][i]++;
        }
      }
    }
    vector<string> ret;
    for (auto &x : m) {
      // cout << x.first << ": [";
      // for (auto i = 0; i < len; i++)
      //   cout << x.second[i] << ", ";
      // cout << "]" << endl;

      bool has_0 = false;
      while (has_0 == false) {
        for (auto i = 0; i < len; i++) {
          if (x.second[i] == 0)
            has_0 = true;
          x.second[i]--;
        }
        if (has_0 == false) {
          string s{x.first};
          ret.push_back(s);
        }
      }
    }
    return ret;
  }
};

void test1() {
  Solution so;
  vector<string> words = {"cool", "cock", "lock"};
  cout << "in: ";
  for (auto &r : words) {
    cout << r << ", ";
  }
  cout << endl;
  auto ret = so.commonChars(words);
  cout << "out: ";
  for (auto &r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

void test2() {
  Solution so;
  vector<string> words = {"bella", "label", "roller"};
  cout << "in: ";
  for (auto &r : words) {
    cout << r << ", ";
  }
  cout << endl;
  auto ret = so.commonChars(words);
  cout << "out: ";
  for (auto &r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

void test3() {
  Solution so;
  vector<string> words = {"bellla", "aabea", "roaaer"};
  cout << "in: ";
  for (auto &r : words) {
    cout << r << ", ";
  }
  cout << endl;
  auto ret = so.commonChars(words);
  cout << "out: ";
  for (auto &r : ret) {
    cout << r << ", ";
  }
  cout << endl;
}

int main() {
  test1();
  test2();
  test3();
}
