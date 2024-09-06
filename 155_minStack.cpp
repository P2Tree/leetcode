#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    if (minimum > val)
      minimum = val;
    data.push_back(val);
  }

  void pop() {
    if (data.back() == minimum) {
      data.pop_back();
      minimum = INT_MAX;
      for (int i = 0; i < data.size(); ++i) {
        if (minimum > data[i])
          minimum = data[i];
      }
    } else
      data.pop_back();
  }

  int top() { return data[data.size() - 1]; }

  int getMin() { return minimum; }

private:
  int minimum = INT_MAX;
  vector<int> data;
};

void test1() {
  MinStack *st = new MinStack();
  st->push(4);
  st->push(2);
  st->push(5);
  cout << st->getMin() << endl;
  assert(st->getMin() == 2);
  st->pop();
  st->pop();
  cout << st->getMin() << endl;
  assert(st->getMin() == 4);
}

void test2() {
  MinStack *st = new MinStack();
  st->push(-2);
  st->push(0);
  st->push(-3);
  cout << st->getMin() << endl;
  assert(st->getMin() == -3);
  st->pop();
  st->top();
  cout << st->getMin() << endl;
  assert(st->getMin() == 0);
}

int main() {
  test1();
  test2();
}
