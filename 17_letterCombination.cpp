#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> res;
  string cs;
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
      return {};
    res.clear();
    cs.clear();
    backtrace(digits, 0);
    return res;
  }

private:
  void backtrace(string digit, int start) {
    if (start == digit.size()) {
      res.push_back(cs);
      return;
    }

    auto c = digit[start];
    auto vec = phoneBoard[c];

    for (int i = 0; i < vec.size(); i++) {
      cs.push_back(vec[i]);
      backtrace(digit, start + 1);
      cs.pop_back();
    }
  }
  std::map<char, vector<char>> phoneBoard{
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
};

void test(string digits) {
  Solution so;
  auto res = so.letterCombinations(digits);
  cout << "digits: " << digits << endl;
  for (auto &r : res) {
    cout << r << endl;
  }
}

int main() {
  test("23");
  test("2");
  test("456");
}
