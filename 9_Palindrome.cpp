#include <iostream>
#include <stack>

using namespace std;

// my answer after read solution
bool isPalindrome_2(int x) {
  if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
  }

  int y = 0;
  while (x > y) {
    y = y * 10 + x % 10;
    x = x / 10;
  }

  return x == y || x == y / 10;
}

// my answer
bool isPalindrome_1(int x) {
  if (x < 0)
    return false;
  if (x < 10)
    return true;

  bool Fine = false;

  stack<int> st;
  unsigned len = 0;
  long long i = 1;
  for (; x / i != 0; i = i * 10) {
    len++;
  }

  i /= 10;
  for (unsigned j = len; j > 0; j--, i /= 10) {
    unsigned current = (x - x % i) / i;
    x = x % i;
    unsigned middle = len / 2 + 1;
    if (len % 2 != 0 && j == middle) {
      continue;
    }
    if (j >= middle) {
      st.push(current);
    } else {
      if (st.top() != current) {
        return false;
      }
      st.pop();
    }
  }

  return true;
}

int main() {
  int input[] = {121, -121, 0, 112, 211, 11, 12, 1441, 1414, 1000000001 };
  bool golden[] = {true, false, true, false, false, true, false, true, false, true};

  constexpr unsigned size = sizeof(input) / 4;

  bool hasFail = false;
  for (unsigned i = 0; i < size; i++) {
    bool ret = isPalindrome_2(input[i]);
    if (ret != golden[i]) {
      cout << "  input: " << input[i] << " output: " << ret
           << " expected: " << golden[i] << endl;
      hasFail = true;
    }
  }
  if (hasFail) {
    cout << "Failed" << endl;
    return -1;
  } else {
    cout << "Success." << endl;
  }

  return 0;
}
