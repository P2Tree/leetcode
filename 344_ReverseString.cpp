#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char> &s) {
  if (s.size() == 0 || s.size() == 1)
    return;
  char *head = &s[0];
  char *tail = &s[s.size() - 1];

  while (true) {
    char c = *head;
    *head = *tail;
    *tail = c;

    head++;
    tail--;
    if (head >= tail) {
      break;
    }
  }
}

void printString(string prefix, vector<char> &s) {
  cout << prefix << " :";
  for (auto &c : s) {
    cout << c;
  }
  cout << endl;
}

int main() {
  vector<char> s0 = {};
  printString("before", s0);
  reverseString(s0);
  printString("after", s0);

  vector<char> s1 = {'a', 'b', 'c', 'd', 'e'};
  printString("before", s1);
  reverseString(s1);
  printString("after", s1);

  vector<char> s2 = {'a', 'b', 'c', 'd'};
  printString("before", s2);
  reverseString(s2);
  printString("after", s2);

  vector<char> s3 = {'a'};
  printString("before", s3);
  reverseString(s3);
  printString("after", s3);

  vector<char> s4 = {'a', 'b'};
  printString("before", s4);
  reverseString(s4);
  printString("after", s4);
}
