#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12)
      return {};
    string path;
    int pointNum = 0;
    search(s, 0, path, pointNum);
    return res;
  }
  void search(const string s, int start, string path, int pointNum) {
    if (start >= s.size()) {
      if (pointNum != 4) {
        return;
      }
      path.resize(path.size() - 1);
      res.push_back(path);
      return;
    }
    pointNum++;
    if (pointNum > 4 && start < s.size()) {
      return;
    }
    for (int i = 1; i <= 3 && (start + i) <= s.size(); i++) {
      auto subs = s.substr(start, i);
      if (!isValidIP(subs)) {
        break;
      }
      path += subs;
      path += ".";
      search(s, start + i, path, pointNum);
      path = path.substr(0, path.size() - subs.size() - 1);
    }
  }
  vector<string> res;
  bool isValidIP(string s) {
    if (s[0] == '0' && s.size() != 1) {
      return false;
    }
    if (s.size() > 3) {
      return false;
    }
    if (std::stoi(s) > 255) {
      return false;
    }
    return true;
  }
};

void test(string str) {
  Solution so;
  auto res = so.restoreIpAddresses(str);
  for (auto &s : res) {
    cout << s << endl;
  }
  cout << endl;
}

int main() {
  test(string("25525511135"));
  test(string("0000"));
  test(string("101023"));
}
