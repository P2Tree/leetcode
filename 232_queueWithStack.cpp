#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    auto x = s2.top();
    s2.pop();
    return x;
  }

  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }

private:
  stack<int> s1;
  stack<int> s2;
};

void test1() {
  MyQueue *obj = new MyQueue();
  obj->push(1);
  obj->push(2);
  auto x = obj->pop();
  assert(x == 1);
  auto y = obj->peek();
  assert(y == 2);
  assert(obj->empty() == false);
  obj->pop();
  assert(obj->empty() == true);
}

int main() { test1(); }
