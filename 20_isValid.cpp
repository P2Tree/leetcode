#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.size() == 0)
      return true;
    stack<char> st;
    for (auto c : s) {
      if (!st.empty()) {
        if ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') ||
            (st.top() == '{' && c == '}')) {
          st.pop();
          continue;
        }
      }
      st.push(c);
    }
    if (st.empty())
      return true;
    return false;
  }
};

void test1() {
  Solution so;
  string input = "()";
  bool isValid = so.isValid(input);
  cout << input << " is valid? " << (isValid ? "Yes" : "No") << endl;
}

void test2() {
  Solution so;
  string input = "(()";
  bool isValid = so.isValid(input);
  cout << input << " is valid? " << (isValid ? "Yes" : "No") << endl;
}

void test3() {
  Solution so;
  string input = "[[]]";
  bool isValid = so.isValid(input);
  cout << input << " is valid? " << (isValid ? "Yes" : "No") << endl;
}
int main() { test1(); }
