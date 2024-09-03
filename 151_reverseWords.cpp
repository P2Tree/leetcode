#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  // space complexity: O(N)
  string reverseWords_Plan1(string s) {
    vector<string> words;

    auto pin = s.find_first_not_of(' ');
    s = s.substr(pin, s.size());

    while (!s.empty()) {
      auto pin = s.find_first_of(' ');
      words.emplace_back(s.substr(0, pin));
      s.erase(0, pin);
      pin = s.find_first_not_of(' ');
      s.erase(0, pin);
    }

    string rets;
    for (int i = words.size() - 1; i >= 0; i--) {
      rets += words[i];
      rets += ' ';
    }
    rets = rets.substr(0, rets.size() - 1);
    return rets;
  }
  // space complexity: O(1)
  string reverseWords(string s) {
    auto begin = s.find_first_not_of(' ');
    auto end = s.find_last_not_of(' ');
    s = s.substr(begin, end + 1 - begin);

    auto p = s.begin();
    auto q = s.end() - 1;

    while (p < q) {
      char c = *p;
      *p = *q;
      *q = c;
      p++;
      q--;
    }

    auto start = s.begin();
    for (auto iter = s.begin(); iter != s.end();) {
      if (*iter == ' ' || iter == s.end() - 1) {
        // get a word
        auto p = start;
        auto q = (iter == s.end() - 1) ? iter : iter - 1;
        while (p < q) {
          char c = *p;
          *p = *q;
          *q = c;
          p++;
          q--;
        }
        iter++;
        while (*iter == ' ') {
          s.erase(iter);
        }
        start = iter;
      } else {
        iter++;
      }
    }
    return s;
  }
};

void test1() {
  string input = "hello world";
  cout << "input: " << input << endl;
  Solution so;
  auto output = so.reverseWords(input);
  cout << "output: " << output << endl;
}

void test2() {
  string input = " hello  cc  ";
  cout << "input: " << input << endl;
  Solution so;
  auto output = so.reverseWords(input);
  cout << "output: " << output << endl;
}
int main() {
  test1();
  test2();
}
