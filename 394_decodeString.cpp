#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<char> st;
    for (auto &c : s) {
      if (c == ']') {
        string subs;
        while (st.top() != '[') {
          subs = st.top() + subs;
          st.pop();
        }
        st.pop(); // pop '['
        string nstr;
        while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
          nstr = st.top() + nstr;
          st.pop(); // pop number
        }
        unsigned n = stoi(nstr);
        string sub;
        for (; n > 0; n--) {
          sub = sub + subs;
        }
        for (auto &c : sub) {
          st.push(c);
        }
      } else {
        st.push(c);
      }
    }
    string ret;
    while (!st.empty()) {
      ret = st.top() + ret;
      st.pop();
    }
    return ret;
  }
};

void test1() {
  Solution so;
  string s = "3[a]2[bc]";
  auto ret = so.decodeString(s);
  cout << "input: " << s << ", output: " << ret << endl;
  assert(ret == "aaabcbc");
}

void test2() {
  Solution so;
  string s = "3[a2[c]]";
  auto ret = so.decodeString(s);
  cout << "input: " << s << ", output: " << ret << endl;
  assert(ret == "accaccacc");
}

void test3() {
  Solution so;
  string s = "2[abc]3[cd]ef";
  auto ret = so.decodeString(s);
  cout << "input: " << s << ", output: " << ret << endl;
  assert(ret == "abcabccdcdcdef");
}

void test4() {
  Solution so;
  string s = "abc3[cd]xyz";
  auto ret = so.decodeString(s);
  cout << "input: " << s << ", output: " << ret << endl;
  assert(ret == "abccdcdcdxyz");
}

int main() {
  test1();
  test2();
  test3();
  test4();
}
