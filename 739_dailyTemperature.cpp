#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures_force(vector<int> &temperatures) {
    vector<int> res;
    for (int i = 0; i < temperatures.size(); i++) {
      int c = 0;
      int j = i + 1;
      int current = temperatures[i];
      for (; j < temperatures.size(); j++) {
        c++;
        if (temperatures[j] > current) {
          break;
        }
      }
      if (j == temperatures.size()) {
        res.push_back(0);
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> dec;
    vector<int> res;
    res.resize(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      if (dec.empty()) {
        dec.push(i);
        continue;
      }
      int current = temperatures[i];
      while (!dec.empty() && current > temperatures[dec.top()]) {
        int s = dec.top();
        res[s] = i - s;
        dec.pop();
      }
      dec.push(i);
    }
    return res;
  }
};

void test() {
  Solution so;
  vector<int> tempers = {73, 74, 75, 71, 69, 72, 76, 73};
  auto res = so.dailyTemperatures(tempers);
  cout << "input: ";
  for (auto i : tempers) {
    cout << i << ", ";
  }
  cout << endl;
  cout << "output: ";
  for (auto o : res) {
    cout << o << ", ";
  }
  cout << endl;
  // 1,1,4,2,1,1,0,0
}

int main() { test(); }
